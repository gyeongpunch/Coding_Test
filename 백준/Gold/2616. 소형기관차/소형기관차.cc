#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <cstring>

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(nullptr);

using namespace std;

const int MAX_N = 50000;

int N, M;
int arr[MAX_N];
int sum[MAX_N + 1];
int prevMax[MAX_N + 1];
int dp[3][MAX_N + 1];

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> arr[i];
        sum[i+1] = sum[i] + arr[i];
    }
    cin >> M;

    for(int i=0; i<3; i++){
        if(i == 0){
            for(int j = i*M + M; j <= N - (3-i - 1)*M; j++){
                dp[i][j] = max(sum[j] - sum[j-M], dp[i][j - 1]);
            }
        }
        else{
            for(int j = i*M + M; j <= N - (3-i - 1) * M; j++){
                dp[i][j] = max(dp[i-1][j-M] + sum[j] - sum[j-M], dp[i][j - 1]);
            }
        }
    }

    // for(int i=0; i<3; i++){
    //     for(int j=0; j<=N; j++){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    cout << dp[2][N] << '\n';

    return 0;
}