#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>

using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

struct Ribbon {
	int value, idx;
};

const int MX_N = 100;
const int MX_K = 10000;

int arr[MX_K];
int dp[MX_N + 1][MX_K];
int N, K;

Ribbon big1 = { -1, -1 }, big2 = { -1, -1 };

int main(void) {
	fastio;

	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < K; j++) {
			if (big1.value <= dp[i-1][j]) {
				big2.value = big1.value;
				big2.idx = big1.idx;

				big1.value = dp[i - 1][j];
				big1.idx = j;
			}
			else if (big2.value < dp[i - 1][j]) {
				big2.value = dp[i - 1][j];
				big2.idx = j;
			}
		}

		for (int j = 0; j < K; j++) {
			cin >> arr[j];

			if (big1.idx == j) {
				dp[i][j] = big2.value + arr[j];
			}
			else {
				dp[i][j] = big1.value + arr[j];
			}
		}
		big1.value = big2.value = 0;
	}

	int mx = 0;
	for (int i = 0; i < K; i++) {
		mx = max(mx, dp[N][i]);
	}
	
	cout << mx << '\n';

	return 0;
}