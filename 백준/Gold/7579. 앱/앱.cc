#include <iostream>
#include <algorithm>
using namespace std;

struct Info{
	int m, c;
};

const int MX = 10001;
const int MXN = 101;

int N, M;
Info arr[MX];
int sum_cost;
int result;
int dp[MX];

void input(){
	cin >> N >> M;
	for(int i=0; i<N; i++){
		cin >> arr[i].m;
	}
	for(int i=0; i<N; i++){
		cin >> arr[i].c;
		sum_cost += arr[i].c;
	}
}

void solution(){
	for(int i=0; i<N; i++){
		for(int j=sum_cost; j>=arr[i].c; j--){
			dp[j] = max(dp[j], dp[j-arr[i].c] + arr[i].m);
		}
	}
	for(int i=0; i<=sum_cost; i++){
		if(dp[i] >= M){
			result = i;
			break;
		}
	}

	// for(int i=0; i<=sum_cost; i++){
	// 	cout << dp[i] << ' ';
	// }
	// cout << "\n\n\n";
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