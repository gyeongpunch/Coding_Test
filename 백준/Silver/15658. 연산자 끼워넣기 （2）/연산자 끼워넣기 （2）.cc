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

const int MX = 11;

int N;
int arr[MX];
int op[4];
vector<int> path;
int mx=-1e9, mn=1e9;

void calc(){
    int now = arr[0];

    for(int i=0; i<N-1; i++){
        if(path[i] == 0) now += arr[i+1];
        else if(path[i] == 1) now -= arr[i+1];
        else if(path[i] == 2) now *= arr[i+1];
        else if(path[i] == 3) now /= arr[i+1];
    }

    mx = max(mx, now);
    mn = min(mn, now);
}

void dfs(int depth){
    if(depth == N-1){
        calc();
        return;
    }

    for(int i=0; i<4; i++){
        if(op[i] <= 0) continue;

        path.push_back(i);
        op[i]--;

        dfs(depth+1);

        path.pop_back();
        op[i]++;
    }
}

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    for(int i=0; i<4; i++){
        cin >> op[i];
    }

    dfs(0);

    cout << mx << '\n' << mn << '\n';

    return 0;
}