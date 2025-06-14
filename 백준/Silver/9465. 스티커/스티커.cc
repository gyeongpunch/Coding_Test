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
int arr[2][MX];
int dp[2][MX+2];

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    int T;
    cin >> T;
    for(int t=0; t<T; t++){
        cin >> N;
        for(int i=0; i<2; i++){
            for(int j=0; j<N; j++){
                cin >> arr[i][j];
            }
        }

        int result = -1e9;
        for(int i=0; i<N; i++){
            for(int j=0; j<2; j++){
                if(j == 0){
                    dp[0][i+2] = max({dp[1][i+1], dp[1][i], dp[0][i]}) + arr[j][i];
                }
                else{
                    dp[1][i+2] = max({dp[0][i], dp[0][i+1], dp[1][i]}) + arr[j][i];
                }

                result = max(result, dp[j][i+2]);
            }
        }
        // for(int i=0; i<2; i++){
        //     for(int j=0; j<N+2; j++){
        //         cout << dp[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }

        cout << result << '\n';
    }

    return 0;
}