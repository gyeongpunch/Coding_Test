#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    // freopen("input.txt", "r", stdin);

    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    long long dp[91] = {0};

    dp[1] = 1;
    dp[2] = 1;

    for(int i=3; i<=N; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    cout << dp[N] << '\n';

    return 0;
}