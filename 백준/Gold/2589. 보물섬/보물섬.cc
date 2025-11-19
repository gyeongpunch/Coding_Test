#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct Point{
	int x, y;
};

const int MX = 50;

int N, M;
char arr[MX][MX];
int visited[MX][MX];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0,- 1};
int result;

bool bound_check(int x, int y){
	return 0<=x && x<N && 0<=y && y<M;
}

void input(){
	cin >> N >> M;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cin >> arr[i][j];
		}
	}
}

void bfs(int x, int y){
	queue<Point> q;
	q.push({x, y});
	memset(visited, -1, sizeof(visited));
	visited[x][y] = 0;
	
	while(!q.empty()){
		Point now = q.front(); q.pop();

		for(int i=0; i<4; i++){
			int nx = now.x + dx[i];
			int ny = now.y + dy[i];

			if(!bound_check(nx, ny)) continue;
			if(visited[nx][ny] != -1) continue;
			if(arr[nx][ny] == 'W') continue;

			q.push({nx, ny});
			visited[nx][ny] = visited[now.x][now.y] + 1;
			result = max(result, visited[nx][ny]);
		}
	}

}

void solution(){
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(arr[i][j] == 'L'){
				bfs(i, j);
			}
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