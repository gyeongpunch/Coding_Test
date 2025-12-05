#include <iostream>
#include <algorithm>
using namespace std;

const int MX = 500;

int N;
int arr[MX][MX];
int visited[MX][MX];
int result;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool bound_check(int x, int y){
	return 0<=x && x<N && 0<=y && y<N;
}

void input(){
	cin >> N;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cin >> arr[i][j];
		}
	}
}

int dfs(int x, int y){
	int &now = visited[x][y];
	if(now != 0) return now;

	now = 1;

	for(int i=0; i<4; i++){
		int nx=x+dx[i];
		int ny=y+dy[i];

		if(!bound_check(nx, ny)) continue;
		if(arr[nx][ny] <= arr[x][y]) continue;

		now = max(now, 1 + dfs(nx, ny));
	}
	// visited[x][y] = max(visited[x][y], now);
	return now;
}

void get_result(){
	cout << result << '\n';

	// for(int i=0; i<N; i++){
	// 	for(int j=0; j<N; j++){
	// 		cout << visited[i][j] << ' ';
	// 	}
	// 	cout << "\n";
	// }
}

void solution(){
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){

			result = max(result, dfs(i, j));
		}
	}
}

int main() {
	input();

	solution();

	get_result();

	return 0;
}