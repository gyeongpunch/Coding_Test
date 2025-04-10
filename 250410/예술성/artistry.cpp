#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define MAX_N 29

struct Point {
	int x, y;
};

int N, result = 0;
int arr[MAX_N][MAX_N];
int arrTmp[MAX_N][MAX_N];
int groupBound[MAX_N * MAX_N + 1][MAX_N * MAX_N + 1];
int groupCnt[MAX_N * MAX_N + 1];
int visited[MAX_N][MAX_N];
int arrGroupNum[MAX_N * MAX_N + 1];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };


bool bound_check(int x, int y) {
	return 0 <= x && x < N && 0 <= y && y < N;
}

void grouping_bfs(int x, int y, int groupNum) {
	visited[x][y] = groupNum;
	groupCnt[groupNum]++;
	arrGroupNum[groupNum] = arr[x][y];

	queue<Point> q;
	q.push({ x, y });

	int nx, ny;
	while (!q.empty()) {
		Point now = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			nx = now.x + dx[i];
			ny = now.y + dy[i];

			if (!bound_check(nx, ny)) continue;

			if (visited[nx][ny] != 0) {
				if (visited[nx][ny] != visited[x][y]) {
					groupBound[visited[now.x][now.y]][visited[nx][ny]]++;
					groupBound[visited[nx][ny]][visited[now.x][now.y]]++;
				}
			}
			else {
				if (arr[nx][ny] == arr[x][y]) {
					q.push({ nx, ny });
					visited[nx][ny] = groupNum;
					groupCnt[groupNum]++;
				}
			}
		}
	}

}

void calc_art_score() {
	memset(visited, 0, sizeof(visited));
	memset(groupBound, 0, sizeof(groupBound));
	memset(groupCnt, 0, sizeof(groupCnt));
	memset(arrGroupNum, 0, sizeof(arrGroupNum));

	int groupNum = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j] == 0) {
				grouping_bfs(i, j, groupNum++);
			}
		}
	}

	for (int i = 2; i < groupNum; i++) {
		for (int j = 1; j < i; j++) {
			result += (groupCnt[i] + groupCnt[j]) * arrGroupNum[i] * arrGroupNum[j] * groupBound[i][j];
		}
	}
}

void cross_rotate() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == N / 2 || j == N / 2) {
				arrTmp[i][j] = arr[j][N-i-1];
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == N / 2 || j == N / 2) {
				arr[i][j] = arrTmp[i][j];
			}
		}
	}
}

void one_rotate(int x, int y, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arrTmp[x+j][y+n-i-1] = arr[x+i][y+j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[x + i][y + j] = arrTmp[x + i][y + j];
		}
	}
}

void total_rotate() {
	cross_rotate();

	one_rotate(0, 0, N / 2);
	one_rotate(N/2+1, 0, N / 2);
	one_rotate(0, N/2+1, N / 2);
	one_rotate(N / 2 + 1, N / 2 + 1, N / 2);
}


int main(void) {
	fastio;

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	calc_art_score();
	// cout << result << '\n';
	for (int i = 0; i < 3; i++) {
		total_rotate();
		calc_art_score();
	}

	cout << result << '\n';

	return 0;
}