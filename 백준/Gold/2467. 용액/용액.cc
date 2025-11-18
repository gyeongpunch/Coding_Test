#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

const int MX = 100000;

struct Result{
	int n1, n2;
	int sum;
};

int N;
int arr[MX];

void solution(){
	Result Res;
	Res.sum = INT_MAX;

	for(int i=0; i<N-1; i++){
		int l = i+1, r=N-1;

		while(l<=r){
			int mid = (l+r)/2;

			if(abs(arr[i] + arr[mid]) < abs(Res.sum)){
				Res.sum = abs(arr[i] + arr[mid]);
				Res.n1 = arr[i];
				Res.n2 = arr[mid];
			}
			
			if(arr[i] + arr[mid] > 0){
				r = mid - 1;
			}
			else{
				l = mid + 1;
			}
		}
	}
	cout << Res.n1 << ' ' << Res.n2 << '\n';
}

int main() {
	cin >> N;
	for(int i=0; i<N; i++){
		cin >> arr[i];
	}

	sort(arr, arr+N);

	solution();

	return 0;
}