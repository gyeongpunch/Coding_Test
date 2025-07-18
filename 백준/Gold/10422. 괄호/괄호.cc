#include <iostream>
using namespace std;

typedef long long ll;

const int MOD = 1000000007;
const int MX = 2600;

ll dp[MX];

ll get_value(int num){
	ll ret = 0;
	for(int i=0; i<num; i++){
		ret = (ret + dp[i]*dp[num-1-i]) % MOD;
	}
	return ret;
}

void solution(){
	dp[0] = 1;
	dp[1] = 1;
	
	for(int i=2; i<MX; i++){
		dp[i] = get_value(i);
	}
}

int main() {

	solution();
	int T, n;
	cin >> T;
	for(int t=0; t<T; t++){
		cin >> n;
		if(n % 2 == 0) cout << dp[n/2] << '\n';
		else cout << 0 << '\n';
	}


	return 0;
}