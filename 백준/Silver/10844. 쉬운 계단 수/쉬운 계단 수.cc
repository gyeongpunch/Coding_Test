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
    long long dp[101][10] = {0};

    for(int i=0; i<10; i++){
        if(i==0){
            dp[0][0] = 0;
        }
        else{
            dp[0][i] = 1;
        }
    }

    for(int i=1; i<N; i++){
        for(int j=0; j<10; j++){
            if(j==0){
                dp[i][0] = dp[i-1][1];
            }
            else if(j==9){
                dp[i][9] = dp[i-1][8];
            }
            else{
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % 1000000000;
            }
        }
    }

    long long sm = 0;
    for(int i=0; i<10; i++){
        sm += dp[N-1][i];
    }

    cout << sm % 1000000000 << endl;

    return 0;
}   