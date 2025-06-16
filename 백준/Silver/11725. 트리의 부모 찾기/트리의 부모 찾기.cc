#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <cstring>

using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(nullptr);

const int MX = 100001;

int N;
vector<int> adj[MX];
int parent[MX];

void get_parent(int now, int prev){
    for(int nextNode : adj[now]){
        if(nextNode == prev) continue;

        parent[nextNode] = now;
        get_parent(nextNode, now);
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

    parent[1] = -1;

    get_parent(1, -1);

    for(int i=2; i<=N; i++){
        cout << parent[i] << '\n';
    }

    return 0;
}