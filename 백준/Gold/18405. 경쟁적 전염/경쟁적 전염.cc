#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Virus{
	int type;
	int x, y;
	int time;
};

const int MX = 200;

int N, K;
int arr[MX][MX];
int S, X, Y;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
vector<Virus> v;

bool bound_check(int x, int y){
	return 0<=x && x<N && 0<=y && y<N;
}

void input(){
	cin >> N >> K;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cin >> arr[i][j];
			if(arr[i][j] != 0) v.push_back({arr[i][j], i, j, 0});
		}
	}
	cin >> S >> X >> Y;
	X--;
	Y--;
}

bool CMP(const Virus &a, const Virus &b){
	return a.type < b.type;
}

void solution(){
	sort(v.begin(), v.end(), CMP);
		
	queue<Virus> q;
	for(const Virus &vi : v) q.push(vi);

	while(!q.empty()){
		Virus now = q.front(); q.pop();

		if(now.time == S) break;

		for(int i=0; i<4; i++){
			int nx = now.x + dx[i];
			int ny = now.y + dy[i];

			if(!bound_check(nx, ny)) continue;
			if(arr[nx][ny] != 0) continue;

			arr[nx][ny] = arr[now.x][now.y];
			q.push({now.type, nx, ny, now.time+1});
		}
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