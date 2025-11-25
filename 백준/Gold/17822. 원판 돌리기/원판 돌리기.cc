#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

struct Point{
	int x, y;
};

struct Info{
	int sum, cnt;
};

const int MX = 51;

int N, M, T;
int result;
Info Sum;
int arr[MX][MX];
int visited[MX][MX];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void input(){
	cin >> N >> M >> T;
	for(int i=1; i<=N; i++){
		for(int j=0; j<M; j++){
			cin >> arr[i][j];
			Sum.sum += arr[i][j];
			Sum.cnt++;
		}
	}
}

void rotate(int X, int d, int k){
	for(int x=X; x<=N; x+=X){
		if(d == 0){
			for(int i=0; i<k; i++){
				int tmp = arr[x][M-1];
				for(int j=M-1; j>0; j--){
					arr[x][j] = arr[x][j-1];
				}
				arr[x][0] = tmp;
			}
		}
		else{
			for(int i=0; i<k; i++){
				int tmp = arr[x][0];
				for(int j=0; j<M-1; j++){
					arr[x][j] = arr[x][j+1];
				}
				arr[x][M-1] = tmp;
			}
		}
	}
}

bool bound_check(int x, int y){
	return 1<=x && x<=N;
}

void add(){
	// cout << Sum.sum << ' ' << Sum.cnt << ' ' << (double)Sum.sum / Sum.cnt << "\n\n";

	Info tmp = Sum;
	for(int i=1; i<=N; i++){
		for(int j=0; j<M; j++){
			if(arr[i][j] == 0) continue;

			if(arr[i][j] > (double)Sum.sum / Sum.cnt){
				arr[i][j]--;
				tmp.sum--;
			}
			else if(arr[i][j] < (double)Sum.sum / Sum.cnt){
				arr[i][j]++;
				tmp.sum++;
			}
		}
	}
	Sum = tmp;
}

void bfs(int x, int y, bool &total_flag){
	visited[x][y] = 1;
	int target = arr[x][y];
	
	bool Flag = false;
	for(int i=0; i<4; i++){
		int nx = x + dx[i];
		int ny = (y + dy[i] + M) % M;

		if(!bound_check(nx, ny)) continue;
		if(arr[nx][ny] == target) Flag = true;
	}

	if(!Flag) return;
	// cout << x << ' ' << y << "\n\n";
	total_flag = true;
	queue<Point> q;
	q.push({x, y});

	while(!q.empty()){
		Point now = q.front(); q.pop();

		Sum.sum -= arr[now.x][now.y];
		Sum.cnt--;
		arr[now.x][now.y] = 0;

		for(int i=0; i<4; i++){
			int nx = now.x + dx[i];
			int ny = (now.y + dy[i] + M) % M;

			if(!bound_check(nx, ny)) continue;
			if(visited[nx][ny] == 1) continue;
			if(arr[nx][ny] != target) continue;

			q.push({nx, ny});
			visited[nx][ny] = 1;
		}
	}
}

void remove(){
	memset(visited, 0, sizeof(visited));
	bool total_flag = false;
	for(int i=1; i<=N; i++){
		for(int j=0; j<M; j++){
			if(visited[i][j]==1) continue;
			if(arr[i][j] == 0) continue;

			bfs(i, j, total_flag);
		}
	}
	if(!total_flag) add();
}

void get_result(){
	cout << Sum.sum << '\n';
}

void print_arr(){
	for(int i=1; i<=N; i++){
		for(int j=0; j<M; j++){
			cout << arr[i][j] << ' ';
		}
		cout << "\n";
	}
}

void solution(){
	for(int i=0; i<T; i++){
		int x, d, k;
		cin >> x >> d >> k;
		rotate(x, d, k);

		// cout << "after rotate:\n";
		// print_arr();

		remove();

		// cout << "after remove:\n";
		// print_arr();
	}
}

int main() {
	input();

	solution();

	get_result();

	return 0;
}