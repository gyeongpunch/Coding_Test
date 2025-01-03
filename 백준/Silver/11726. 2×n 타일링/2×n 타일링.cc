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

    vector<int> dp(N, 0);
    dp[0] = 1;
    dp[1] = 2;

    for(int i=2; i<N; i++){
        dp[i] = (dp[i-1] + dp[i-2]) % 10007;
    }

    int result = dp[N-1];
    
    cout << result << endl;

    return 0;
}