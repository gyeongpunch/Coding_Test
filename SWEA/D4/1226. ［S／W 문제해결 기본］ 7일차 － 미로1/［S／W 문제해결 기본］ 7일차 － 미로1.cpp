#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <cstring>

using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(nullptr);

struct Point{
    int x, y;
};

const int N = 16;
int arr[N][N];
int visited[N][N];
int test;
Point st, ed;
int result;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void init(){
    memset(visited, 0, sizeof(visited));
    result = 0;
}

void input(){
    cin >> test;
    string s;
    for(int i=0; i<N; i++){
        cin >> s;
        for(int j=0; j<N; j++){
            arr[i][j] = s[j] - '0';
            if(arr[i][j] == 2) st = {i, j};
            else if (arr[i][j] == 3) ed = {i, j};
        }
    }
}

bool bound_check(int x, int y){
    return 0<=x && x<N && 0<=y && y<N;
}

void solution(){
    queue<Point> q;
    q.push(st);
    visited[st.x][st.y] = 1;

    Point now;
    int nx, ny;

    while(!q.empty()){
        now = q.front(); q.pop();

        if(now.x==ed.x && now.y==ed.y){
            result = 1;
            return;
        }

        for(int i=0; i<4; i++){
            nx=now.x+dx[i];
            ny=now.y+dy[i];

            if(!bound_check(nx, ny)) continue;
            if(visited[nx][ny] == 1) continue;
            if(arr[nx][ny] == 1) continue;

            q.push({nx, ny});
            visited[nx][ny] = 1;
        }
    }
}

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    int T = 10;
    for(int t=1; t<=T; t++){    
        init();
        input();
        solution();

        cout << '#' << test << ' ' << result << '\n';
    }

    return 0;
}