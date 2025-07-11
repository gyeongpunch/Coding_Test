#include <iostream>
#include <queue>
#include <cstring>
#include <climits>
#include <queue>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

const int MX = 400001;

int N, K;
int visited[MX];
int cnt[MX];
int result = 0;

void bfs(){
    queue<int> q;
    q.push(N);
    memset(visited, -1, sizeof(visited));
    visited[N] = 0;
    cnt[N] = 1;

    if(N == K){
        return;
    }

    while(!q.empty()){
        int now = q.front(); q.pop();

        int nxt[3] = {now-1, now+1, now*2};

        for(int i=0; i<3; i++){
            int nx = nxt[i];

            if(nx < 0 || nx >= MX) continue;
            
            if(visited[nx] == -1){
                q.push(nx);
                visited[nx] = visited[now] + 1;
                cnt[nx] = cnt[now];
            }
            else if (visited[nx] == visited[now] + 1){
                cnt[nx] += cnt[now];
            }
        }
    }
}

int main(void) {
    fastio;

    cin >> N >> K;

    bfs();

    cout << visited[K] << '\n' << cnt[K] << '\n';
    
    return 0; 
}
