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

struct Node{
    int left, right;
};

struct Info{
    int min, max;
};

const int MX = 10001;
int N;
Node adj[MX];
int columns[MX];
int col = 0;
Info arr[MX];
int parent[MX];

void dfs(int node, int lv){
    if(node==-1) return;

    dfs(adj[node].left, lv + 1);
    
    columns[node] = ++col;

    arr[lv].min = min(arr[lv].min, columns[node]);
    arr[lv].max = max(arr[lv].max, columns[node]);

    dfs(adj[node].right, lv + 1);
}

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    cin >> N;
    int p, l, r;
    for(int i=1; i<=N; i++){
        cin >> p >> l >> r;
        adj[p].left = l;
        adj[p].right = r;

        if(l!=-1) parent[l] = p;
        if(r!=-1) parent[r] = p;

        arr[i].min = N+1;
        arr[i].max = 0;
    }

    int root;
    for(int i=1; i<=N; i++){
        if(parent[i] == 0) {
            root = i;
            break;
        }
    }

    dfs(root, 1);

    // for(int i=1; i<=N; i++){
    //     cout << i << ' ' << level[i] << ' ' << columns[i] << '\n';
    // }

    // cout << '\n';

    int maxWidth=0, level = 0;

    for(int i=1; i<=N; i++){
        if(arr[i].min==N+1 && arr[i].max==0) break;

        if(arr[i].max - arr[i].min + 1 > maxWidth){
            level = i;
            maxWidth = arr[i].max - arr[i].min + 1;
        }

        // cout << i << ' ' << arr[i].min << ' ' << arr[i].max << '\n';
    }

    cout << level << ' ' << maxWidth << '\n';

    return 0;
}