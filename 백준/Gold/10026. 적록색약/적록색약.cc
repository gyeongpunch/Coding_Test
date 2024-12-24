#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int N;
vector<vector<char>> arr;
vector<vector<int>> visited;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void bfs(int x, int y, bool is_nono) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y]++;

    char current_color = arr[x][y];
    while (!q.empty()) {
        auto [cx, cy] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < N && visited[nx][ny] == visited[cx][cy] - 1) {
                if (is_nono) {
                    // 적록색약: R과 G를 동일하게 처리
                    if ((current_color == 'R' || current_color == 'G') &&
                        (arr[nx][ny] == 'R' || arr[nx][ny] == 'G')) {
                        visited[nx][ny]++;
                        q.push({nx, ny});
                    } else if (arr[nx][ny] == current_color) {
                        visited[nx][ny]++;
                        q.push({nx, ny});
                    }
                } else {
                    // 일반적인 경우: 같은 색만 연결
                    if (arr[nx][ny] == current_color) {
                        visited[nx][ny]++;
                        q.push({nx, ny});
                    }
                }
            }
        }
    }
}

int main() {
    cin >> N;
    arr = vector<vector<char>>(N, vector<char>(N, ' '));
    visited = vector<vector<int>>(N, vector<int>(N, 0));

    // 입력받기
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < N; j++) {
            arr[i][j] = str[j];
        }
    }

    int normal = 0;
    int nonormal = 0;

    // 일반적인 경우 계산
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visited[i][j] == 0) {
                bfs(i, j, false);
                normal++;
            }
        }
    }

    // 적록색약인 경우 계산
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visited[i][j] == 1) { // 일반 탐색 후 값이 1인 경우만 탐색
                bfs(i, j, true);
                nonormal++;
            }
        }
    }

    // 결과 출력
    cout << normal << ' ' << nonormal << endl;

    return 0;
}
