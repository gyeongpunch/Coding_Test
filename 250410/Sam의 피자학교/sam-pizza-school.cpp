#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define MAX_N 100

struct Point {
	int idx;
	int x, y;
};

int N, K;
int arr[MAX_N];
Point arrLoc[MAX_N];
int arrTmp[MAX_N];
int result = 0;

void add_mill() {
	int min = 1e9;
	for (int i = 0; i < N; i++) {
		if (arr[i] < min) {
			min = arr[i];
		}
	}
	for (int i = 0; i < N; i++) {
		if (arr[i] == min) {
			arr[i]++;
		}
	}
}

void rotate(int idx, int rows, int cols) {
	for (int i = 0; i < idx; i++) {
		arrLoc[i] = { arrLoc[i].idx, arrLoc[i].y, rows - arrLoc[i].x - 1 };
	}
}

void roll() {
	arrLoc[0] = { 0, 0, 0 };
	arrLoc[1] = { 1, 1, 0 };
	int rows = 2, cols = 1;
	int idx = 2;

	while (idx + rows <= N) {
		rotate(idx, rows, cols);

		for (int i = 0; i < rows; i++) {
			arrLoc[i + idx] = { i+idx, cols, i };
		}
		idx += rows;

		if (rows == cols + 1) {
			cols++;
		}
		else {
			rows++;
		}
	}

	for (int i = idx; i < N; i++) {
		arrLoc[i] = { i, rows - 1, cols + i - idx };
	}
}

bool is_over() {
	int mx = -1;
	int mn = 1e9;

	for (int i = 0; i < N; i++) {
		mx = max(mx, arr[i]);
		mn = min(mn, arr[i]);
	}

	return abs(mx - mn) <= K;
}

bool is_near(int idx1, int idx2) {
	return abs(arrLoc[idx1].x - arrLoc[idx2].x) + abs(arrLoc[idx1].y - arrLoc[idx2].y) == 1;
}

bool custom_compare(Point a, Point b) {
	if (a.y == b.y) return a.x > b.x;
	return a.y < b.y;
}

void ggook() {
	for (int i = 0; i < N; i++) {
		arrTmp[i] = arr[i];
	}

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (is_near(i, j)) {
				int d = abs(arr[i] - arr[j]) / 5;

				if (arr[i] > arr[j]) {
					arrTmp[i] -= d;
					arrTmp[j] += d;
				}
				else {
					arrTmp[j] -= d;
					arrTmp[i] += d;
				}
			}
		}
	}

	sort(arrLoc, arrLoc + N, custom_compare);

	for (int i = 0; i < N; i++) {
		arr[i] = arrTmp[arrLoc[i].idx];
	}
}

void fold_rotate(int idx, int rows, int cols) {
	for (int i = 0; i < N; i++) {
		if (0 <= arrLoc[i].y && arrLoc[i].y < cols / 2) {
			arrLoc[i] = { arrLoc[i].idx, rows - arrLoc[i].x - 1, cols/2 - arrLoc[i].y - 1 };
		}
		else {
			arrLoc[i] = { arrLoc[i].idx, rows + arrLoc[i].x, arrLoc[i].y - cols / 2 };
		}
	}
}

void twice_half() {
	int rows = 1, cols = N;
	int idx = N / 2;

	for (int i = 0; i < N; i++) {
		arrLoc[i] = { i, 0, i };
	}

	for (int t = 0; t < 2; t++) {
		fold_rotate(idx, rows, cols);
		rows *= 2;
		cols /= 2;
	}
}

int main(void) {
	fastio;

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	while (!is_over()) {
		add_mill();

		roll();

		ggook();

		twice_half();

		ggook();

		result++;
	}

	cout << result << '\n';

	return 0;
}