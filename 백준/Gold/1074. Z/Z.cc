#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <cmath>

using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

int N, r, c;
int result = 0;
int depth = 0;
bool flag = false;

void recur(int sx, int sy, int ex, int ey) {
	if (ex - sx == 1 && ey - sy == 1) {
		for (int i = sx; i <= ex; i++) {
			for (int j = sy; j <= ey; j++) {
				if (i == r && j == c) return;
				result++;
			}
		}
		return;
	}

	int mx = (ex + sx) / 2;
	int my = (ey + sy) / 2;

	if (r <= mx && c <= my) {
		recur(sx, sy, mx, my); 
	}
	else if (r <= mx && c > my) {
		result += ((ex - sx + 1) / 2) * ((ex - sx + 1) / 2);
		recur(sx, my+1, mx, ey);
	}
	else if (r > mx && c <= my) {
		result += ((ex - sx + 1) / 2) * ((ex - sx + 1) / 2) * 2;
		recur(mx + 1, sy, ex, my);
	}
	else if (r > mx && c > my) {
		result += ((ex - sx + 1) / 2) * ((ex - sx + 1) / 2) * 3;
		recur(mx + 1, my + 1, ex, ey);
	}
}

int main(void) {
	fastio;

	cin >> N >> r >> c;
	recur(0, 0, pow(2, N) - 1, pow(2, N) - 1);

	cout << result << '\n';

	return 0;
}