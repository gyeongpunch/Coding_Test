#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

struct Info{
	int x, y, sum;
};

const int MX = 100001;

int N;
int arr[MX];
Info result = {0, 0, INT_MAX};

void input(){
	cin >> N;
	for(int i=0; i<N; i++){
		cin >> arr[i];
	}
}

void solution(){
	sort(arr, arr+N);

	int l=0, r=N-1;

	while(l<r){
		int sum = arr[l] + arr[r];

		if(abs(sum) <= abs(result.sum)){
			result = {arr[l], arr[r], sum};
		}

		if(sum < 0){
			l++;
		}
		else{
			r--;
		}

	}
}

void get_result(){
	cout << result.x << ' ' << result.y << '\n';
}

int main() {
	input();

	solution();

	get_result();

	return 0;
}