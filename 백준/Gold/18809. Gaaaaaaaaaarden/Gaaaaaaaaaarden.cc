#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

struct Point{
	int x, y;
};

const int MX = 50;

int N, M, G, R;
int arr[MX][MX];
int visited[MX][MX];
int flower[MX][MX];
vector<Point> canLoc;
vector<Point> green;
vector<Point> red;
int result;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool bound_check(int x, int y){
	return 0<=x && x<N && 0<=y && y<M;
}

void bfs(){
	memset(visited, 0, sizeof(visited));
	memset(flower, 0, sizeof(flower));
	queue<Point> q;

	for(const Point &p : green){
		q.push(p);
		visited[p.x][p.y] = 1;
		flower[p.x][p.y] = 1;
	}
	for(const Point &p : red){
		q.push(p);
		visited[p.x][p.y] = 1;
		flower[p.x][p.y] = -1;
	}

	int cnt = 0;
	while(!q.empty()){
		Point now = q.front(); q.pop();

		int nowTime = visited[now.x][now.y];
		int nowColor = flower[now.x][now.y];

		if(flower[now.x][now.y] == 2) continue;

		for(int i=0; i<4; i++){
			int nx = now.x + dx[i];
			int ny = now.y + dy[i];

			if(!bound_check(nx, ny)) continue;
			if(arr[nx][ny] == 0) continue;

			if(visited[nx][ny] == 0){
				visited[nx][ny] = nowTime + 1;
				flower[nx][ny] = nowColor;
				q.push({nx, ny});
			}
			else{
				if(flower[nx][ny] != 2 && flower[nx][ny] != nowColor){
					if(visited[nx][ny] != nowTime + 1) continue;
					cnt++;
					flower[nx][ny] = 2;
				}
			}
		}
	}
	result = max(result, cnt);

	// cout << "visited-----------------------------------------\n";
	// for(int i=0; i<N; i++){
	// 	for(int j=0; j<M; j++){
	// 		cout << visited[i][j] << ' ';
	// 	}
	// 	cout << '\n';
	// }
	// cout << '\n';
	
	// cout << "flower-----------------------------------------\n";
	// for(int i=0; i<N; i++){
	// 	for(int j=0; j<M; j++){
	// 		cout << flower[i][j] << ' ';
	// 	}
	// 	cout << '\n';
	// }
	// cout << "\n\n";
}

void dfs(int depth){
	if(green.size()==G && red.size()==R){
		bfs();
		return;
	}
	
	if(green.size() + canLoc.size() - depth < G) return;
	if(red.size() + canLoc.size() - depth < R) return;
	if(depth==canLoc.size()) return;
	
	if(green.size() < G){
		green.push_back(canLoc[depth]);
		dfs(depth+1);
		green.pop_back();
	}
	if(red.size() < R){
		red.push_back(canLoc[depth]);
		dfs(depth+1);
		red.pop_back();
	}
	dfs(depth+1);
}

int main() {
	cin >> N >> M >> G >> R;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cin >> arr[i][j];
			if(arr[i][j] == 2){
				canLoc.push_back({i, j});
			}
		}
	}

	dfs(0);

	cout << result << '\n';

	return 0;
}