#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define MAX_N 99

struct Point {
	int x, y;
};

struct Sool {
	Point p;
	int nowLength;
	int nowLimitLength;
	int nowLimitCnt;
	int dir;
	int clock;
};

struct Run {
	Point p;
	int dir;
};

void input();
bool bound_check(int x, int y);
int get_dist(Run run);
void run_move();

int N, M, H, K;
int arrTree[MAX_N][MAX_N];
int arr[MAX_N][MAX_N];
int visited[5][5];
int visitedCnt = 1;
vector<Run> arrRun;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
Sool nowSool;
int result = 0;

void vprint() {
	cout << "=======================\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << visited[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << "=======================\n";
}

void sool_move() {
	int nx, ny;
	visited[nowSool.p.x][nowSool.p.y] = visitedCnt++;
	nx = nowSool.p.x + dx[nowSool.dir];
	ny = nowSool.p.y + dy[nowSool.dir];

	if ((nx == 0 && ny == 0) || (nx == N / 2 && ny == N / 2)) {
		if (nowSool.clock == 0) {
			nowSool = { {0, 0}, 1, N, 1, 2, 1 };
		}
		else if (nowSool.clock == 1) {
			nowSool = { {N / 2, N / 2}, 0, 1, 0, 0, 0 };
		}

		return;
	}

	if (nowSool.clock == 0) {
		nowSool.p.x = nx;
		nowSool.p.y = ny;
		nowSool.nowLength++;
		if (nowSool.nowLength == nowSool.nowLimitLength) {
			nowSool.dir = (nowSool.dir + 1) % 4;
			nowSool.nowLimitCnt++;
			nowSool.nowLength = 0;

			if (nowSool.nowLimitCnt == 2) {
				nowSool.nowLimitCnt = 0;
				nowSool.nowLimitLength++;
			}
		}
	}
	else if (nowSool.clock == 1) {
		nowSool.p.x = nx;
		nowSool.p.y = ny;
		nowSool.nowLength++;
		if (nowSool.nowLength == nowSool.nowLimitLength) {
			nowSool.dir = (nowSool.dir + 3) % 4;
			nowSool.nowLimitCnt++;
			nowSool.nowLength = 0;
			if (nowSool.nowLimitCnt == 2) {
				nowSool.nowLimitCnt = 0;
				nowSool.nowLimitLength--;
			}
		}
	}
}

void catch_run(int k) {
	int nx, ny;
	int cnt = 0;

	vector<Run> tmp;
	bool flag;

	for (const Run &run : arrRun) {
		flag = true;

		if (arrTree[run.p.x][run.p.y] == 1) {
			tmp.push_back(run);
			continue;
		}

		for (int i = 0; i < 3; i++) {
			nx = nowSool.p.x + dx[nowSool.dir] * i;
			ny = nowSool.p.y + dy[nowSool.dir] * i;

			if (!bound_check(nx, ny)) continue;

			if (nx == run.p.x && ny == run.p.y) {
				flag = false;
				cnt++;
				break;
			}
		}

		if (flag) {
			tmp.push_back(run);
		}
	}

	arrRun = tmp;
	result += k * cnt;
}

void simulation(int k) {
	run_move();

	sool_move();
	// vprint();
	catch_run(k);
}

int main() {
	fastio;

	input();

	for (int k = 1; k <= K; k++) {
		simulation(k);
	}

	cout << result << '\n';

	return 0;
}

void input() {
	cin >> N >> M >> H >> K;
	int a, b, c;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		a--;
		b--;
		if (c == 1) {
			arrRun.push_back({ {a, b}, 1});
		}
		else if (c == 2) {
			arrRun.push_back({ {a, b}, 2 });
		}
	}
	for (int i = 0; i < H; i++) {
		cin >> a >> b;
		arrTree[a - 1][b - 1] = 1;
	}
	nowSool = { {N / 2, N / 2}, 0, 1, 0, 0, 0 };
}

void run_move() {
	int nx, ny;
	for (Run &run : arrRun) {
		if (get_dist(run) > 3) continue;

		nx = run.p.x + dx[run.dir];
		ny = run.p.y + dy[run.dir];

		if (bound_check(nx, ny)) {
			if (nx != nowSool.p.x || ny != nowSool.p.y) {
				run.p.x = nx;
				run.p.y = ny;
			}
		}
		else {
			run.dir = (run.dir + 2) % 4;

			nx = run.p.x + dx[run.dir];
			ny = run.p.y + dy[run.dir];

			if (nx != nowSool.p.x || ny != nowSool.p.y) {
				run.p.x = nx;
				run.p.y = ny;
			}
		}
	}
}

int get_dist(Run run) {
	return abs(run.p.x - nowSool.p.x) + abs(run.p.y - nowSool.p.y);
}

bool bound_check(int x, int y) {
	return 0 <= x && x < N && 0 <= y && y < N;
}