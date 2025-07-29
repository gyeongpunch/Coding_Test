#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

struct Point{
	int x, y;
};

const int MX = 20;

int N, M;
int arr[MX][MX];
int visited[MX][MX];
vector<Point> Empty;
vector<Point> path;
int result;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool bound_check(int x, int y){
	return 0<=x && x<N && 0<=y && y<M;
}

int bfs(int x, int y){
	queue<Point> q;
	visited[x][y] = 1;
	q.push({x, y});
	int sz = 1;

	bool flag = true;
	while(!q.empty()){
		Point now = q.front(); q.pop();

		for(int i=0; i<4; i++){
			int nx = now.x+dx[i];
			int ny = now.y+dy[i];

			if(!bound_check(nx, ny)) continue;
			if(visited[nx][ny] == 1) continue;
			if(arr[nx][ny] == 1) continue;
			else if(arr[nx][ny] == 0) {
				flag = false;
				continue;
			}
			else if(arr[nx][ny] == 2){
				q.push({nx, ny});
				visited[nx][ny] = 1;
				sz++;
			}
		}
	}
	return flag ? sz : 0;
}

void simulation(){
	arr[path[0].x][path[0].y] = 1;
	arr[path[1].x][path[1].y] = 1;

	memset(visited, 0, sizeof(visited));

	int subResult = 0;

	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(arr[i][j]==2 && visited[i][j]==0){
				int cnt = bfs(i, j);

				if(cnt > 0){
					subResult += cnt;
				}
			}
		}
	}
	result = max(result, subResult);

	arr[path[0].x][path[0].y] = 0;
	arr[path[1].x][path[1].y] = 0;
}

void dfs(int depth, int prev){
	if(depth == 2){
		simulation();
		return;
	}
	for(int i=prev+1; i<Empty.size(); i++){
		path.push_back(Empty[i]);

		dfs(depth + 1, i);

		path.pop_back();
	}
}

int main() {
	// 코드 작성
	cin >> N >> M;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cin >> arr[i][j];

			if(arr[i][j] == 0){
				Empty.push_back({i, j});
			}
		}
	}
	
	dfs(0, -1);

	// for(const Point p : Empty){
	// 	cout << p.x << ' ' << p.y << "\n\n";
	// }

	cout << result << '\n';

	return 0;
}

/*
1은 나의 돌, 2는 상대의 돌
*/