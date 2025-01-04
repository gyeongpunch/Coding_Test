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
        for(int j=0; j<=i; j++){
            cin >> arr[i][j];
        }
    }
    
    dp[0][0] = arr[0][0];

    for(int i=1; i<N; i++){
        for(int j=0; j<=i; j++){
            if(j==0){
                dp[i][j] = arr[i][j] + dp[i-1][j];
            }
            else if(j==i){
                dp[i][j] = arr[i][j] + dp[i-1][j-1];
            }
            else{
                dp[i][j] = arr[i][j] + max(dp[i-1][j], dp[i-1][j-1]);
            }
        }
    }
    int result = *max_element(dp[N-1].begin(), dp[N-1].end());

    cout << result << endl;

    return 0;
}