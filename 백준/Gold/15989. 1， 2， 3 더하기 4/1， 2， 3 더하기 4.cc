#include <iostream>
using namespace std;

const int MX = 10001;

int dp[MX];

void get_result(){
	int nums[3] = {1, 2, 3};

	dp[0] = 1;
	for(int i=0; i<3; i++){
		int n = nums[i];
		for(int j=1; j<MX; j++){
			if(j-n < 0) continue;
			
			dp[j] += dp[j-n];
		}
	}
}

int main() {
	// 코드 작성

	get_result();

	int T;
	cin >> T;
	int n;
	for(int t=0; t<T; t++){
		cin >> n;
		cout << dp[n] << '\n';
	}

	return 0;
}

/*
1
2, 1+1
3, 1+1+1, 1+2


for(int i=0; i<N; i++){

}

1 2 3 4 5 6 7 8 9 10
1 1 1

순서가 다른 것은 같은 것으로 친다.
*/