#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define MAX_N 10

struct Point {
	int x, y;
};

void input();
bool bound_check(int x, int y);
bool can_go(int x, int y);
int get_dist(const Point &p);

int N, M, K;
int arr[MAX_N][MAX_N];
int arrTmp[MAX_N][MAX_N];
vector<Point> runner;
Point Exit;
int result = 0;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
Point minP, maxP;


void runner_move() {
	vector<Point> tmp;
	bool flag;
	int nx, ny;
	for (const Point &p : runner) {
		flag = true;
		
		int nowDist = get_dist(p);

		for (int i = 0; i < 4; i++) {
			nx = p.x + dx[i];
			ny = p.y + dy[i];

			if (!can_go(nx, ny)) continue;

			int nextDist = get_dist({ nx, ny });
			if (nextDist == 0) {
				result++;
				flag = false;
				break;
			}
			else if (nextDist < nowDist) {
				tmp.push_back({ nx, ny });
				result++;
				flag = false;

				minP.x = min(minP.x, nx);
				minP.y = min(minP.y, ny);
				maxP.x = max(maxP.x, nx);
				maxP.y = max(maxP.y, ny);
				
				break;
			}
		}

		if (flag) {
			tmp.push_back(p);

			minP.x = min(minP.x, p.x);
			minP.y = min(minP.y, p.y);
			maxP.x = max(maxP.x, p.x);
			maxP.y = max(maxP.y, p.y);
		}
	}
	runner = tmp;
}

bool is_bound_in(int sz, int x, int y, const Point &p) {
	if (p.x < x) return false;
	if (p.y < y) return false;
	if (p.x > x + sz - 1) return false;
	if (p.y > y + sz - 1)return false;

	return true;
}

bool is_okay(int sz, int x, int y) {
	if (!is_bound_in(sz, x, y, Exit)) return false;

	for (const Point &p : runner) {
		if (!is_bound_in(sz, x, y, p)) return false;
	}
}

void rotate(int sz, int x, int y) {
	for (int i = 0; i < sz; i++) {
		for (int j = 0; j < sz; j++) {
			arrTmp[x + j][y + sz - i - 1] = max(arr[x + i][y + j] - 1, 0);
		}
	}

	for (int i = 0; i < sz; i++) {
		for (int j = 0; j < sz; j++) {
			arr[x + i][y + j] = arrTmp[x + i][y + j];
		}
	}

	for (Point &p : runner) {

	}

}

void find_min_sq() {
	for (int sz = 1; sz <= N; sz++) {
		for (int x = 0; x < N; x++) {
			for (int y = 0; y < N; y++) {
				if (is_okay(sz, x, y)) {
					rotate(sz, x, y);
					return;
				}
			}
		}
	}
}

void simulation() {
	minP = Exit;
	maxP = Exit;

	runner_move();

	if (runner.empty()) return;

	find_min_sq();
}

int main() {
	fastio;

	input();

	for (int k = 0; k < K; k++) {
		simulation();
		if (runner.empty()) return;
	}

	cout << result << '\n';
	cout << Exit.x << ' ' << Exit.y << '\n';

	return 0;
}

bool can_go(int x, int y) {
	return bound_check(x, y) && arr[x][y] == 0;
}

int get_dist(const Point &p) {
	return abs(p.x - Exit.x) + abs(p.y - Exit.y);
}

bool bound_check(int x, int y) {
	return 0 <= x && x < N && 0 <= y && y < N;
}

void input() {
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			arrTmp[i][j] = arr[i][j];
		}
	}
	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		runner.push_back({ a - 1, b - 1 });
	}
	cin >> a >> b;
	Exit = { a - 1, b - 1 };
}