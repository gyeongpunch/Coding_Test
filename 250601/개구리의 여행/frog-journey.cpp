#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

struct Point{
    int x, y;
};

struct Node{
    Point p;
    int time, jump;

    bool operator<(const Node& other) const{
        return time > other.time;
    }
};

const int MAX_SZ = 50;

int N, Q, result;
char arr[MAX_SZ][MAX_SZ];
int visited[MAX_SZ][MAX_SZ][6];
Point start, End;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void init_input(){
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> arr[i][j];
        }
    }
    cin >> Q;
}
void input(){
    cin >> start.x >> start.y >> End.x >> End.y;
    start.x--;  
    start.y--;
    End.x--;   
    End.y--;
}
void init(){
    result = 1e9;
    memset(visited, -1, sizeof(visited));
}
bool bound_check(int x, int y){
    return 0<=x && x<N && 0<=y && y<N;
}

void solution() {
    priority_queue<Node> pq;
    // (start.x, start.y)에서 time=0, jump=1로 시작
    pq.push({{start.x, start.y}, 0, 1});

    while (!pq.empty()) {
        Node node = pq.top();
        pq.pop();
        int cx = node.p.x;
        int cy = node.p.y;
        int nowTime = node.time;
        int nowJump = node.jump;

        // 1) 아직 방문 기록이 없거나, 더 짧은 경로가 발견되었을 때만 진행
        if (visited[cx][cy][nowJump] != -1 && visited[cx][cy][nowJump] < nowTime) {
            continue;
        }
        if (visited[cx][cy][nowJump] == -1) {
            visited[cx][cy][nowJump] = nowTime;
        }

        // 2) 목표 지점 도달 시, 첫 번째로 꺼낸 nowTime이 최단이므로 바로 result에 기록하고 break
        if (cx == End.x && cy == End.y) {
            result = nowTime;
            break;
        }

        // 3) 만약 nowTime이 이미 result 이상이라면 더 탐색할 필요 없음 → break
        if (nowTime >= result) {
            break;
        }

        // 4) jump 이동
        for (int dir = 0; dir < 4; dir++) {
            int nx = cx + dx[dir] * nowJump;
            int ny = cy + dy[dir] * nowJump;
            if (!bound_check(nx, ny)) continue;
            // 착지는 오직 '.'만 허용
            if (arr[nx][ny] != '.') continue;
            // 중간 경로에 '#'이 있으면 불가
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
            if (visited[nx][ny][nowJump] == -1 
             || visited[nx][ny][nowJump] > nextTime) {
                pq.push({{nx, ny}, nextTime, nowJump});
            }
        }

        // 5) 점프력 증가
        if (nowJump < 5) {
            int newJump = nowJump + 1;
            int newTime = nowTime + newJump * newJump;
            if (visited[cx][cy][newJump] == -1 
             || visited[cx][cy][newJump] > newTime) {
                pq.push({{cx, cy}, newTime, newJump});
            }
        }

        // 6) 점프력 감소
        for (int newJump = 1; newJump < nowJump; newJump++) {
            int newTime = nowTime + 1;
            if (visited[cx][cy][newJump] == -1 
             || visited[cx][cy][newJump] > newTime) {
                pq.push({{cx, cy}, newTime, newJump});
            }
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init_input();
    
    for(int i=0; i<Q; i++){
        input();
        init();
        solution();

        if(result == 1e9){
            cout << -1 << '\n';
        }
        else{
            cout << result << '\n';
        }
    }
    
    return 0;
}