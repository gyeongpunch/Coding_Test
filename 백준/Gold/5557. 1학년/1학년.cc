#include <iostream>
using namespace std;
typedef long long ll;

const int MXN = 100;
const int MXD = 21;

int N;
int arr[MXN];
ll dp[MXN][MXD];

int main() {
	// 코드 작성
	cin >> N;
	for(int i=0; i<N; i++) cin >> arr[i];

	dp[0][arr[0]] = 1;
	
	for(int i=1; i<N-1; i++){
		for(int j=0; j<MXD; j++){
			if (dp[i - 1][j] > 0) {
                if (j + arr[i] <= 20) {
                    dp[i][j + arr[i]] += dp[i - 1][j];
                }

                if (j - arr[i] >= 0) {
                    dp[i][j - arr[i]] += dp[i - 1][j];
                }
            }
		}
	}

	ll result = dp[N-2][arr[N-1]];

	cout << result << '\n';

	return 0;
}