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
    int node, length;
};

const int MX = 10001;

int N;
vector<Edge> adj[MX];
int visited[MX];
int result;

int bfs(int start){
    memset(visited, -1, sizeof(visited));
    queue<int> q;
    q.push(start);
    visited[start] = 0;

    int maxNode=0;

    while(!q.empty()){
        int now = q.front(); q.pop();

        if(visited[now] > visited[maxNode]){
            maxNode = now;
        }

        for(Edge edge : adj[now]){
            if(visited[edge.node] != -1) continue;

            q.push(edge.node);
            visited[edge.node] = visited[now] + edge.length;
        }
    }

    return maxNode;
}


int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    cin >> N;
    int a, b, c;
    for(int i=0; i<N-1; i++){
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    int left = bfs(1);
    int right = bfs(left);

    cout << visited[right] << '\n';

    return 0;
}