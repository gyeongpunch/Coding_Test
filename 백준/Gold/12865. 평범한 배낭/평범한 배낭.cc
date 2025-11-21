#include <iostream>
#include <algorithm>
using namespace std;

struct Info{
	int w, v;
};

const int MX = 101;
const int MXP = 100001;

int N, K;
Info arr[MX];
int dp[MXP];

void input(){
	cin >> N >> K;
	for(int i=0; i<N; i++){
		int w, v;
		cin >> arr[i].w >> arr[i].v;
	}
}

void solution(){
	for(int i=0; i<N; i++){
		Info now = arr[i];
		for(int j=K; j>=now.w; j--){
			dp[j] = max(dp[j], dp[j-now.w] + now.v);
		}
	}
}

void get_result(){
	cout << dp[K] << '\n';
}

int main() {
	input();

	solution();

	get_result();

	return 0;
}