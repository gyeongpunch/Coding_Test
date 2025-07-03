#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <cstring>

using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(nullptr);

struct Edge{
    int x, c;
};

const int MX = 100001;

int N, M;
vector<Edge> adj[MX];
int visited[MX];
int s, e;
int l=1, r=0;
int result;

bool bfs(int mid){
    queue<int> q;
    memset(visited, 0, sizeof(visited));
    q.push(s);
    visited[s] = 1;

    while(!q.empty()){
        int now = q.front(); q.pop();

        if(now == e) return true;
        
        for(const Edge &nxt : adj[now]){
            if(visited[nxt.x] == 1) continue;
            if(nxt.c < mid) continue;

            q.push(nxt.x);
            visited[nxt.x] = 1;
        }

    }
    return false;
}

void solution(){
    while(l <= r){
        int mid = (l + r) / 2;

        bool isAvail = bfs(mid);

        if(isAvail){
            l = mid + 1;
            result = max(result, mid);
        }
        else{
            r = mid - 1;
        }
    }
}

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    cin >> N >> M;
    int a, b, c;
    for(int i=0; i<M; i++){
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
        r = max(r, c);
    }
    cin >> s >> e;

    solution();

    cout << result << '\n';

    return 0;
}