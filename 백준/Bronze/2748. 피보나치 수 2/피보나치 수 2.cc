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
    long long dp[N+1];
    dp[0] = 0;
    dp[1] = 1;

    for(int i=2; i<=N; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    cout << dp[N] << endl;

    return 0;
}   