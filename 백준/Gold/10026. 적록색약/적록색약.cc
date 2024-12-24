#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int N;
vector<vector<char>> arr;
vector<vector<bool>> visited;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

// BFS 함수
void bfs(int x, int y, bool is_nono) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    char current_color = arr[x][y];
    while (!q.empty()) {
        auto [cx, cy] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            // 범위 체크 및 방문 여부 확인
            if (nx >= 0 && nx < N && ny >= 0 && ny < N && !visited[nx][ny]) {
                // 적록색약 여부에 따른 색상 비교
                if (is_nono) {
                    // 적록색약: R과 G를 같은 색으로 간주
                    if ((current_color == 'R' || current_color == 'G') &&
                        (arr[nx][ny] == 'R' || arr[nx][ny] == 'G')) {
                        visited[nx][ny] = true;
                        q.push({nx, ny});
                    } else if (arr[nx][ny] == current_color) {
                        visited[nx][ny] = true;
                        q.push({nx, ny});
                    }
                } else {
                    // 일반적인 경우: 같은 색만 연결
                    if (arr[nx][ny] == current_color) {
                        visited[nx][ny] = true;
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
    visited = vector<vector<bool>>(N, vector<bool>(N, false));

    // 입력받기
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < N; j++) {
            arr[i][j] = str[j];
        }
    }

    int normal = 0;    // 일반적인 경우 구역 수
    int nonormal = 0;  // 적록색약인 경우 구역 수

    // 일반적인 경우 계산
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j]) {
                bfs(i, j, false);
                normal++;
            }
        }
    }

    // 방문 배열 초기화
    visited = vector<vector<bool>>(N, vector<bool>(N, false));

    // 적록색약인 경우 계산
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j]) {
                bfs(i, j, true);
                nonormal++;
            }
        }
    }

    // 결과 출력
    cout << normal << ' ' << nonormal << endl;

    return 0;
}
