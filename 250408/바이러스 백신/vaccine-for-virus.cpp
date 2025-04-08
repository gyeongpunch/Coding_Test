#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define MAX_N 50

struct Point {
	int x, y;
};

int N, M;
int arr[MAX_N][MAX_N];
int visited[MAX_N][MAX_N];
vector<Point> totalHos;
int hosCnt = 0;
int virCnt = 0;
vector<int> path;
int result = MAX_N * MAX_N;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

bool bound_check(int x, int y) {
	return 0 <= x && x < N && 0 <= y && y < N;
}

void calc() {
	queue<Point> q;
	memset(visited, -1, sizeof(visited));

	for (int i : path) {
		q.push(totalHos[i]);
		visited[totalHos[i].x][totalHos[i].y] = 0;
	}

	int removeTime = 0;
	int rest = virCnt;

	int nx, ny;
	while (!q.empty()) {
		Point now = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			nx = now.x + dx[i];
			ny = now.y + dy[i];

			if (!bound_check(nx, ny)) continue;
			if (visited[nx][ny] != -1) continue;
			if (arr[nx][ny] == 1) continue;

			q.push({ nx, ny });
			visited[nx][ny] = visited[now.x][now.y] + 1;

			if (arr[nx][ny] == 0) {
				rest--;
				removeTime = visited[nx][ny];
			}
		}
	}

	if (rest == 0) {
		result = min(result, removeTime);
	}

}

void makeComb(int depth, int prev) {
	if (depth == M) {
		calc();
		return;
	}

	for (int i = prev + 1; i < hosCnt; i++) {
		path.push_back(i);

		makeComb(depth + 1, i);

		path.pop_back();
	}
}

int main(void) {
	fastio;

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				totalHos.push_back({ i, j });
				hosCnt++;
			}
			if (arr[i][j] == 0) {
				virCnt++;
			}
		}
	}

	makeComb(0, -1);

	if (result == MAX_N * MAX_N) result = -1;

	cout << result << '\n';

	return 0;
}