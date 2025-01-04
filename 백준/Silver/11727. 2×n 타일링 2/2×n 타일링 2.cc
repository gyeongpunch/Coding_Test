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
    int dp[1001] = {0};

    dp[1] = 1;
    dp[2] = 3;

    for(int i=3; i<=N; i++){
        dp[i] = (dp[i-2]*2 + dp[i-1]) % 10007;
    }

    cout << dp[N] << '\n';

    return 0;
}