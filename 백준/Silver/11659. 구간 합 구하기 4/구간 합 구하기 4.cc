#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    // freopen("input.txt", "r", stdin);

    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    int start, end;
    cin >> N >> M;

    int dp[100001];
    dp[0] = 0;

    for(int i=1; i<=N; i++){
        cin >> dp[i];
        dp[i] += dp[i-1];
    }

    while(M--){
        cin >> start >> end;
        cout << dp[end]-dp[start-1] << '\n';
    }

    return 0;
}