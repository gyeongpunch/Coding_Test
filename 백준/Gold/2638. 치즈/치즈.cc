#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct Point{
	int x, y;
};

const int MX = 102;

int N, M;
int arr[MX][MX];
int arrTmp[MX][MX];
int visited[MX][MX];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int result, cheese, cnt;

bool bound_check(int x, int y){
	return 0<=x && x<=N+1 && 0<=y && y<=M+1;
}

void input(){
	cin >> N >> M;
	for(int x=1; x<=N; x++){
		for(int y=1; y<=M; y++){
			cin >> arr[x][y];
			arrTmp[x][y] = arr[x][y];
			if(arr[x][y] == 1) cheese++;
		}
	}
}

void melt(){
	queue<Point> q1;
	queue<Point> q2;
	q1.push({0, 0});
	memset(visited, 0, sizeof(visited));
	visited[0][0] = 1;

	while(!q1.empty()){
		Point now = q1.front(); q1.pop();

		for(int i=0; i<4; i++){
			int nx = now.x + dx[i];
			int ny = now.y + dy[i];

			if(!bound_check(nx, ny)) continue;
			if(visited[nx][ny] == 1) continue;

			visited[nx][ny] = 1;
			if(arr[nx][ny] == 0){
				q1.push({nx, ny});
			}
			else{
				q2.push({nx, ny});
			}
		}
	}

	while(!q2.empty()){
		Point now = q2.front(); q2.pop();

		int nowCnt = 0;
		for(int d=0; d<4; d++){
			int nx = now.x + dx[d];
			int ny = now.y + dy[d];

			if(!bound_check(nx, ny)) continue;
			if(arr[nx][ny] == 0 && visited[nx][ny] == 1) nowCnt++;
		}

		if(nowCnt >= 2) {
			arrTmp[now.x][now.y] = 0;
			cnt++;
		}
		else arrTmp[now.x][now.y] = 1;
	}


	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			arr[i][j] = arrTmp[i][j];
		}
	}
}

void solution(){
	while(true){
		if(cnt == cheese) break;

		melt();

		result++;
	}

	cout << result << '\n';
}

int main() {
	input();

	solution();

	return 0;
}

/*
N*M 모눈종이
실내 온도에 내어놓으면 공기와 접촉하여 천천히 녹는다
4변 중에서 적어도 2변 이상이 실내온도의 공기와 접촉한 것은 정확히 한시간만에 녹아 없어져 버린다.

*/