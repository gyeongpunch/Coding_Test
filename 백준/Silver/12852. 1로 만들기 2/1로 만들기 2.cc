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

    vector<int> dp(N+1, 0);

    for(int i=2; i<=N; i++){
        dp[i] = dp[i-1] + 1;
        if(i%3==0){
            dp[i] = min(dp[i], dp[i/3] + 1);
        }
        if(i%2==0){
            dp[i] = min(dp[i], dp[i/2] + 1);
        }
    }
    int result = dp[N];
    cout << result << '\n' << N << ' ';

    int index=N;
    while(index>1){
        if(index%3==0 && dp[index/3]==result-1){
            index /= 3;
            cout << index << ' ';
            
        }
        else if(index%2==0 && dp[index/2]==result-1){
            index /= 2;
            cout << index << ' ';
        }
        else if(dp[index-1]==result-1){
            index--;
            cout << index << ' ';
        }
        result--;
    }

    cout << '\n';

    return 0;
}