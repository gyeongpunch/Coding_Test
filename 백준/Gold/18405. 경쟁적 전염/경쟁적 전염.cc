#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point{
	int x, y;
};

const int MX = 200;

int N, K;
int arr[MX][MX];
int S, X, Y;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
vector<Point> v;

bool bound_check(int x, int y){
	return 0<=x && x<N && 0<=y && y<N;
}

void input(){
	cin >> N >> K;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cin >> arr[i][j];
			if(arr[i][j] != 0) v.push_back({i, j});
		}
	}
	cin >> S >> X >> Y;
	X--;
	Y--;
}

bool CMP(const Point &a, const Point &b){
	return arr[a.x][a.y] < arr[b.x][b.y];
}

void solution(){
	int now_time = 0;
	vector<Point> tmp;
	for(int i=0; i<S; i++){
		sort(v.begin(), v.end(), CMP);
		tmp.clear();

		for(const Point &p : v){
			for(int i=0; i<4; i++){
				int nx = p.x + dx[i];
				int ny = p.y + dy[i];

				if(!bound_check(nx, ny)) continue;
				if(arr[nx][ny] != 0) continue;

				arr[nx][ny] = arr[p.x][p.y];
				tmp.push_back({nx, ny});
			}
		}

		v = tmp;
	}
}

void get_result(){
	cout << arr[X][Y] << '\n';
}

int main() {
	input();

	solution();

	get_result();
	
	return 0;
}