#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

typedef long long ll;

struct Info{
	int x, y;
};

const int MX = 501;

int N;
Info arr[MX];
ll dp[MX][MX];
ll result;

void init(){
	for(int i=0; i<N; i++){
		for(int j=i; j<N; j++){
			if(i!=j) dp[i][j] = LLONG_MAX;
		}
	}
}

void solution(){
	for(int i=1; i<N; i++){
		for(int j=0; j<N-i; j++){
			int y = j + i;
			int x = j;
			for(int k=x; k<y; k++){
				ll cost = dp[x][k] + dp[k+1][y] + (ll)arr[x].x * arr[k].y * arr[y].y;
                dp[x][y] = min(dp[x][y], cost);
			}
			// cout << x << ' ' << y << ' ' << dp[x][y] << '\n';
		}
	}
	result = dp[0][N-1];
}

void print_dp(){
	cout << "=======================\n";
	for(int i=0; i<N; i++){
		for(int j=i; j<N; j++){
			cout << dp[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << "========================\n\n";
}

int main() {
	// 코드 작성
	cin >> N;
	for(int i=0; i<N; i++){
		cin >> arr[i].x >> arr[i].y;
	}

	init();

	solution();

	cout << result << '\n';

	// print_dp();

	return 0;
}