#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <cstring>

using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(nullptr);

const int MX = 1000;
int N;
int arr[MX];
int dp[MX+1];

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }

    fill(dp+1, dp+N+1, 1e9);

    for(int idx=1; idx<=N; idx++){
        for(int i=1; i<=min(N, idx); i++){
            dp[idx] = min(dp[idx], dp[idx-i] + arr[i-1]);
        }
    }

    cout << dp[N] << '\n';

    return 0;
}