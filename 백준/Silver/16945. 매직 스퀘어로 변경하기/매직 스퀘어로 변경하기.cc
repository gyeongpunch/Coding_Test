#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 3;

int arr[N][N];
int arrTmp[N][N];
int visited[N*N+1];
int tmp[8];
int result = 1e9;

bool isSame(){
	return tmp[0]==tmp[1] && tmp[1]==tmp[2] && tmp[2]==tmp[3] && tmp[3]==tmp[4] && tmp[4]==tmp[5] && tmp[5]==tmp[6] && tmp[6]==tmp[7];
}

void calc(){
	int now = 0;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			now += abs(arr[i][j] - arrTmp[i][j]);
		}
	}

	result = min(result, now);
}

void check(){
	memset(tmp, 0, sizeof(tmp));

	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			tmp[j+3] += arrTmp[i][j];
			tmp[i] += arrTmp[i][j];

			if(i==j) tmp[6] += arrTmp[i][j];
			if(N-i-1==j) tmp[7] += arrTmp[i][j];
		}
	}

	if(isSame()){
		calc();
	}
}

void dfs(int depth){
	if(depth == N*N){
		check();
		return;
	}

	int i = depth / 3;
	int j = depth % 3;

	for(int n=1; n<=9; n++){
		if(visited[n] == 1) continue;

		arrTmp[i][j] = n;
		visited[n] = 1;
		dfs(depth + 1);

		visited[n] = 0;
		arrTmp[i][j] = 0;
	}
}

int main() {
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cin >> arr[i][j];
		}
	}

	check();

	dfs(0);

	cout << result << '\n';

	return 0;
}
