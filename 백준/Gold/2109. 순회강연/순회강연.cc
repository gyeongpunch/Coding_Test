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

struct Info{
    int p, d;
};

const int MX = 100001;

int N;
Info arr[MX];
int visited[MX];
int parent[MX];

bool cmp(Info a, Info b){
    if(a.p==b.p) return a.d > b.p;
    return a.p > b.p;
}

int find(int x){
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void Union(int a, int b){
    int rootA = find(a);
    int rootB = find(b);

    if(rootA != rootB){
        parent[rootB] = rootA;
    }
}

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    cin >> N;
    int p, d;
    for(int i=0; i<N; i++){
        cin >> arr[i].p >> arr[i].d;
    }

    sort(arr, arr+N, cmp);
    for(int i=1; i<=MX; i++){
        parent[i] = i;
    }
    
    int result = 0;
    for(int i=0; i<N; i++){
        int myP = find(arr[i].d);
        if(visited[myP] == 0 && myP!=0){
            visited[myP] = 1;
            result += arr[i].p;
            parent[myP] = parent[myP] - 1;
        }
    }

    cout << result << '\n';

    return 0;
}