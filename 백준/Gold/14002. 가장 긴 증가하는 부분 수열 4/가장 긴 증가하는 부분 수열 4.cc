#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int main(void){
    // freopen("input.txt", "r", stdin);

    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    int arr[1000];
    int dp[1000] = {0};
    fill(dp, dp+N, 1);
    deque<int> result;
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
    cout << mx << endl;
    int target = mx;
    for(int i=N-1; i>-1; i--){
        if(target == dp[i]){
            result.push_front(arr[i]);
            target--;
        }
    }

    for(int i=0; i<mx; i++){
        cout << result[i] << ' ';
    }
    cout << endl;

    return 0;
}   