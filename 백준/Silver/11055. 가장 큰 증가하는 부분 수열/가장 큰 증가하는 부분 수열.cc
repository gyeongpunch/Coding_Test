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
    int dp[1000];
    int mx = 0;
    for(int i=0; i<N; i++){
        int num;
        cin >> num;
        dp[i] = num;
        for(int j=0; j<i; j++){
            if(dp[i] > dp[j]){
                dp[i] = max(dp[i], dp[j]+num);
            }
        }
        mx = max(mx, dp[i]);
    }

    cout << mx << '\n';

    return 0;
}