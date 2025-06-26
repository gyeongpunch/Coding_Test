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
#include <iomanip>

using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(nullptr);

struct Info{
    int x, y, d, c;
};

struct Point{
    int x, y;
};

const int MX = 100;
int N, M;
char arr[MX][MX];
int visited[MX][MX][4];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int dir[2] = {1, 3};

bool bound_check(int x, int y){
    return 0<=x && x<N && 0<=y && y<M;
}

Point st={-1, -1}, ed={-1, -1};

int bfs(){
    memset(visited, -1, sizeof(visited));
    deque<Info> dq;
    for(int i=0; i<4; i++){
        dq.push_back({st.x, st.y, i, 0});
        visited[st.x][st.y][i] = 0;
    }

    while(!dq.empty()){
        Info now = dq.front(); dq.pop_front();

        int nx = now.x + dx[now.d];
        int ny = now.y + dy[now.d];
        int nd = now.d;
        int nc = now.c;

        if(bound_check(nx, ny) && arr[nx][ny] != '*'){
            if(visited[nx][ny][nd]==-1 || visited[nx][ny][nd] > nc){
                dq.push_front({nx, ny, nd, nc});
                visited[nx][ny][nd] = nc;
            }
        }

        for(int d=0; d<2; d++){
            nd = (now.d + dir[d]) % 4;
            nx=now.x+dx[nd];
            ny=now.y+dy[nd];
            nc = now.c+1;
            
            if(!bound_check(nx, ny)) continue;
            if(arr[nx][ny] == '*') continue;
            if(visited[nx][ny][nd] == -1 || visited[nx][ny][nd] > nc){
                dq.push_back({nx, ny, nd, nc});
                visited[nx][ny][nd] = nc;
            }
        }
    }
    int mn = 1e9;
    for(int i=0; i<4; i++){
        if(visited[ed.x][ed.y][i] == -1) continue;
        mn=min(mn, visited[ed.x][ed.y][i]);
    }

    return mn;
}

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    cin >> M >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 'C'){
                if(st.x==-1 && st.y==-1) {
                    arr[i][j]='.', st={i, j};
                }
                else {
                    arr[i][j]='.', ed={i, j};
                }
            }
        }
    }

    int result = bfs();

    cout << result << '\n';        

    return 0;
}