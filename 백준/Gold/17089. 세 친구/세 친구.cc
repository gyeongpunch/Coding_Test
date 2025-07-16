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
#include <climits>

using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(nullptr);

const int MX = 4001;

int N, M;
vector<int> adj[MX];
unordered_set<int> Set[MX];
int visited[MX];
vector<int> path;
int result = INT_MAX;

void dfs(int depth, int now){
    if(depth == 3){
        int sm = adj[path[0]].size()-2 + adj[path[1]].size()-2 + adj[path[2]].size()-2;
        result = min(result, sm);
        return;
    }

    for(const int &nxt : adj[now]){
        if(nxt <= now) continue;
        if(path.size() == 2 && Set[path[0]].find(nxt) == Set[path[0]].end()) continue;

        path.push_back(nxt);
        dfs(depth+1, nxt);
        path.pop_back();
    }

}

int main(void){
    fastio;
    
    cin >> N >> M;
    int a, b;
    for(int i=0; i<M; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        Set[a].insert(b);
        Set[b].insert(a);
    }

    for(int i=1; i<=N; i++){
        path.push_back(i);
        dfs(1, i);
        path.pop_back();
    }

    if(result == INT_MAX) result = -1;

    cout << result << '\n';

    return 0;
}