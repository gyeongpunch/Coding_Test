#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MX = 200;

int N;
long long dp[MX+1];
long long result;

void solution(){
	for(int i=1; i<=N; i++) dp[i] = i;

	for(int i=1; i<=N; i++){
		dp[i] = i;
		for(int j=1; j<=i-3; j++){
			dp[i] = max(dp[i], dp[j] * (i-j-1));
		}
		// cout << dp[i] << ' ';
	}
	result = dp[N];
}

int main() {
	// 코드 작성
	cin >> N;
	solution();
	cout << result << '\n';
	return 0;
}