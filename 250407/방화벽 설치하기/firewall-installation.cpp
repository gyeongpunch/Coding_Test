#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define MAX_SZ 8
#define Target 3
struct Point {
	int x, y;
};

int N, M;
int arr[MAX_SZ][MAX_SZ];
int visited[MAX_SZ][MAX_SZ];
vector<Point> totalEmpty;
vector<Point> Fire;
vector<int> path;
int result = 0;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

bool bound_check(int x, int y) {
	return 0 <= x && x < N && 0 <= y && y < M;
}

void calc() {
	memset(visited, 0, sizeof(visited));
	queue<Point> q;
	for (const Point &f : Fire) {
		q.push(f);
	}
	for (const int &idx : path) {
		visited[totalEmpty[idx].x][totalEmpty[idx].y] = 1;
	}

	int rest = totalEmpty.size() - 3;

	int nx, ny;
	while (!q.empty()) {
		Point now = q.front(); q.pop();
		if(arr[now.x][now.y] == 0) rest--;
		for (int i = 0; i < 4; i++)
		{
			nx = now.x + dx[i];
			ny = now.y + dy[i];

			if (!bound_check(nx, ny)) continue;
			if (visited[nx][ny] == 1) continue;
			if (arr[nx][ny] != 0) continue;

			q.push({ nx, ny });
			visited[nx][ny] = 1;
		}
		
	}
	result = max(result, rest);
}

void makeComb(int depth, int prev) {
	if (depth == Target) {
		calc();
		return;
	}

	for (int i = prev + 1; i < totalEmpty.size(); i++) {
		path.push_back(i);

		makeComb(depth + 1, i);

		path.pop_back();
	}
}

int main() {
	fastio;

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 0) {
				totalEmpty.push_back({ i, j });
			}
			else if (arr[i][j] == 2) {
				Fire.push_back({ i, j });
			}
		}
	}

	makeComb(0, -1);

	cout << result << '\n';

	return 0;
}