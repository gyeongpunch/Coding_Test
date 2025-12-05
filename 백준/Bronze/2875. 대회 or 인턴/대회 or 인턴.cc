#include <iostream>
using namespace std;

int main() {
	int N, M, K;
	cin >> N >> M >> K;
	for(int i=0; i<K; i++){
		if(N >= M*2) N--;
		else M--;
	}

	int result = N >= M*2 ? M : N/2;

	cout << result << '\n';

	return 0;
}