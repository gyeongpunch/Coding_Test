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

    vector<vector<int>> arr(N, vector<int>(N, 0));
    vector<vector<int>> dp(N, vector<int>(N, 0));
    for(int i=0; i<N; i++){
        for(int j=0; j<3; j++){
            cin >> arr[i][j];
        }
    }
    dp = arr;

    for(int i=1; i<N; i++){
        dp[i][0] += min(dp[i-1][1], dp[i-1][2]);
        dp[i][1] += min(dp[i-1][0], dp[i-1][2]);
        dp[i][2] += min(dp[i-1][0], dp[i-1][1]);
    }

    int result = min(dp[N-1][0], min(dp[N-1][1], dp[N-1][2]));
    
    cout << result << endl;

    return 0;
}