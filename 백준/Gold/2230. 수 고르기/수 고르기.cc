#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

const int MX = 100000;

int N, M;
int arr[MX];
int result = INT_MAX;

void solution(){
	int l = 0, r = 0;

	while(l <= r && r<N){
		int dist = arr[r] - arr[l];

		if(dist==M){
			result = M;
			return;
		}
		else if(dist > M){
			l++;
			result = min(result, dist);
		}
		else{
			r++;
		}
	}
}

int main() {
	cin >> N >> M;
	for(int i=0; i<N; i++){
		cin >> arr[i];
	}

	sort(arr, arr+N);

	solution();

	cout << result << '\n';
	
	return 0;
}