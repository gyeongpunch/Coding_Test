#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define MAX_L 40
#define MAX_N 30
struct Knight {
	int x, y, h, w, k;
};

int L, N, Q;
int arr[MAX_L][MAX_L];
int arrKnight[MAX_L][MAX_L];
Knight knight[MAX_N + 1];
int damage[MAX_N];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int result = 0;
int is_moveList[MAX_N + 1];
int is_availMove[MAX_N + 1];
int is_hurtList[MAX_N + 1];

bool bound_check(int x, int y) {
	return 0 <= x && x < L && 0 <= y && y < L;
}

void calc_result() {
	for (int i = 1; i <= N; i++) {
		if (damage[i] >= knight[i].k) continue;
		result += damage[i];
	}
}

void push_knight(int idx, int dir) {
	Knight now = knight[idx];

	int nx = now.x + dx[dir];
	int ny = now.y + dy[dir];

	for (int x = nx; x < nx + now.h; x++) {
		for (int y = ny; y < ny + now.w; y++) {
			
			if (!bound_check(x, y)) return;
			if (arr[x][y] == 2) return;

			if (arrKnight[x][y] != 0 && idx != arrKnight[x][y]) {
				is_moveList[arrKnight[x][y]] = 1;
				is_hurtList[arrKnight[x][y]] = 1;
				push_knight(arrKnight[x][y], dir);
			}

		}
	}
	is_availMove[idx] = 1;
}

void simulation(int idx, int dir) {
	is_moveList[idx] = 1;
	push_knight(idx, dir);

	for (int i = 1; i <= N; i++) {
		if (is_moveList[i] == 1 && is_availMove[i] == 0) {
			return;
		}
	}

	for (int i = 1; i <= N; i++) {
		if (is_moveList[i] == 0) continue;

		Knight now = knight[i];
		
		for (int x = now.x; x < now.x + now.h; x++) {
			for (int y = now.y; y < now.y + now.w; y++) {
				arrKnight[x][y] = 0;
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		if (is_moveList[i] == 0) continue;

		Knight &now = knight[i];

		now.x += dx[dir];
		now.y += dy[dir];

		for (int x = now.x; x < now.x + now.h; x++) {
			for (int y = now.y; y < now.y + now.w; y++) {
				arrKnight[x][y] = i;

				if (is_hurtList[i] == 1 && arr[x][y] == 1) {
					damage[i]++;
				}
			}
		}

		if (damage[i] >= now.k) {
			for (int x = now.x; x < now.x + now.h; x++) {
				for (int y = now.y; y < now.y + now.w; y++) {
					arrKnight[x][y] = 0;
				}
			}
		}
	}
}

int main(void) {
	fastio;

	cin >> L >> N >> Q;
	for (int i = 0; i < L; i++) {
		for (int j = 0; j < L; j++) {
			cin >> arr[i][j];
		}
	}

	int r, c, h, w, k;
	for (int i = 1; i <= N; i++) {
		cin >> r >> c >> h >> w >> k;

		knight[i] = { r-1, c-1, h, w, k };

		for (int x = r-1; x < r-1 + h; x++) {
			for (int y = c-1; y < c-1 + w; y++) {
				arrKnight[x][y] = i;
			}
		}
	}
	int idx, d;
	for (int i = 0; i < Q; i++) {
		cin >> idx >> d;

		if (damage[idx] >= knight[idx].k) continue;

		memset(is_moveList, 0, sizeof(is_moveList));
		memset(is_availMove, 0, sizeof(is_availMove));
		memset(is_hurtList, 0, sizeof(is_hurtList));

		simulation(idx, d);
	}
	
	calc_result();

	cout << result << '\n';


	return 0;
}