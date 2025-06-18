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

const int MX = 100001;

int N;
vector<int> adj[MX];
int visited[MX];
int order[MX];
int result, idx;

bool dfs(int now){
    visited[now] = 1;
    unordered_set<int> Set;
    for(int c : adj[now]){
        if(visited[c] == 1) continue;
        Set.insert(c);
    }

    for(int i=0; i<Set.size(); i++){
        int nxt = order[++idx];
        if(Set.count(nxt) == 0) return false;
        if(!dfs(nxt)) return false;
    }

    return true;
}

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    cin >> N;
    int a, b;
    for(int i=0; i<N-1; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=0; i<N; i++){
        cin >> order[i];
    }

    if(dfs(1)){
        result = 1;
    }

    cout << result << '\n';

    return 0;
}