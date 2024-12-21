#include <string>
#include <vector>
#include <queue>
#include <stdexcept> // 예외 처리를 위해 필요

using namespace std;

int xSize, ySize;

pair<int, int> findTarget(vector<string> maps, char target) {
    for (int x = 0; x < maps.size(); x++) {
        int y = maps[x].find(target);
        if (y != string::npos) {
            return make_pair(x, y); // x는 행, y는 열
        }
    }
    return make_pair(-1, -1); // target이 없으면 (-1, -1) 반환
}

bool indexInBound(int x, int y) {
    return 0 <= x && x < xSize && 0 <= y && y < ySize;
}

int bfs(vector<string> maps, char start, char end) {
    vector<vector<int>> visited(xSize, vector<int>(ySize, -1));
    int dx[4] = {0, 1, 0, -1}; // 위, 오른쪽, 아래, 왼쪽
    int dy[4] = {1, 0, -1, 0};

    pair<int, int> startPos = findTarget(maps, start);
    if (startPos.first == -1 || startPos.second == -1) return -1;

    queue<pair<int, int>> q;
    q.push(startPos);
    visited[startPos.first][startPos.second] = 0;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (maps[x][y] == end) {
            return visited[x][y];
        }

        for (int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (!indexInBound(nx, ny)) continue;
            if (visited[nx][ny] != -1) continue;

            if (maps[nx][ny] != 'X') {
                q.push(make_pair(nx, ny));
                visited[nx][ny] = visited[x][y] + 1;
            }
        }
    }
    return -1;
}

int solution(vector<string> maps) {
    xSize = maps.size();
    ySize = maps[0].size();

    int time1 = bfs(maps, 'S', 'L');
    int time2 = bfs(maps, 'L', 'E');

    if (time1 == -1 || time2 == -1) {
        return -1;
    }

    return time1 + time2;
}
