#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define MAX_N 20

struct Point {
	int x, y;
};

struct Info {
	int sz, redCnt, x, y, maxX, minY;
};

int N, M;
int arr[MAX_N][MAX_N];
int arrTmp[MAX_N][MAX_N];
int visited[MAX_N][MAX_N];
vector<Point> redLoc;
int result = 0;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

bool bound_check(int x, int y) {
	return 0 <= x && x < N && 0 <= y && y < N;
}

void red_visited_reset() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == 0) {
				visited[i][j] = 0;
			}
		}
	}
}

void find_bfs(Info &maxInfo, int x, int y) {
	red_visited_reset();
	queue<Point> q;
	q.push({ x, y });
	visited[x][y] = 1;
	Info nowInfo = { 1, 0, x, y, x, y };

	int nx, ny;
	while (!q.empty()) {
		Point now = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			nx = now.x + dx[i];
			ny = now.y + dy[i];

			if (!bound_check(nx, ny)) continue;
			if (visited[nx][ny] != 0) continue;
			
			if (arr[nx][ny] == arr[x][y]) {
				q.push({ nx, ny });
				visited[nx][ny] = 1;

				nowInfo.sz++;
				nowInfo.maxX = max(nx, nowInfo.maxX);
				nowInfo.minY = min(ny, nowInfo.minY);
			}
			else if (arr[nx][ny] == 0) {
				q.push({ nx, ny });
				visited[nx][ny] = 1;

				nowInfo.sz++;
				nowInfo.redCnt++;
			}
		}
	}

	if (nowInfo.sz < 2) return;

	if (maxInfo.sz < nowInfo.sz || 
		((maxInfo.sz == nowInfo.sz && maxInfo.redCnt > nowInfo.redCnt) || 
		((maxInfo.redCnt == nowInfo.redCnt && maxInfo.maxX < nowInfo.maxX) || 
		(maxInfo.maxX == nowInfo.maxX && maxInfo.minY > nowInfo.minY)))) {
		maxInfo = nowInfo;
	}
}

void boom(int x, int y) {
	queue<Point> q;
	memset(visited, 0, sizeof(visited));
	q.push({ x, y });
	visited[x][y] = 1;

	int nx, ny;
	while(!q.empty()){
		Point now = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			nx = now.x + dx[i];
			ny = now.y + dy[i];

			if (!bound_check(nx, ny)) continue;
			if (visited[nx][ny] != 0) continue;

			if (arr[nx][ny] == arr[x][y] || arr[nx][ny] == 0) {
				q.push({ nx, ny });
				visited[nx][ny] = 1;
				arr[nx][ny] = -2;
			}
		}
	}
	arr[x][y] = -2;
}

void drop() {
	for (int y = 0; y < N; y++) {
		int curX = N - 1;
		for (int x = N - 1; x > -1; x--) {
			if (arr[x][y] == -2) continue;

			else if (arr[x][y] == -1) {
				if (x - 1 < 0) break;
				curX = x - 1;
			}
			else if (0 <= arr[x][y]) {
				arr[curX][y] = arr[x][y];
				if (x != curX) {
					arr[x][y] = -2;
				}
				if (curX - 1 < 0) break;
				curX--;
				while (arr[curX - 1][y] == -1 && curX < x) {
					curX--;
				}
			}
		}
	}
}

void rotate() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			arrTmp[i][j] = arr[j][N - i - 1];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			arr[i][j] = arrTmp[i][j];
		}
	}
}

bool simulation() {
	Info maxInfo = { 0, 0, 0, 0, 0, 0 };
	memset(visited, 0, sizeof(visited));

	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			if (visited[x][y] == 0 && 1 <= arr[x][y]) {
				find_bfs(maxInfo, x, y);
			}
		}
	}

	if (maxInfo.sz == 0) return false;
	boom(maxInfo.x, maxInfo.y);
	result += maxInfo.sz * maxInfo.sz;

	drop();

	rotate();

	drop();
	return true;
}

bool is_over() {
	Info maxInfo = { 0, 0, 0, 0, 0, 0 };
	memset(visited, 0, sizeof(visited));

	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			if (visited[x][y] == 0 && 1 <= arr[x][y]) {
				find_bfs(maxInfo, x, y);
			}
		}
	}

	return maxInfo.sz != 0;
}

int main(void) {
	fastio;

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	while (true) {
		if (!simulation()) break;
	}

	cout << result << '\n';

	return 0;
}