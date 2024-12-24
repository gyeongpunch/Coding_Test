#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void f_bfs(int N, int M, const vector<string>& arr, vector<vector<int>>& f_v, queue<pair<int, int>>& f_loc) {
    while (!f_loc.empty()) {
        auto [x, y] = f_loc.front();
        f_loc.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < N && ny >= 0 && ny < M && arr[nx][ny] != '#' && f_v[nx][ny] == -1) {
                f_v[nx][ny] = f_v[x][y] + 1;
                f_loc.push({nx, ny});
            }
        }
    }
}

int s_bfs(int N, int M, const vector<string>& arr, const vector<vector<int>>& f_v, vector<vector<int>>& s_v, queue<pair<int, int>>& s_loc) {
    while (!s_loc.empty()) {
        auto [x, y] = s_loc.front();
        s_loc.pop();

        // 탈출 조건: 상근이가 테두리에 도달
        if (x == 0 || x == N - 1 || y == 0 || y == M - 1) {
            return s_v[x][y] + 1;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < N && ny >= 0 && ny < M && arr[nx][ny] != '#' &&
                s_v[nx][ny] == -1 && (f_v[nx][ny] == -1 || f_v[nx][ny] > s_v[x][y] + 1)) {
                s_v[nx][ny] = s_v[x][y] + 1;
                s_loc.push({nx, ny});
            }
        }
    }
    return -1; // 탈출 불가능
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int M, N;
        cin >> M >> N;

        vector<string> arr(N);
        vector<vector<int>> f_v(N, vector<int>(M, -1));
        vector<vector<int>> s_v(N, vector<int>(M, -1));
        queue<pair<int, int>> f_loc;
        queue<pair<int, int>> s_loc;

        for (int i = 0; i < N; i++) {
            cin >> arr[i];
            for (int j = 0; j < M; j++) {
                if (arr[i][j] == '*') {
                    f_loc.push({i, j});
                    f_v[i][j] = 0;
                } else if (arr[i][j] == '@') {
                    s_loc.push({i, j});
                    s_v[i][j] = 0;
                }
            }
        }

        f_bfs(N, M, arr, f_v, f_loc);
        int result = s_bfs(N, M, arr, f_v, s_v, s_loc);

        if (result == -1) {
            cout << "IMPOSSIBLE" << endl;
        } else {
            cout << result << endl;
        }
    }

    return 0;
}
