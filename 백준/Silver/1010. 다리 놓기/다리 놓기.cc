#include <iostream>
using namespace std;

const int MX = 31;

int T, N, M;
int dp[MX][MX];

int main() {
	for(int i=1; i<MX; i++){
		dp[i][1] = i;
		dp[i][i] = 1;
	}

	for(int i=2; i<MX; i++){
		for(int j=2; j<i; j++){
			dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
		}
	}
	
	cin >> T;
	for(int i=0; i<T; i++){
		cin >> N >> M;
		cout << dp[M][N] << '\n';
	}
	return 0;
}