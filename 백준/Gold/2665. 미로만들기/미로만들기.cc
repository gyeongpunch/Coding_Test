#include <iostream>
#include <climits>
#include <deque>
using namespace std;

struct Info{
	int x, y, cnt;
};

struct CMP{
	bool operator()(const Info &a, const Info &b){
		return a.cnt > b.cnt;
	}
};

const int MX = 50;

int N;
char arr[MX][MX];
int visited[MX][MX];
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
			visited[i][j] = INT_MAX;
		}
	}
}

void solution(){
	deque<Info> dq;
	dq.push_front({0, 0, 0});
	visited[0][0] = 0;

	while(!dq.empty()){
		Info now = dq.front(); dq.pop_front();
		
		for(int i=0; i<4; i++){
			int nx = now.x + dx[i];
			int ny = now.y + dy[i];

			if(!bound_check(nx, ny)) continue;

			int w = (arr[nx][ny] == '1') ? 0 : 1;
			int new_cnt = now.cnt + w;

			if(visited[nx][ny] <= new_cnt) continue;

			if(w==0) dq.push_front({nx, ny, new_cnt});
			else dq.push_back({nx, ny, new_cnt});
			visited[nx][ny] = new_cnt;
		}
	}
}

void get_result(){
	cout << visited[N-1][N-1] << '\n';
}

int main() {
	input();

	solution();

	get_result();

	return 0;
}