#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <cstring>

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(nullptr);

using namespace std;

#define MAX_N 50

vector<int> tree[MAX_N];
int listen[MAX_N];
int N;

void get_listen(int now){
    vector<int> v;

    for(int child : tree[now]){
        get_listen(child);
        v.push_back(listen[child]);
    }
    
    sort(v.begin(), v.end(), greater<int>());

    for(int i=0; i<tree[now].size(); i++){
        listen[now] = max(listen[now], v[i] + i + 1);
    }
}

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    cin >> N;

    int a;
    for(int i=0; i<N; i++){
        cin >> a;
        
        if(i == 0) continue;

        tree[a].push_back(i);
    }

    get_listen(0);

    cout << listen[0] << '\n';

    return 0;
}