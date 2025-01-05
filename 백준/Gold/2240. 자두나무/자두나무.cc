#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    // freopen("input.txt", "r", stdin);

    ios::sync_with_stdio(false);
    cin.tie(0);

    int T, W;
    cin >> T >> W;

    int arr[T+1];
    int dp[1001][31] = {0};
    int mx=0;

    for(int i=1; i<=T; i++){
        cin >> arr[i];
        for(int j=0; j<=W; j++){
            dp[i][j] = dp[i-1][j];
            if(j>0){
                dp[i][j] = max(dp[i][j], dp[i-1][j-1]);
            }
            if(j%2 + 1 == arr[i]){
                mx = max(mx, ++dp[i][j]);
            }
        }
    }
    
    cout << mx << '\n';

    return 0;
}   