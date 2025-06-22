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

const int MX = 10;

int N, M;
Point arr[MX][MX];
int visited[MX][MX];

void bfs(){
    queue<int> q;
    memset(visited, -1, sizeof(visited));
    q.push(0);
    visited[0][0] = 0;

    while(!q.empty()){
        int now = q.front(); q.pop();
        int x = now / MX;
        int y = now % MX;

        for(int i=1; i<=6; i++){
            if(now + i >= 100) continue;

            int nx = (now + i) / MX;
            int ny = (now + i) % MX;

            if(arr[nx][ny].x==0 && arr[nx][ny].y==0){
                if(visited[nx][ny]==-1 || visited[nx][ny] > visited[x][y]+1){
                    q.push(now + i);
                    visited[nx][ny] = visited[x][y] + 1;
                }
            }

            else{
                int nnx = arr[nx][ny].x;
                int nny = arr[nx][ny].y;
                int nIdx = nnx*MX + nny;

                if(visited[nx][ny]==-1 || visited[nx][ny] > visited[x][y]+1){
                    visited[nx][ny] = visited[x][y] + 1;
                }

                if(visited[nnx][nny]==-1 || visited[nnx][nny] > visited[x][y]+1){
                    q.push(nIdx);
                    visited[nnx][nny] = visited[x][y] + 1;
                }
            }
        }
    }
}

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    cin >> N >> M;
    int from, to;
    for(int i=0; i<N+M; i++){
        cin >> from >> to;
        from--;
        to--;
        int fromX = from / MX;
        int fromY = from % MX;
        int toX = to / MX;
        int toY = to % MX;
        
        arr[fromX][fromY] = {toX, toY};

        // cout << fromX << ' ' << fromY << ' ' << toX << ' ' << toY << '\n';
    }

    bfs();

    cout << visited[MX-1][MX-1] << '\n';

    // for(int i=0; i<MX; i++){
    //     for(int j=0; j<MX; j++){
    //         cout << visited[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    return 0;
}