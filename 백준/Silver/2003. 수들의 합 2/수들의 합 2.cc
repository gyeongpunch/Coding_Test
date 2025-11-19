#include <iostream>
using namespace std;

const int MX = 10001;

int N, M;
int arr[MX];
int prefix_sum[MX];
int result;

void input(){
	cin >> N >> M; 
	for(int i=0; i<N; i++){
		cin >> arr[i];
	}
}

void solution(){
	for(int i=1; i<=N; i++){
		prefix_sum[i] = prefix_sum[i-1] + arr[i-1];
		// cout << prefix_sum[i] << ' ';
	}

	for(int i=0; i<N; i++){
		for(int j=i+1; j<=N; j++){
			int sm = prefix_sum[j] - prefix_sum[i];

			if(sm == M) result++;
		}
	}

	cout << result << '\n';
}

int main() {
	input();

	solution();

	return 0;
}