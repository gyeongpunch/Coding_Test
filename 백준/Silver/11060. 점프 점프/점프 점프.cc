#include <iostream>
#include <climits>
using namespace std;

const int MX = 1000;

int N;
int arr[MX];
int dp[MX];

int main() {
	// 코드 작성

	cin >> N;
	for(int i=0; i<N; i++) cin >> arr[i];

	fill(dp, dp+N, INT_MAX);

	dp[0] = 0;
	for(int i=0; i<N; i++){
		if(dp[i] == INT_MAX) continue;

		for(int j=1; j<=arr[i]; j++){
			if(i + j >= N) break;
			dp[i+j] = min(dp[i+j], dp[i] + 1);
		}
	}

	int result = dp[N-1] != INT_MAX ? dp[N-1] : -1;

	cout << result << '\n';

	return 0;
}

/*
1*N 미로
각 칸에는 정수. 재환이는 Ai이하만큼 오른쪽으로 떨어진 칸으로 점프 가능
가장 오른쪽으로 가려고할 때 최소 점프 횟수

10
1 2 0 1 3 2 1 5 4 2
0 1 2 2 3 4 4 4 5 5
*/