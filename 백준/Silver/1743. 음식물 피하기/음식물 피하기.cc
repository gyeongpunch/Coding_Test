#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct Point{
	int x, y;
}j;

const int MX = 100;

int N, M, K;
int arr[MX][MX];
int visited[MX][MX];
int result;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool bound_check(int x, int y){
	return 0<=x && x<N && 0<=y && y<M;
}

void input(){
	cin >> N >> M >> K;
	for(int i=0; i<K; i++){
		int x, y;
		cin >> x >> y;
		arr[x-1][y-1] = 1;
	}
}

int bfs(int x, int y){
	queue<Point> q;
	q.push({x, y});
	visited[x][y] = 1;
	int cnt = 0;

	while(!q.empty()){
		Point now = q.front(); q.pop();
		cnt++;

		for(int i=0; i<4; i++){
			int nx = now.x + dx[i];
			int ny = now.y + dy[i];

			if(!bound_check(nx, ny)) continue;
			if(visited[nx][ny] == 1) continue;
			if(arr[nx][ny] == 0) continue;

			q.push({nx, ny});
			visited[nx][ny] = 1;
		}
	}
	return cnt;
}

void solution(){
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(visited[i][j] == 1) continue;
			if(arr[i][j] == 0) continue;

			result = max(result, bfs(i, j));
		}
	}
}

void get_result(){
	cout << result << '\n';
}

int main() {
	input();

	solution();

	get_result();
	
	return 0;
}