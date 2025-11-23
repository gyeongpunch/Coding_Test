#include <iostream>
using namespace std;

struct Info{
	int hp, jy;
};

const int MX = 21;
const int MXH = 100;

int N;
Info arr[MX];
int dp[MXH+1];
int result;

void input(){
	cin >> N;
	for(int i=0; i<N; i++){
		cin >> arr[i].hp;
	}
	for(int i=0; i<N; i++){
		cin >> arr[i].jy;
	}
}

void solution(){
	for(int i=0; i<N; i++){
		for(int j=MXH-1; j>=arr[i].hp; j--){
			dp[j] = max(dp[j], dp[j-arr[i].hp] + arr[i].jy);
			result = max(result, dp[j]);
		}

		// for(int j=0; j<=100; j++){
		// 	cout << dp[j] << ' ';
		// }
		// cout << "\n\n\n";
	}
}

void get_result(){
	cout << result << '\n';
}

int main() {
	input();

	solution();

	get_result();

	return 0;
}