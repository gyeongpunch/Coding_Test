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
int dp[3][MX][3];
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

    for(int i=0; i<3; i++){
        dp[i][0][i] = arr[0][i];
        for(int j=1; j<N; j++){
            for(int k=0; k<3; k++){
                for(int l=0; l<3; l++){
                    if(k==l) continue;
                    if((dp[i][j][k]==0 || dp[i][j][k] > dp[i][j-1][l] + arr[j][k]) && dp[i][j-1][l] != 0){
                        dp[i][j][k] = dp[i][j-1][l] + arr[j][k];
                    }
                }
                if(j==N-1 && dp[i][j][k] < result && dp[i][j][k]!=0 && i!=k){
                    result = dp[i][j][k];
                }
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