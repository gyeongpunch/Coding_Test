#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(nullptr);

struct Info{
    int total, now;
};

const int MX = 2000;

int S;
int result = 1e9;
int visited[MX][MX];

bool bound_check(int x){
    return 0<=x && x<MX;
}

void bfs(){
    queue<Info> q;
    memset(visited, -1, sizeof(visited));
    q.push({1, 0});
    visited[1][0] = 0;

    Info nowInfo, nxt;
    while(!q.empty()){
        nowInfo = q.front(); q.pop();

        if(visited[nowInfo.total][nowInfo.now] >= result) continue;

        if(nowInfo.total == S){
            result = min(result, visited[nowInfo.total][nowInfo.now]);
            continue;
        }

        for(int i=0; i<3; i++){
            if(i==0) nxt = {nowInfo.total, nowInfo.total};
            else if(i==1) nxt = {nowInfo.total + nowInfo.now, nowInfo.now};
            else if(i==2) nxt = {nowInfo.total - 1, nowInfo.now};

            if(!bound_check(nxt.total)) continue;
            if(visited[nxt.total][nxt.now] != -1) continue;

            q.push(nxt);
            visited[nxt.total][nxt.now] = visited[nowInfo.total][nowInfo.now] + 1;
        }

    }
}

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    cin >> S;

    bfs();

    cout << result << '\n';

    return 0;
}