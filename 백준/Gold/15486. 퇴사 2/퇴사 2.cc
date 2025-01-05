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
    int arr[N][2];
    int dp[1500001] = {0};
    
    for(int i=0; i<N; i++){
        cin >> arr[i][0] >> arr[i][1];
    }

    for(int i=N-1; i>-1; i--){
        if(i+arr[i][0] > N){
            dp[i] = dp[i+1];
        }
        else{
            dp[i] = max(dp[i+1], dp[i+arr[i][0]] + arr[i][1]);
        }
    }

    cout << dp[0] << '\n';

    return 0;
}   