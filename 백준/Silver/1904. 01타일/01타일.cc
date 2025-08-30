#include <iostream>
using namespace std;

const int MOD = 15746;

int N;
int a, b, c, result;

void solution(){
	if(N < 3){
		result = N;
		return;
	}
	a = 1;
	b = 2;
	for(int i=3; i<=N; i++){
		c = (a + b) % MOD;
		a = b;
		b = c;
	}

	result = c;
}

int main() {
	cin >> N;

	solution();

	cout << result << '\n';
	
	return 0;
}