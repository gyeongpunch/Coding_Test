#include <iostream>
#include <climits>
#include <cstring>
#include <algorithm>
using namespace std;

const int MX = 100005;

int N, result;
int arr[MX][3], dp[MX][3];

void init(){
	memset(dp, 0, sizeof(dp));
}

void input(){
	for(int i=0; i<N; i++){
		for(int j=0; j<3; j++){
			cin >> arr[i][j];
		}
	}
}

void solution(){
	dp[0][0] = INT_MAX;
	dp[0][1] = arr[0][1];
	dp[0][2] = arr[0][1] + arr[0][2];

	for(int i=1; i<N; i++){
		dp[i][0] = arr[i][0] + min(dp[i-1][0], dp[i-1][1]);
		dp[i][1] = arr[i][1] + min({dp[i-1][0], dp[i-1][1], dp[i-1][2], dp[i][0]});
		dp[i][2] = arr[i][2] + min({dp[i-1][1], dp[i-1][2], dp[i][1]});
	}
	result = dp[N-1][1];
}

int main() {
	for(int testCase=1; ; testCase++){
		cin >> N;
		if(N == 0) break;
		init();

		input();

		solution();

		cout << testCase << ". " << result << '\n';
	}
	return 0;
}