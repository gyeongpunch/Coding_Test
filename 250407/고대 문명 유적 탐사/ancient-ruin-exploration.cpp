#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
const int N = 5;
const int NN = 3;
const int MAX_M = 300;

struct Info {
	int value;
	int rCnt;
	int cx, cy;
};

struct Point {
	int x, y;
};

void simul_init();
void input();
void rotate(int x, int y);
bool bound_check(int x, int y);
int K, M;
int arr[N][N];
int arrTmp[N][N];
int new_list[MAX_M];
int newIdx = 0;
int visited[N][N];
bool resultFlag;
int result;
Info maxInfo;
vector<Point> maxInfoVector;
vector<Point> oneVector;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };


int bfs(int x, int y) {
	queue<Point> q;
	q.push({ x, y });
	visited[x][y] = 1;
	int cnt = 0;
	vector<Point> tmp;
	int nx, ny;
	while (!q.empty()) {
		Point now = q.front(); q.pop();

		tmp.push_back(now);
		cnt++;

		for (int i = 0; i < 4; i++)
		{
			nx = now.x + dx[i];
			ny = now.y + dy[i];

			if (!bound_check(nx, ny)) continue;
			if (arr[nx][ny] != arr[x][y]) continue;
			if (visited[nx][ny] == 1) continue;

			q.push({ nx, ny });
			visited[nx][ny] = 1;
		}
	}

	if (cnt >= 3) {
		for (const Point &p : tmp) {
			oneVector.push_back(p);
		}
		return cnt;
	}
	return 0;
}

void update_one_value(int x, int y, int r) {
	memset(visited, 0, sizeof(visited));

	int sum = 0;
	oneVector.clear();
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{	
			if (visited[i][j] == 0) {
				sum += bfs(i, j);
			}
		}
	}

	if (maxInfo.value < sum ||
		(maxInfo.value == sum && (maxInfo.rCnt > r ||
		(maxInfo.rCnt == r && (maxInfo.cy > y + 1 ||
		(maxInfo.cy == y + 1 && maxInfo.cx > x + 1)))))) {
		maxInfo.value = sum;
		maxInfo.rCnt = r;
		maxInfo.cx = x + 1;
		maxInfo.cy = y + 1;
		maxInfoVector = oneVector;
	}
}

void get_max_rotate() {
	for (int x = 0; x <= 2; x++) {
		for (int y = 0; y <= 2; y++) {
			for (int r = 0; r < 4; r++) {
				rotate(x, y);

				if(r<3) update_one_value(x, y, r);
			}
		}
	}
}

void bomb() {
	for (const Point &p : maxInfoVector) {
		arr[p.x][p.y] = 0;
		result++;
	}
}

void new_fill() {
	for (int y = 0; y < N; y++) {
		for (int x = N - 1; x > -1; x--) {
			if (arr[x][y] == 0) {
				arr[x][y] = new_list[newIdx++];
			}
		}
	}
}

void simulation() {
	maxInfo = { -1, 4, -1, -1 };
	maxInfoVector.clear();

	get_max_rotate();

	if (maxInfo.value == 0) {
		resultFlag = false;
		return;
	}
	for (int i = 0; i <= maxInfo.rCnt; i++) {
		rotate(maxInfo.cx - 1, maxInfo.cy - 1);
	}

	bomb();
	new_fill();
	
	while (true) {
		maxInfo = { -1, 4, -1, -1 };
		maxInfoVector.clear();

		update_one_value(0, 0, 0);

		if (maxInfo.value == 0) {
			return;
		}
		bomb();
		new_fill();
	}
}

int main() {
	fastio;

	input();

	for (int i = 0; i < K; i++)
	{
		simul_init();

		simulation();

		if (resultFlag) {
			cout << result << ' ';
		}
		else {
			break;
		}
	}


	return 0;
}

void rotate(int x, int y) {
	for (int i = 0; i < NN; i++) {
		for (int j = 0; j < NN; j++) {
			arrTmp[x + j][y + NN - i - 1] = arr[x + i][y + j];
		}
	}
	for (int i = 0; i < NN; i++) {
		for (int j = 0; j < NN; j++) {
			arr[x + i][y + j] = arrTmp[x + i][y + j];
		}
	}
}

void input() {
	cin >> K >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			arrTmp[i][j] = arr[i][j];
		}
	}
	for (int i = 0; i < M; i++)
	{
		cin >> new_list[i];
	}
}

void simul_init() {
	resultFlag = true;
	result = 0;
}

bool bound_check(int x, int y) {
	return 0 <= x && x < N && 0 <= y && y < N;
}