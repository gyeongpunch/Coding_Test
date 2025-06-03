#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <cstring>

using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(nullptr);

const int MX = 50000;

int N;
int dp[MX+1];

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    cin >> N;
    
    fill(dp, dp+MX+1, 1e9);
    dp[0] = 0;

    for(int i = 1; i <= N; i++){
        for(int k = 1; k*k <= i; k++){
            dp[i] = min(dp[i], dp[i - k*k] + 1);
        }
    }

    cout << dp[N] << "\n";

    return 0;
}