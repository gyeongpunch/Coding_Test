#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <queue>
#include <cstring>

using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(nullptr);

const int MX=3001;

int N;
vector<int> adj[MX];
int visited[MX];
int isInCycle[MX];
int dist[MX];

bool foundCycle = false;
int cycleStart = -1;
queue<int> q;

bool dfs(int now, int prev){
    visited[now] = 1;
    for(int next : adj[now]){
        if(next == prev) continue;

        if(visited[next]==0){
            if(dfs(next, now)){
                if(foundCycle) return true;
                isInCycle[now] = 1;
                if(now==cycleStart) foundCycle = true;
                return !foundCycle;
            }
        }
        else if(!foundCycle){
            cycleStart = next;
            isInCycle[now] = 1;
            return true;
        }
    }
    return false;
}

void bfs(){
    while(!q.empty()){
        int now = q.front(); q.pop();

        for(int next : adj[now]){
            if(dist[next]!=-1) continue;

            dist[next] = dist[now] + 1;
            q.push(next);
        }
    }
}

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    cin >> N;
    int a, b;
    for(int i=0; i<N; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, -1);

    fill(dist, dist+N+1, -1);

    for(int i=1; i<=N; i++){
        if(isInCycle[i]==1){
            q.push(i);
            dist[i] = 0;
        }
    }

    bfs();

    for(int i=1; i<=N; i++){
        cout << dist[i] << ' ';
    }
    cout << '\n';

    return 0;
}