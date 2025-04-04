#include <iostream>
#include <cmath>
#include <unordered_set>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cin.tie(nullptr);
#define MAX_N 20

int N;
unordered_set<int> favList[MAX_N * MAX_N+ 1];
int arr[MAX_N][MAX_N];
int result = 0;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

struct Info {
	int maxCnt;
	int emptyCnt;
	int x;
	int y;
};

bool bound_check(int x, int y) {
	return 0 <= x && x < N && 0 <= y && y < N;
}

void pprint() {
	cout << "=======================\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << "=======================\n";
}

void simulation(int n) {
	Info info = { -1, -1, 0, 0 };

	int nx, ny;
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			if (arr[x][y] != 0) continue;

			int nowCnt = 0;
			int nowEmptyCnt = 0;

			for (int i = 0; i < 4; i++) {
				nx = x + dx[i];
				ny = y + dy[i];

				if (!bound_check(nx, ny)) continue;

				if (arr[nx][ny] == 0) {
					nowEmptyCnt++;
				}
				else {
					if (favList[n].count(arr[nx][ny])) {
						nowCnt++;
					}
				}
			}

			if (nowCnt > info.maxCnt) {
				info.maxCnt = nowCnt;
				info.emptyCnt = nowEmptyCnt;
				info.x = x;
				info.y = y;
			}
			else if (nowCnt == info.maxCnt && nowEmptyCnt > info.emptyCnt) {
				info.maxCnt = nowCnt;
				info.emptyCnt = nowEmptyCnt;
				info.x = x;
				info.y = y;
			}
		}
	}

	arr[info.x][info.y] = n;
}

void calc() {
	int nx, ny;
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			int cnt = 0;
			for (int i = 0; i < 4; i++) {
				nx = x + dx[i];
				ny = y + dy[i];

				if (!bound_check(nx, ny)) continue;

				if (favList[arr[x][y]].count(arr[nx][ny])) {
					cnt++;
				}
			}
			// cout << cnt << '\n';
			if (cnt > 0) {
				result += pow(10, cnt - 1);
			}

		}
	}

}

int main() {
	fastio;

	cin >> N;
	int n, f;
	for (int i = 0; i < N*N; i++) {
		cin >> n;
		for (int j = 0; j < 4; j++) {
			cin >> f;
			favList[n].insert(f);
		}
		simulation(n);
	}

	// pprint();
	calc();

	cout << result << '\n';

	return 0;
}