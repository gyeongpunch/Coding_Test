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

const int MX = 15;

int N, L, R, X;
int arr[MX];
int result;
vector<int> path;
int nowSum = 0;

void dfs(int prev){
    if(path.size() > 1 && L<=nowSum && nowSum<=R && path[path.size()-1]-path[0] >= X){
        result++;
    }

    if(prev == N-1) return;

    for(int i=prev+1; i<N; i++){
        path.push_back(arr[i]);
        nowSum += arr[i];

        dfs(i);

        path.pop_back();
        nowSum -= arr[i];
    }
}

int main(void){
    fastio;
    
    cin >> N >> L >> R >> X;
    for(int i=0; i<N; i++) cin >> arr[i];

    sort(arr, arr+N);

    dfs(-1);

    cout << result << '\n';

    return 0;
}