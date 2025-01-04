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
    int dp[100000];
    int mx;
    for(int i=0; i<N; i++){
        cin >> dp[i];
        if(i==0){
            mx = dp[0];
        }
        if(i>0){
            dp[i] = max(dp[i], dp[i-1]+dp[i]);
            mx = max(mx, dp[i]);
        }
    }

    cout << mx << '\n';

    return 0;
}