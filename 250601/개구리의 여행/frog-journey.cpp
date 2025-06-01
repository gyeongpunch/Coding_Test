#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

struct Point {
    int x, y;
};

struct Node {
    Point p;
    int time, jump;
    bool operator<(const Node& other) const {
        return time > other.time; 
    }
};

static const int MAX_SZ = 50;
int N, Q, result;
char arr[MAX_SZ][MAX_SZ];
int visited[MAX_SZ][MAX_SZ][6];
Point start, End;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = {  0, -1, 0, 1 };

void init_input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }
    cin >> Q;
}

void input() {
    cin >> start.x >> start.y >> End.x >> End.y;
    start.x--;  start.y--;
    End.x--;    End.y--;
}

void init() {
    result = 1e9;
    memset(visited, -1, sizeof(visited));
}

inline bool bound_check(int x, int y) {
    return (0 <= x && x < N && 0 <= y && y < N);
}

void solution() {
    priority_queue<Node> pq;
    pq.push({ { start.x, start.y }, 0, 1 });

    while (!pq.empty()) {
        Node node = pq.top();
        pq.pop();
        int cx = node.p.x;
        int cy = node.p.y;
        int nowTime = node.time;
        int nowJump = node.jump;

        // 1) pop 시점에 '방문한 적이 있으면' 즉시 skip
        if (visited[cx][cy][nowJump] != -1) 
            continue;

        // 2) '방문 기록'이 아직 없으면 이 순간이 최단 시간
        visited[cx][cy][nowJump] = nowTime;

        // 3) 목표 지점 도달 → 최단 시간 확정 → 즉시 return
        if (cx == End.x && cy == End.y) {
            result = nowTime;
            return;
        }

        // 4) jump 이동 (거리 = nowJump, 비용 +1)
        for (int dir = 0; dir < 4; dir++) {
            int nx = cx + dx[dir] * nowJump;
            int ny = cy + dy[dir] * nowJump;
            if (!bound_check(nx, ny)) continue;
            // 착지는 오직 '.'만 허용
            if (arr[nx][ny] != '.') continue;

            bool blocked = false;
            for (int step = 1; step < nowJump; step++) {
                int tx = cx + dx[dir] * step;
                int ty = cy + dy[dir] * step;
                if (arr[tx][ty] == '#') {
                    blocked = true;
                    break;
                }
            }
            if (blocked) continue;

            int nextTime = nowTime + 1;
            if (visited[nx][ny][nowJump] == -1) {
                pq.push({{nx, ny}, nextTime, nowJump});
            }
        }

        // 5) 점프력 증가 (newJump = nowJump+1, 비용 = newJump^2)
        if (nowJump < 5) {
            int newJump = nowJump + 1;
            int newTime = nowTime + newJump * newJump;
            if (visited[cx][cy][newJump] == -1) {
                pq.push({{cx, cy}, newTime, newJump});
            }
        }

        // 6) 점프력 감소 (newJump = 1..nowJump-1, 비용 +1)
        for (int newJump = 1; newJump < nowJump; newJump++) {
            int newTime = nowTime + 1;
            if (visited[cx][cy][newJump] == -1) {
                pq.push({{cx, cy}, newTime, newJump});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init_input();
    for (int i = 0; i < Q; i++) {
        input();
        init();
        solution();

        if (result == 1e9)
            cout << -1 << '\n';
        else
            cout << result << '\n';
    }
    return 0;
}
