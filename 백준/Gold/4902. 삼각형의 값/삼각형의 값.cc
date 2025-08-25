#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int MX_N = 401;
const int MX_COL = 801;

int N;
int arr[MX_N][MX_COL];
int prefixSum[MX_N][MX_COL];
int result;

void input_and_preprocess() {
    memset(arr, 0, sizeof(arr));
    memset(prefixSum, 0, sizeof(prefixSum));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 2 * i + 1; j++) {
            cin >> arr[i][j];
            if (j == 0) {
                prefixSum[i][j] = arr[i][j];
            }
			else {
                prefixSum[i][j] = prefixSum[i][j - 1] + arr[i][j];
            }
        }
    }
}

// 특정 행의 구간 합을 O(1)에 계산하는 함수
int get_row_sum(int r, int c1, int c2) {
    if (c1 > c2) return 0;
    if (c1 == 0) return prefixSum[r][c2];
    return prefixSum[r][c2] - prefixSum[r][c1 - 1];
}

void simulation() {
    result = -1e9;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 2 * i + 1; j++) {
            if (j % 2 != 0) continue;

            int current_sum = 0;
            for (int s = 1; ; s++) {
                int base_i = i + s - 1;
                if (base_i >= N) break;

                int base_start_j = j;
                int base_end_j = j + 2 * (s - 1);
                if (base_end_j > 2 * base_i) break;

                current_sum += get_row_sum(base_i, base_start_j, base_end_j);
                result = max(result, current_sum);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 2 * i + 1; j++) {
            if (j % 2 == 0) continue;

            int current_sum = 0;
            for (int s = 1; ; s++) {
                int top_i = i - (s - 1);
                if (top_i < 0) break;

                int top_start_j = j - 2 * (s - 1);
                int top_end_j = j;
                if (top_start_j < 0 || top_end_j > 2 * top_i) break;

                current_sum += get_row_sum(top_i, top_start_j, top_end_j);
                result = max(result, current_sum);
            }
        }
    }
}

int main() {
    int case_num = 1;
    while (cin >> N && N != 0) {
        input_and_preprocess();
        simulation();
        cout << case_num++ << ". " << result << '\n';
    }

    return 0;
}