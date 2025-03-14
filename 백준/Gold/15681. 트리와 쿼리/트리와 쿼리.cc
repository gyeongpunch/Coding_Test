#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <cstring>

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(nullptr);

using namespace std;

const int MAX_N = 100001;

int N, R, Q;
vector<int> tree[MAX_N];
vector<int> children[MAX_N];
int parents[MAX_N];
int subTreeSize[MAX_N];

void makeTree(int nowNode, int parent){
    for(int neighbor : tree[nowNode]){
        if(neighbor == parent) continue;

        children[nowNode].push_back(neighbor);
        parents[neighbor] = nowNode;
        makeTree(neighbor, nowNode);
    }
}

void getSubTreeSize(int subRoot){
    subTreeSize[subRoot] = 1;
    for(int child : children[subRoot]){
        getSubTreeSize(child);
        subTreeSize[subRoot] += subTreeSize[child];
    }
}

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    cin >> N >> R >> Q;

    int a, b;
    for(int i=0; i<N-1; i++){
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    makeTree(R, -1);

    for(int i=0; i<Q; i++){
        cin >> a;

        if(subTreeSize[a] == 0){
            getSubTreeSize(a);
        }
        cout << subTreeSize[a] << '\n';
    }
    

    return 0;
}