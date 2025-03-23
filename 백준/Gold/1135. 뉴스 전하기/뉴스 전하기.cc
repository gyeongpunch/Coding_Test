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
int subTreeSize[MAX_N];
int height[MAX_N];
int N;

int get_listen(int now){
    vector<int> v;

    for(int child : tree[now]){
        v.push_back(get_listen(child));
    }

    sort(v.begin(), v.end(), greater<int>());

    int maxTime = 0;
    for (int i = 0; i < v.size(); i++) {
        maxTime = max(maxTime, v[i] + i + 1);
    }
    
    return maxTime;
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

    cout << get_listen(0) << '\n';

    return 0;
}