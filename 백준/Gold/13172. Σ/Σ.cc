#include <iostream>
using namespace std;
typedef long long ll;

const int MOD = 1000000007;

int M;
ll result;

ll power(ll base, ll exp){
	ll ret = 1;
	base %= MOD;

	while(exp > 0){
		if(exp % 2 == 1){
			ret = (ret * base) % MOD;
		}
		base = (base * base) % MOD;
		exp /= 2;
	}
	return ret;
}

int main() {
	cin >> M;

	ll n, s;
	for(int i=0; i<M; i++){
		cin >> n >> s;
		result += (s * power(n, MOD-2)) % MOD;
		result %= MOD;
	}

	cout << result << '\n';

	return 0;
}