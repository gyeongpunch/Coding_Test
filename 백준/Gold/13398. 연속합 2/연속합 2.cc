#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <cstring>

using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(nullptr);

const int MX = 100000;

int N;
int arr[MX];
int dp[MX][2];

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }

    int result = arr[0];
    dp[0][0] = arr[0];
    dp[0][1] = -1001;

    for(int i=1; i<N; i++){
        dp[i][0] = max(dp[i-1][0] + arr[i], arr[i]);
        dp[i][1] = max(dp[i-1][1] + arr[i], dp[i-1][0]);
        result = max({result, dp[i][0], dp[i][1]});
    }

    cout << result << '\n';

    return 0;
}