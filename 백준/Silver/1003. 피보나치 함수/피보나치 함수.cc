#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    // freopen("input.txt", "r", stdin);

    ios::sync_with_stdio(false);
    cin.tie(0);

    int T, N;
    cin >> T;

    vector<vector<int>> dp(41, vector<int>(2, 0));

    dp[0][0] = 1;
    dp[1][1] = 1;

    for(int i=2; i<=40; i++){
        dp[i][0] = dp[i-1][0] + dp[i-2][0];
        dp[i][1] = dp[i-1][1] + dp[i-2][1];
    }

    while(T--){
        cin >> N;
        cout << dp[N][0] << ' ' << dp[N][1] << '\n';
    }

    return 0;
}