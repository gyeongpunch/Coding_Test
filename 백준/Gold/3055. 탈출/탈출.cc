#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <cstring>

using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(nullptr);

struct Point{
    int x, y;
};

bool operator==(Point a, Point b){
    return a.x==b.x && a.y==b.y;
}

const int MX = 50;

int N, M;
char arr[MX][MX];
int w_vst[MX][MX];
int m_vst[MX][MX];

queue<Point> wq;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

Point st, ed;

bool bound_check(int x, int y){
    return 0<=x && x<N && 0<=y && y<M;
}

void w_bfs(){
    while(!wq.empty()){
        Point now = wq.front(); wq.pop();

        for(int i=0; i<4; i++){
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if(!bound_check(nx, ny)) continue;
            if(w_vst[nx][ny]!=-1) continue;
            if(arr[nx][ny] == 'X') continue;
            if(arr[nx][ny] == 'D') continue;

            wq.push({nx, ny});
            w_vst[nx][ny] = w_vst[now.x][now.y] + 1;
        }
    }
}

int m_bfs(){
    queue<Point> q;
    q.push(st);
    memset(m_vst, -1, sizeof(m_vst));
    m_vst[st.x][st.y] = 0;

    while(!q.empty()){
        Point now = q.front(); q.pop();

        if(now == ed) return m_vst[now.x][now.y];

        for(int i=0; i<4; i++){
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if(!bound_check(nx, ny)) continue;
            if(arr[nx][ny] == 'X') continue;
            if(w_vst[nx][ny]!=-1 && m_vst[now.x][now.y]+1 >= w_vst[nx][ny]) continue;
            if(m_vst[nx][ny] != -1) continue;

            q.push({nx, ny});
            m_vst[nx][ny] = m_vst[now.x][now.y] + 1;
        }
    }
    return -1;
}

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    cin >> N >> M;
    memset(w_vst, -1, sizeof(w_vst));
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 'S') st = {i, j};
            else if(arr[i][j] == 'D') ed = {i, j};
            else if(arr[i][j] == '*') {
                wq.push({i, j});
                w_vst[i][j] = 0;
            }
        }
    }

    w_bfs();

    int result = m_bfs();
    if(result == -1) cout << "KAKTUS" << '\n';
    else cout << result << '\n';
    

    return 0;
}