#include <iostream>
#include <queue>
#include <climits>
#include <vector>
using namespace std;

struct Info{
	int x, y, c;
};

struct CMP{
	bool operator()(const Info &a, const Info &b){
		return a.c > b.c;
	}
};

const int MX = 125;

int N;
int arr[MX][MX];
int dist[MX][MX];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void init(){
	for(int i=0; i<MX; i++){
		fill(dist[i], dist[i]+MX, INT_MAX);
	}
}

void input(){
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cin >> arr[i][j];
		}
	}
}

bool bound_check(int x, int y){
	return 0<=x && x<N && 0<=y && y<N;
}

void solution(int turn){
	priority_queue<Info, vector<Info>, CMP> pq;
	dist[0][0] = arr[0][0];
	pq.push({0, 0, arr[0][0]});

	while(!pq.empty()){
		Info now = pq.top(); pq.pop();

		if(dist[now.x][now.y] < now.c) continue;

		for(int i=0; i<4; i++){
			int nx = now.x + dx[i];
			int ny = now.y + dy[i];

			if(!bound_check(nx, ny)) continue;
			if(dist[nx][ny] <= dist[now.x][now.y] + arr[nx][ny]) continue;

			pq.push({nx, ny, dist[now.x][now.y] + arr[nx][ny]});
			dist[nx][ny] = dist[now.x][now.y] + arr[nx][ny];
		}
	}
	cout << "Problem " << turn << ": " << dist[N-1][N-1] << '\n';
}

int main() {
	int turn = 1;
	while(true){
		cin >> N;

		if(N == 0) break;

		init();

		input();

		solution(turn++);
	}


	return 0;
}