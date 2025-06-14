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

const int N = 100;

char arr[N][N];
int visited[N][N];
int result;
Point s, e;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void init(){
    result = 0;
    memset(visited, 0, sizeof(visited));
}

void input(){
    int n;
    cin >> n;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> arr[i][j];
            if(arr[i][j] == '2'){
                s = {i, j};
            }
            else if(arr[i][j] == '3'){
                e = {i, j};
            }
        }
    }
}

bool bound_check(int x, int y){
    return 0<=x && x<N && 0<=y && y<N;
}

void solution(){
    queue<Point> q;
    q.push(s);
    visited[s.x][s.y] = 1;

    Point now;
    int nx, ny;

    while(!q.empty()){
        now = q.front(); q.pop();

        if(now.x==e.x && now.y==e.y){
            result = 1;
            return;
        }

        for(int i=0; i<4; i++){
            nx = now.x+dx[i];
            ny = now.y+dy[i];

            if(!bound_check(nx, ny)) continue;
            if(arr[nx][ny] == '1') continue;
            if(visited[nx][ny] == 1) continue;

            q.push({nx, ny});
            visited[nx][ny] = 1;
        }
    }
}

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    int T=10;
    for(int t=1; t<=T; t++){    
        init();
        input();
        solution();

        cout << '#' << t << ' ' << result << '\n';
    }

    return 0;
}