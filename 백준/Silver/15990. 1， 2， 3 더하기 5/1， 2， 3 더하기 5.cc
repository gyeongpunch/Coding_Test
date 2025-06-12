#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <cstring>
#include <numeric>

using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(nullptr);

const int MX = 100000;
const int MOD = 1000000009;

int T, n;
long long dp[MX+1][4];

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    dp[1][1] = dp[2][2] = dp[3][3] = 1;

    for(int n=1; n<=MX; n++){
        for(int i=1; i<=min(n, 3); i++){
            for(int prevIdx=1; prevIdx<=3; prevIdx++){
                if(prevIdx == i) continue;
                dp[n][i] += (dp[n-i][prevIdx] % MOD);
            }
        }
        dp[n][0] = (dp[n][1]+dp[n][2]+dp[n][3]) % MOD;
    }
    
    cin >> T;
    for(int t=0; t<T; t++){
        cin >> n;
        cout << dp[n][0] << '\n';
    }

    return 0;
}