#include <iostream>
#include <algorithm>
using namespace std;

struct Point{
	int x, y;
};

const int MX = 15;

int N, M;
char arr[MX][MX];
int visited[MX][MX];
int result;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool bound_check(int x, int y){
	return 0<=x && x<N && 0<=y && y<M;
}

bool is_avail(int x, int y, int l){
	for(int i=0; i<4; i++){
		for(int j=0; j<=l; j++){
			int nx = x + dx[i] * j;
			int ny = y + dy[i] * j;

			if(!bound_check(nx, ny)) return false;
			if(arr[nx][ny] == '.') return false;
			if(visited[nx][ny] == 1) return false;
		}
	}
	return true;
}

void painting(int x, int y, int l){
	for(int i=0; i<4; i++){
		for(int j=0; j<=l; j++){
			int nx = x + dx[i] * j;
			int ny = y + dy[i] * j;

			visited[nx][ny] = 1;
		}
	}
}

void removing(int x, int y, int l){
	for(int i=0; i<4; i++){
		for(int j=0; j<=l; j++){
			int nx = x + dx[i] * j;
			int ny = y + dy[i] * j;

			visited[nx][ny] = 0;
		}
	}
}

void dfs(int length, int sz, int depth){
	if(depth == 2){
		result = max(result, sz);
		return;
	}

	for(int i=length; i>-1; i--){
		for(int x=0; x<N; x++){
			for(int y=0; y<M; y++){
				if(arr[x][y] == '.') continue;
				if(visited[x][y] == 1) continue;
				if(!is_avail(x, y, i)) continue;

				painting(x, y, i);

				dfs(i, sz * (4*i+1), depth + 1);

				removing(x, y, i);
			}
		}
	}

}

int main() {
	cin >> N >> M;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cin >> arr[i][j];
		}
	}

	dfs(min(N, M)/2, 1, 0);

	cout << result << '\n';

	return 0;
}