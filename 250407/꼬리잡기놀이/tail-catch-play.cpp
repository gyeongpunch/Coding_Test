#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define MAX_N 20
#define MAX_M 5

void input();
bool bound_check(int x, int y);
void grouping();
void bfs(int x, int y, int groupNum);
void total_move();

struct Point {
	int x, y;
};

int N, M, K;
int arr[MAX_N][MAX_N];
int arrMap[MAX_N][MAX_N];
int visited[MAX_N][MAX_N];
vector<Point> team[MAX_M + 1];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int result = 0;

void plus_score(int x, int y, int groupNum) {
	for (int i = 0; i < team[groupNum].size(); i++) {
		if (team[groupNum][i].x == x && team[groupNum][i].y == y) {
			result += (i + 1) * (i + 1);
			return;
		}
	}
}

void reverse(int groupNum) {
	vector<Point> tmp;
	for (int i = team[groupNum].size() - 1; i > -1; i--) {
		tmp.push_back(team[groupNum][i]);
	}
	team[groupNum] = tmp;

	for (int i = 0; i < tmp.size(); i++) {
		if (i == 0) {
			arr[tmp[i].x][tmp[i].y] = 1;
		}
		else if (i == tmp.size() - 1) {
			arr[tmp[i].x][tmp[i].y] = 3;
		}
		else {
			arr[tmp[i].x][tmp[i].y] = 2;
		}
	}

}

void left_gogo(int x) {
	for (int y = 0; y < N - 1; y++) {
		if (1 <= arr[x][y] && arr[x][y] <= 3) {
			plus_score(x, y, arrMap[x][y]);
			reverse(arrMap[x][y]);
			return;
		}
	}
}

void bottom_gogo(int y) {
	for (int x = N - 1; x > -1; x--) {
		if (1 <= arr[x][y] && arr[x][y] <= 3) {
			plus_score(x, y, arrMap[x][y]);
			reverse(arrMap[x][y]);
			return;
		}
	}
}

void right_gogo(int x) {
	for (int y = N - 1; y > -1; y--) {
		if (1 <= arr[x][y] && arr[x][y] <= 3) {
			plus_score(x, y, arrMap[x][y]);
			reverse(arrMap[x][y]);
			return;
		}
	}
}

void top_gogo(int y) {
	for (int x = 0; x < N; x++) {
		if (1 <= arr[x][y] && arr[x][y] <= 3) {
			plus_score(x, y, arrMap[x][y]);
			reverse(arrMap[x][y]);
			return;
		}
	}
}

void simulation() {
	for (int k = 0; k < K; k++) {

		total_move();

		int now_k = k % (N * 4);

		if (0 <= now_k && now_k < N) {
			left_gogo(now_k);
		}
		else if (N <= now_k && now_k < N*2) {
			now_k -= N;
			bottom_gogo(now_k);
		}
		else if (N*2 <= now_k && now_k < N*3) {
			now_k -= N * 2;
			right_gogo(N- now_k -1);
		}
		else if (N*3 <= now_k && now_k < N*4) {
			now_k -= N * 3;
			top_gogo(N- now_k -1);
		}
	}
}

int main(void) {
	fastio;

	input();
	grouping();
	
	simulation();
	
	cout << result << '\n';

	return 0;
}

void total_move() {
	int nx, ny;
	for (int i = 1; i <= M; i++) {
		vector<Point> tmp;

		Point now = team[i][0];

		for (int j = 0; j < 4; j++) {
			nx = now.x + dx[j];
			ny = now.y + dy[j];

			if (!bound_check(nx, ny)) continue;
			if (arrMap[now.x][now.y] != arrMap[nx][ny]) continue;
			if (arr[nx][ny] == 2) continue;

			tmp.push_back({ nx, ny });
			break;
		}

		for (int j = 0; j < team[i].size() - 1; j++) {
			tmp.push_back(team[i][j]);
		}

		arr[team[i].back().x][team[i].back().y] = 4;
		arr[team[i][0].x][team[i][0].y] = 2;

		arr[tmp.back().x][tmp.back().y] = 3;
		arr[tmp[0].x][tmp[0].y] = 1;

		team[i] = tmp;
	}
}

void grouping() {
	int groupNum = 1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (arr[i][j] == 1) {
				bfs(i, j, groupNum++);
			}
		}
	}
}

void bfs(int x, int y, int groupNum) {
	queue<Point> q;
	q.push({ x, y });
	visited[x][y] = 1;
	arrMap[x][y] = groupNum;
	team[groupNum].push_back({ x, y });

	int nx, ny;
	while (!q.empty()) {
		Point now = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			nx = now.x + dx[i];
			ny = now.y + dy[i];

			if (!bound_check(nx, ny)) continue;
			if (visited[nx][ny] == 1) continue;
			if (arr[nx][ny] == 0) continue;

			if (arr[now.x][now.y] == 1 && arr[nx][ny] == 3) continue;

			if (arr[nx][ny] != 4) {
				team[groupNum].push_back({ nx, ny });
			}
			q.push({ nx, ny });
			visited[nx][ny] = 1;
			arrMap[nx][ny] = groupNum;
			break;
		}
	}
}

void input() {
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}
}

bool bound_check(int x, int y) {
	return 0 <= x && x < N && 0 <= y && y < N;
}