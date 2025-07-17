#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

struct DPoint{
	int dx, dy;
};

const int MX = 32;

int N;
int arr[MX][MX];
ll dp[3][MX][MX];

vector<vector<vector<DPoint>>> pipes = {
	{{{0, 1}}, {{MX, MX}}, {{1, 0}, {0, 1}, {1, 1}}},
	{{{MX, MX}}, {{1, 0}}, {{1, 0}, {0, 1}, {1, 1}}},
	{{{0, 1}}, {{1, 0}}, {{1, 0}, {0, 1}, {1, 1}}},
};

bool bound_check(int x, int y){
	return 0<=x && x<N && 0<=y && y<N;
}

void gogo(int x, int y, int idx){
	for(int i=0; i<3; i++){
		bool flag = true;
		int nx, ny;
		for(const DPoint &p : pipes[idx][i]){
			nx = x + p.dx;
			ny = y + p.dy;
			if(!bound_check(nx, ny)) flag = false;
			if(arr[nx][ny] == 1) flag = false;
		}
		if(flag) dp[i][nx][ny] += dp[idx][x][y];
	}
}

ll solution(){
	dp[0][0][1] = 1;

	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(arr[i][j] == 1) continue;
			for(int k=0; k<3; k++){
				gogo(i, j, k);
			}
		}
	}
	return dp[0][N-1][N-1] + dp[1][N-1][N-1] + dp[2][N-1][N-1];
}

int main() {
	cin >> N;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cin >> arr[i][j];
		}
	}
	
	ll result = solution();

	cout << result << '\n';

	return 0;
}