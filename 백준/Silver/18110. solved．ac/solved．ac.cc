#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

const int MX = 300001;

int N;
int arr[MX];

void solution(){
	if(N==0){
		cout << 0 << '\n';
		return;
	}

	sort(arr, arr+N);

	int ft = (N*15+50)/100;
	int rest = N - ft*2;

	int sum = accumulate(arr+ft, arr+N-ft, 0);

	int result = (sum + rest/2) / rest;

	cout << result << '\n';
}
int main() {
	cin >> N;
	for(int i=0; i<N; i++){
		cin >> arr[i];
	}
	
	solution();

	return 0;
}