#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <cstring>

using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(nullptr);

const int MX=1000;

int N;
int arr[MX][3];
int dp[MX][3];
int result = 1e9;

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<3; j++){
            cin >> arr[i][j];
        }
    }

    for(int first=0; first<3; first++){
        for(int i=0; i<3; i++){
            dp[0][i] = i==first ? arr[0][i] : 1e9;
        }

        for(int i=1; i<N; i++){
            dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + arr[i][0];
            dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + arr[i][1];
            dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + arr[i][2];
        }

        for(int last=0; last<3; last++){
            if(result > dp[N-1][last] && first!=last){
                result = dp[N-1][last];
            }
        }
    }

    // for(int i=0; i<3; i++){
    //     for(int j=0; j<N; j++){
    //         for(int k=0; k<3; k++){
    //             cout << dp[i][j][k] << ' ';
    //         }
    //         cout << '\n';
    //     }
    //     cout << '\n';
    // }

    cout << result << '\n';

    return 0;
}