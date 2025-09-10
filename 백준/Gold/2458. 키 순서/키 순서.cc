#include <iostream>
#include <vector>
using namespace std;

const int MX = 501;

int N, M;
int arr[MX][MX];

int main() {
	cin >> N >> M;
	int a, b;
	for(int i=0; i<M; i++){
		cin >> a >> b;
		arr[a][b] = 1;
	}

	for(int k=1; k<=N; k++){
		for(int i=1; i<=N; i++){
			for(int j=1; j<=N; j++){
				if(i == j) continue;
				if(arr[i][j] == 1) continue;
				if(arr[i][k]==1 && arr[k][j]==1){
					arr[i][j] = 1;
				}
			}
		}
	}

	// for(int i=1; i<=N; i++){
	// 	for(int j=1; j<=N; j++){
	// 		cout << arr[i][j] << ' ';
	// 	}
	// 	cout << '\n';
	// }

	int result = 0;
	for(int i=1; i<=N; i++){
		int cnt = 0;
		for(int j=1; j<=N; j++){
			if(i==j) continue;
			if(arr[i][j]==1 || arr[j][i]==1){
				cnt++;
			}
		}
		if(cnt==N-1){
			result++;
		}
	}

	cout << result << '\n';

	return 0;
}

/*
1부터 N번 학생
N명의 학생의 키는 모두 다르다.

자신의 키가 몇 번째인지 알 수 있는 학생 or not
자신의 키가 몇 번째인지 알 수 있는 학생의 수

합이 N-1되면 됨

*/