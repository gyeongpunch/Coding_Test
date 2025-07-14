#include <iostream>
using namespace std;

const int MX = 50;
const int MXX = 1001;

int N, S, M;
int arr[MX];

// i번째 곡 순서에서 j볼륨으로 연주 가능
int dp[MX][MXX];

bool bound_check(int x){
	return 0<=x && x<=M;
}

int main() {

	cin >> N >> S >> M;
	for(int i=0; i<N; i++) cin >> arr[i];

	int now = S;
	for(int i=0; i<N; i++){
		if(i == 0){
			int d[2] = {now - arr[i], now + arr[i]};
			for(int j=0; j<2; j++){
				if(bound_check(d[j])){
					dp[i][d[j]] = 1;
				}
			}
			continue;
		}
		for(int j=0; j<=M; j++){
			if(dp[i-1][j] != 1) continue;

			int d[2] = {j-arr[i], j+arr[i]};

			for(int j=0; j<2; j++){
				if(bound_check(d[j])){
					dp[i][d[j]] = 1;
				}
			}
		}
	}


	int result = -1;
	for(int j=0; j<=M; j++){
		if(dp[N-1][j] == 1) result = j;
	}

	cout << result << '\n';

	return 0;
}

/*
N개의 곡 연주
매 곡마다 볼륨을 바꾸자
볼륨 리스트가 있다.
V에 적힌 수는 바꿀 수 있는 볼륨
0 미만, M 초과 불가능


시작 5

0에서
5-5, 5+5
0, 10 가능

1에서
0-3, 0+3, 10-3, 10+3
3, 7

2에서


*/