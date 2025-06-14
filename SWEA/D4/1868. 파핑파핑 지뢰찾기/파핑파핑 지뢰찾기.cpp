#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <cstring>
#include <stack>

using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(nullptr);

struct Point{
    int x, y;
};

const int MX = 300;

int N;
char arr[MX][MX];
int visited[MX][MX];
int result;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int ddx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int ddy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

void init(){
    memset(visited, 0, sizeof(visited));
    result = 0;
}

void input(){
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> arr[i][j];
        }
    }
}

bool bound_check(int x, int y){
    return 0<=x && x<N && 0<=y && y<N;
}

bool check_zero(int x, int y){
    int nx, ny;
    for(int i=0; i<8; i++){
        nx=x+ddx[i];
        ny=y+ddy[i];
        if(!bound_check(nx, ny)) continue;
        if(arr[nx][ny] == '*') return false;
    }
    return true;
}

void bfs(int x, int y){
    queue<Point> q;
    q.push({x, y});
    visited[x][y] = 1;

    Point now;
    int nx, ny;
    while(!q.empty()){
        now = q.front(); q.pop();

        for(int i=0; i<8; i++){
            nx=now.x+ddx[i];
            ny=now.y+ddy[i];

            if(!bound_check(nx, ny)) continue;
            if(visited[nx][ny] == 1) continue;
            if(arr[nx][ny]=='*') continue;

            visited[nx][ny] = 1;
            if(check_zero(nx, ny)){
                q.push({nx, ny});
            }
        }
    }
}

void solution(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(arr[i][j] == '*') continue;
            if(visited[i][j] == 1) continue;
            if(!check_zero(i, j)) continue;

            bfs(i, j);
            result++;
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(arr[i][j]=='.' && visited[i][j]==0){
                result++;
            }
        }
    }
}

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    int T;
    cin >> T;
    for(int t=1; t<=T; t++){    
        input();
        init();
        solution();

        cout << '#' << t << ' ' << result << '\n';
    }

    return 0;
}