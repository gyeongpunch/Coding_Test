#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>

using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);


struct Point {
	int x, y;
};

struct Snake {
	queue<Point> q;
	int dir;
};

struct Move {
	int time;
	char dir;
};

const int MAX_N = 100;

int N, K;
int arr[MAX_N][MAX_N];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
vector<Move> movee;
Snake cur;
int result = 0;

bool bound_check(int x, int y) {
	return 0 <= x && x < N && 0 <= y && y < N;
}

void pprint() {
	cout << "===========================\n";
	cout << "now time: " << result << '\n';
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << "===========================\n";
}

int main(void) {
	fastio;

	cin >> N >> K;
	int x, y;
	for (int i = 0; i < K; i++) {
		cin >> x >> y;
		arr[x-1][y-1] = 2;
	}

	arr[0][0] = 1;
	cur.q.push({ 0, 0 });
	cur.dir = 1;
	
	int L, t;
	char d;

	cin >> L;
	for (int i = 0; i < L; i++) {
		cin >> t >> d;
		movee.push_back({ t, d });
	}

	
	int moveIdx = 0;

	int nx, ny;
	while (true) {
		if (moveIdx < L && movee[moveIdx].time == result) {
			if (movee[moveIdx].dir == 'D') {
				cur.dir = (cur.dir + 1) % 4;
			}
			else if (movee[moveIdx].dir == 'L') {
				cur.dir = (cur.dir + 3) % 4;
			}
			moveIdx++;
		}

		nx = cur.q.back().x + dx[cur.dir];
		ny = cur.q.back().y + dy[cur.dir];

		if (!bound_check(nx, ny)) break;
		if (arr[nx][ny] == 1) break;

		if (arr[nx][ny] == 0) {
			arr[cur.q.front().x][cur.q.front().y] = 0;
			cur.q.pop();
		}
		cur.q.push({ nx, ny });
		arr[nx][ny] = 1;

		result++;
	}

	cout << result + 1 << '\n';

	return 0;
}