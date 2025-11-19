#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

struct Point{
	int x, y;
};

const int MX = 100;

int N, M;
int arr[MX][MX];
int visited[MX][MX];
int total_cnt;
int result_hour, result_cnt;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool bound_check(int x, int y){
	return 0<=x && x<N && 0<=y && y<M;
}

void input(){
	cin >> N >> M;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cin >> arr[i][j];
			if(arr[i][j] == 1) total_cnt++;
		}
	}
}

void solution(){
	int sum_cnt = 0;

	while(true){
		memset(visited, 0, sizeof(visited));
		queue<Point> q;
		q.push({0, 0});
		visited[0][0] = 1;
		int cnt = 0;

		vector<Point> melt;

		while(!q.empty()){
			Point now = q.front(); q.pop();

			for(int i=0; i<4; i++){
				int nx = now.x + dx[i];
				int ny = now.y + dy[i];

				if(!bound_check(nx, ny)) continue;
				if(visited[nx][ny]) continue;

				if(arr[nx][ny] == 0){
					q.push({nx, ny});
					visited[nx][ny] = 1;
				}
				else{
					visited[nx][ny] = 1;
					melt.push_back({nx, ny});
					cnt++;
				}
			}
		}

		for(const Point &p : melt){
			arr[p.x][p.y] = 0;
		}
		// cout << "cnt: " << cnt << '\n';
		// for(int i=0; i<N; i++){
		// 	for(int j=0; j<M; j++){
		// 		cout << arr[i][j] << ' ';
		// 	}
		// 	cout << '\n';
		// }

		// cout << "\n\n";

		if(cnt == 0){
			return;
		}
		else{
			result_cnt = total_cnt - sum_cnt;
			sum_cnt += cnt;
		}

		
		result_hour++;
	}
}

void get_result(){
	cout << result_hour << '\n' << result_cnt << '\n';
}

int main() {
	input();

	solution();

	get_result();

	return 0;
}