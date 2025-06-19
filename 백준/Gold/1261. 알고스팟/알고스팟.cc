#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(nullptr);

struct Point{
    int x, y;
};

const int MX = 100;

int N, M;
int arr[MX][MX];
int visited[MX][MX];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int result = 1e9;

bool bound_check(int x, int y){
    return 0<=x && x<N && 0<=y && y<M;
}

void bfs(){
    queue<Point> q;
    memset(visited, -1, sizeof(visited));
    q.push({0, 0});
    visited[0][0] = 0;

    while(!q.empty()){
        Point now = q.front(); q.pop();

        for(int i=0; i<4; i++){
            int nx=now.x+dx[i];
            int ny=now.y+dy[i];

            if(!bound_check(nx, ny)) continue;
            if(arr[nx][ny] == 0){
                if(visited[nx][ny]==-1 || visited[nx][ny]>visited[now.x][now.y]){
                    q.push({nx, ny});
                    visited[nx][ny] = visited[now.x][now.y];
                }
            }
            else if(arr[nx][ny] == 1){
                if(visited[nx][ny]==-1 || visited[nx][ny]>visited[now.x][now.y]+1){
                    q.push({nx, ny});
                    visited[nx][ny] = visited[now.x][now.y] + 1;
                }
            }
        }
    }
    result = visited[N-1][M-1];
}

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    cin >> M >> N;
    string s;
    for(int i=0; i<N; i++){
        cin >> s;
        for(int j=0; j<M; j++){
            arr[i][j] = s[j] - '0';
        }
    }

    bfs();

    cout << result << '\n';

    return 0;
}