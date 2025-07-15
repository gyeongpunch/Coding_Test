#include <iostream>
#include <queue>
#include <cstring>
#include <climits>
#include <unordered_map>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

struct Point{
    int x, y;
};

const int MX = 30;

int N, M;
char arr[MX][MX];
int visited[MX][MX];
int result, emptyCnt;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void print_visited(){
    cout << "===================================\n";
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cout << visited[i][j] << ' ';
        }
        cout << '\n';
    }
    
    cout << "===================================\n\n";
}

bool bound_check(int x, int y){
    return 0<=x && x<N && 0<=y && y<M;
}

void init(){
    result = INT_MAX;
    emptyCnt = 0;
}

void input(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> arr[i][j];
            if(arr[i][j] == '.') emptyCnt++;
        }
    }
}

void dfs(int x, int y, int moveCnt, int changeCnt){
    // cout << x << ' ' << y << ' ' << changeCnt << '\n';

    if(moveCnt == emptyCnt){
        result = min(result, changeCnt);
        return;
    }

    for(int d=0; d<4; d++){
        int nx = x, ny = y;
        vector<Point> path;

        while(true){
            nx += dx[d];
            ny += dy[d];

            if(!bound_check(nx, ny)) break;
            if(arr[nx][ny] == '*') break;
            if(visited[nx][ny] != 0) break;

            visited[nx][ny] = 1;
            path.push_back({nx, ny});
        }

        if(!path.empty()){
            dfs(nx - dx[d], ny - dy[d], moveCnt + path.size(), changeCnt + 1);

            for(const Point &p : path){
                visited[p.x][p.y] = 0;
            }
        }
    }
}

void solution(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(arr[i][j] == '*') continue;
            visited[i][j] = 1;
            dfs(i, j, 1, 0);
            visited[i][j] = 0;
        }
    }
}

int main(void) {
    fastio;

    int T = 1;
    while(cin >> N >> M){
        init();
        input();
        solution();

        if(result == INT_MAX) result = -1;

        cout << "Case " << T++ << ": " << result << '\n';
    }


    return 0; 
}
