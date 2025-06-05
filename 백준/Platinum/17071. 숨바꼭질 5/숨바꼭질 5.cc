#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <cstring>

using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(nullptr);

struct Info{
    int x, t;
};

const int MX = 500001;

int N, K;
int visited[MX][2];
int result = -1;

bool bound_check(int x){
    return 0<=x && x<MX;
}

void bfs(){
    queue<Info> q;
    q.push({N, 0});
    memset(visited, -1, sizeof(visited));
    visited[N][0] = 0;

    int x, s;
    while(!q.empty()){
        Info now = q.front(); q.pop();

        int bro = K + (now.t * (now.t+1))/2;

        if(bro >= MX) return;

        if(visited[bro][now.t%2] != -1){
            result = now.t;
            return;
        }

        int next[3] = {now.x-1, now.x+1, now.x*2};

        for(int nx : next){
            if(!bound_check(nx)) continue;
            if(visited[nx][(now.t+1)%2] != -1) continue;

            q.push({nx, now.t+1});
            visited[nx][(now.t+1)%2] = now.t + 1;
        }
    }
}

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    cin >> N >> K;

    bfs();

    cout << result << '\n';

    return 0;
}