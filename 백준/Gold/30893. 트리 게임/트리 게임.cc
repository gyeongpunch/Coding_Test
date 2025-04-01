#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(nullptr);
#define MAX_N 100001

struct Node{
    int n, who;
};

int N, S, E;
vector<int> tree[MAX_N];
int visited[MAX_N];

bool bfs() {
    queue<Node> q;
    q.push({S, 0});
    visited[S] = 1;
    
    while (!q.empty()) {
        Node now = q.front(); q.pop();
        
        if (now.n == E) return true;
        
        vector<int> next;
        for (int nxt : tree[now.n]) {
            if (visited[nxt] == 0)
                next.push_back(nxt);
        }
        int cnt = next.size();
        
        if (now.who == 1) {
            if (cnt > 1) continue;
            if (cnt == 1) {
                int nxt = next[0];
                visited[nxt] = 1;
                q.push({nxt, 0});
            }
        }
        else {
            for (int nxt : next) {
                visited[nxt] = 1;
                q.push({nxt, 1});
            }
        }
    }
    return false;
}

int main(void){
    fastio;

    // freopen("input.txt", "r", stdin);

    cin >> N >> S >> E;
    int a, b;
    for(int i = 0; i < N - 1; i++){
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    
    if(bfs())
        cout << "First";
    else
        cout << "Second";
    
    return 0;
}
