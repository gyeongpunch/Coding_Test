#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 5;
const int M = 300;

int arr[N][N];
int arrTmp[N][N];
int visited[N][N];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int newNum[M];
int newNumIdx = 0;

struct Point {
    int x, y;
};

struct Info {
    int value = -1;
    int rCnt, cx, cy;
};

Info maxInfo;
int result;
bool resultFlag;
vector<Point> bombTotal;

bool in_range(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

void rotate(int x, int y) {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            arrTmp[x + j][y + 3 - i - 1] = arr[x + i][y + j];

    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            arr[x + i][y + j] = arrTmp[x + i][y + j];
}

int bfs(int x, int y) {
    queue<Point> q;
    q.push({x, y});
    visited[x][y] = 1;
    int cnt = 1;

    while (!q.empty()) {
        Point cur = q.front(); q.pop();
        for (int dir = 0; dir < 4; ++dir) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            if (!in_range(nx, ny) || visited[nx][ny]) continue;
            if (arr[nx][ny] != arr[x][y]) continue;
            visited[nx][ny] = 1;
            q.push({nx, ny});
            ++cnt;
        }
    }
    return cnt >= 3 ? cnt : 0;
}

void get_one_max(int x, int y, int rCnt) {
    memset(visited, 0, sizeof(visited));
    int sum = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (!visited[i][j]) sum += bfs(i, j);

    if (maxInfo.value < sum) {
        maxInfo = {sum, rCnt, x + 1, y + 1};
    } else if (maxInfo.value == sum) {
        if (maxInfo.rCnt > rCnt || (maxInfo.rCnt == rCnt && (maxInfo.cy > y + 1 || (maxInfo.cy == y + 1 && maxInfo.cx > x + 1)))) {
            maxInfo = {sum, rCnt, x + 1, y + 1};
        }
    }
}

void get_max_rotate() {
    // int backup[N][N];
    // memcpy(backup, arr, sizeof(arr));

    for (int x = 0; x <= 2; ++x) {
        for (int y = 0; y <= 2; ++y) {
            for (int r = 1; r <= 4; ++r) {
                rotate(x, y);
                get_one_max(x, y, r);
            }
            // memcpy(arr, backup, sizeof(arr));
        }
    }
}

int bfs2(int x, int y) {
    queue<Point> q;
    vector<Point> trace;
    q.push({x, y});
    visited[x][y] = 1;
    trace.push_back({x, y});

    while (!q.empty()) {
        Point cur = q.front(); q.pop();
        for (int dir = 0; dir < 4; ++dir) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            if (!in_range(nx, ny) || visited[nx][ny]) continue;
            if (arr[nx][ny] != arr[x][y]) continue;
            visited[nx][ny] = 1;
            q.push({nx, ny});
            trace.push_back({nx, ny});
        }
    }

    if (trace.size() >= 3) {
        for (auto &p : trace) arr[p.x][p.y] = 0;
        return trace.size();
    }
    return 0;
}

bool bomb() {
    memset(visited, 0, sizeof(visited));
    int cnt = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (!visited[i][j]) cnt += bfs2(i, j);
    result += cnt;
    return cnt > 0;
}

void fill_new() {
    for (int j = 0; j < N; ++j)
        for (int i = N - 1; i >= 0; --i)
            if (arr[i][j] == 0) arr[i][j] = newNum[newNumIdx++];
}

void simulation() {
    maxInfo = {-1, 0, 0, 0};
    get_max_rotate();
    if (maxInfo.value == 0) {
        resultFlag = false;
        return;
    }

    for (int i = 0; i < maxInfo.rCnt; ++i)
        rotate(maxInfo.cx - 1, maxInfo.cy - 1);

    bomb();
    fill_new();
    while (bomb()) fill_new();
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int K, M;
    cin >> K >> M;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> arr[i][j];

    for (int i = 0; i < M; ++i)
        cin >> newNum[i];

    for (int k = 0; k < K; ++k) {
        result = 0;
        resultFlag = true;
        simulation();
        if (!resultFlag) break;
        cout << result << " ";
    }

    return 0;
}

