#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
int x, y, a, b;

// 방향 배열: 상하좌우
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

// 방의 스위치 연결 상태
vector<vector<vector<pair<int, int>>>> total_room;

// 방문 여부 및 불이 켜진 상태
vector<vector<int>> visited, light_on;

int bfs() {
    int cnt = 1; // (1, 1)은 항상 불이 켜져 있으므로 카운트 시작
    visited[0][0] = 1; 
    light_on[0][0] = 1;

    queue<pair<int, int>> q;
    q.push({0, 0});

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        // 현재 방에서 스위치를 통해 다른 방의 불을 켜기
        while (!total_room[x][y].empty()) {
            auto [target_x, target_y] = total_room[x][y].back();
            total_room[x][y].pop_back();

            // 불이 꺼져 있던 방이라면 불을 켜고, 이동 가능 여부를 판단
            if (!light_on[target_x][target_y]) {
                light_on[target_x][target_y] = 1;
                cnt++;

                // 해당 방에 이미 방문 가능한 조건(인접한 방문한 방)이 있으면 큐에 추가
                for (int i = 0; i < 4; i++) {
                    int nx = target_x + dx[i];
                    int ny = target_y + dy[i];
                    if (nx >= 0 && nx < N && ny >= 0 && ny < N && visited[nx][ny]) {
                        q.push({target_x, target_y});
                        visited[target_x][target_y] = 1;
                        break;
                    }
                }
            }
        }

        // 상하좌우 이동
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < N && !visited[nx][ny] && light_on[nx][ny]) {
                visited[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }

    return cnt;
}

int main() {
    cin >> N >> M;

    // 초기화
    total_room = vector<vector<vector<pair<int, int>>>>(N, vector<vector<pair<int, int>>>(N));
    visited = vector<vector<int>>(N, vector<int>(N, 0));
    light_on = vector<vector<int>>(N, vector<int>(N, 0));

    // 스위치 정보 입력
    while (M--) {
        cin >> x >> y >> a >> b;
        total_room[x - 1][y - 1].push_back({a - 1, b - 1});
    }

    int result = bfs();

    cout << result << '\n';

    return 0;
}
