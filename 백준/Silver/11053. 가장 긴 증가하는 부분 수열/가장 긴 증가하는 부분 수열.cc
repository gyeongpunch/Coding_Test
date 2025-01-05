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
    int arr[N];
    int dp[1000];
    fill(dp, dp + N, 1);
    int mx=0;

    for(int i=0; i<N; i++){
        cin >> arr[i];
        for(int j=0; j<i; j++){
            if(arr[i] > arr[j]){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        mx = max(mx, dp[i]);
    }
    // for(int i=0; i<N; i++){
    //     cout << dp[i] << ' ';
    // }
    // cout << endl;

    cout << mx << '\n';

    return 0;
}