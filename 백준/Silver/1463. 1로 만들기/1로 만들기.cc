#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    int N;
    cin >> N;
    vector<int> dp(N+1, 0);

    for(int i=N-1; i>0; i--){
        dp[i] = dp[i+1] + 1;
        if(i*2<=N){
            dp[i] = min(dp[i], dp[i*2]+1);
        }
        if(i*3<=N){
            dp[i] = min(dp[i], dp[i*3]+1);
        }
    }

    cout << dp[1] << endl;

    return 0;
}