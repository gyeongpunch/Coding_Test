#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MXS = 15001;
const int MX = 31;

int N, G;
int arr[MX];
bool dp[MXS];
int sum_weight;

void input(){
	cin >> N;
	for(int i=0; i<N; i++){
		cin >> arr[i];
		sum_weight += arr[i];
	}
}

void solution(){
	dp[0] = true;

	for(int i=0; i<N; i++){
		vector<int> tmp;
		for(int j=sum_weight; j>=arr[i]; j--){
			if(dp[j-arr[i]]){
				dp[j] = true;
				tmp.push_back(abs(arr[i] - (j-arr[i])));
			}
		}
		for(const int &n : tmp){
			dp[n] = true;
		}

		// for(int j=0; j<=sum_weight; j++){
		// 	cout << dp[j] << ' ';
		// }
		// cout << '\n';
	}
}

void get_result(){
	cin >> G;
	for(int i=0; i<G; i++){
		int g;
		char r;
		cin >> g;
		if(g >= MXS) r = 'N';
		else r = dp[g] ? 'Y' : 'N';
		cout << r << ' ';
	}
}

int main() {
	input();

	solution();

	get_result();

	return 0;
}