#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    // freopen("input.txt", "r", stdin);

    ios::sync_with_stdio(false);
    cin.tie(0);

    long long T;
    cin >> T;
    long long dp[101] = {0};
    dp[1] = dp[2] = dp[3] = 1;
    dp[4] = dp[5] = 2;
    for(int i=6; i<=100; i++){
        dp[i] = dp[i-1] + dp[i-5];
    }
    while(T--){
        int N;
        cin >> N;
        cout << dp[N] << '\n';
    }

    // for(int i=1; i<20; i++){
    //     cout << dp[i] << ' ';
    // }
    // cout << endl;
    return 0;
}