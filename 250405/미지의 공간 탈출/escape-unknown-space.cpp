#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define MAX_N 20
#define MAX_M 10

struct Point{
    int x, y;
};

struct Time{
    Point p;
    int d, v;
};

struct CubePoint{
    int dir;
    Point p;
};

int N, M, F;
int arr[MAX_N][MAX_N];
int cube[5][MAX_M][MAX_M];
vector<Time> totalTime;
Point Me, Exit, Bound, cubeExit;
Point minCube = {MAX_N, MAX_N}, maxCube;
CubePoint CubeMe;

int cubeVisited[5][MAX_M][MAX_M];
int timeVisited[MAX_N][MAX_N];
int visited[MAX_N][MAX_N];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool bound_check(int x, int y){
    return 0<=x && x<N && 0<=y && y<N;
}

void time_bfs(){
    memset(timeVisited, -1, sizeof(timeVisited));
    queue<Time> q;
    for(const Time &t : totalTime){
        q.push(t);
        timeVisited[t.p.x][t.p.y] = 0;
    }

    int nx, ny;
    while(!q.empty()){
        Time now = q.front(); q.pop();
        nx = now.p.x + dx[now.d];
        ny = now.p.y + dy[now.d];

        if(!bound_check(nx, ny)) continue;
        if(arr[nx][ny] != 0) continue;
        if(timeVisited[nx][ny] != -1) continue;

        q.push({{nx, ny}, now.d, now.v});
        timeVisited[nx][ny] = timeVisited[now.p.x][now.p.y] + now.v;
    }
}

bool cube_bound(CubePoint now){
    Point cp;
    if(now.dir == 4){
        return false;
    }
    if(now.p.x == M-1){
        if(now.dir == 0){
            cp.x = M - now.p.y - 1 + minCube.x;
            cp.y = maxCube.y;
        }
        else if(now.dir == 1){
            cp.x = now.p.y + minCube.x;
            cp.y = minCube.y;
        }
        else if(now.dir == 2){
            cp.x = maxCube.x;
            cp.y = now.p.y + minCube.y;
        }
        else if(now.dir == 3){
            cp.x = minCube.x;
            cp.y = M - now.p.y - 1 + minCube.y;
        }
    }
    else{
        return false;
    }

    return cp.x == cubeExit.x && cp.y == cubeExit.y;
}

bool cube_exit_bfs(){
    memset(cubeVisited, -1, sizeof(cubeVisited));

    queue<CubePoint> q;
    q.push(CubeMe);
    cubeVisited[CubeMe.dir][CubeMe.p.x][CubeMe.p.y] = 0;

    int nd, nx, ny;
    while(!q.empty()){
        CubePoint now = q.front(); q.pop();

        if(cube_bound(now)){
            visited[cubeExit.x][cubeExit.y] = cubeVisited[now.dir][now.p.x][now.p.y];
            return true;
        }

        for(int i=0; i<4; i++){
            nx = now.p.x + dx[i];
            ny = now.p.y + dy[i];
            nd = now.dir;
            
            if(nd == 4){
                if(nx >= M){
                    nd = 2; nx = 0; ny = now.p.y;
                }
                else if (nx < 0){
                    nd = 3; nx = 0; ny = M - now.p.y - 1;
                }
                else if (ny >= M){
                    nd = 0; nx = 0; ny = M - now.p.x - 1;
                }
                else if (ny < 0){
                    nd = 1; nx = 0; ny = now.p.x;
                }
            }
            else if (nd == 0){
                if(nx >= M){
                    nd = 0; nx = now.p.x; ny = now.p.y;
                }
                else if (nx < 0){
                    nd = 4; nx = M - now.p.y - 1; ny = M - now.p.x - 1;
                }
                else if (ny >= M){
                    nd = 3; nx = now.p.x; ny = M - now.p.y - 1;
                }
                else if (ny < 0){
                    nd = 2; nx = now.p.x; ny = M - now.p.y - 1;
                }
            }
            else if (nd == 1){
                if(nx >= M){
                    nd = 1; nx = now.p.x; ny = now.p.y;
                }
                else if (nx < 0){
                    nd = 4; nx = now.p.y; ny = 0;
                }
                else if (ny >= M){
                    nd = 2; nx = now.p.x; ny = M - now.p.y - 1;
                }
                else if (ny < 0){
                    nd = 3; nx = now.p.x; ny = M - now.p.y - 1;
                }
            }
            else if (nd == 2){
                if(nx >= M){
                    nd = 2; nx = now.p.x; ny = now.p.y;
                }
                else if (nx < 0){
                    nd = 4; nx = M - now.p.x - 1; ny = now.p.y;
                }
                else if (ny >= M){
                    nd = 0; nx = now.p.x; ny = M - now.p.y - 1;
                }
                else if (ny < 0){
                    nd = 1; nx = now.p.x; ny = M - now.p.y - 1;
                }
            }
            else if (nd == 3){
                if(nx >= M){
                    nd = 2; nx = now.p.x; ny = now.p.y;
                }
                else if (nx < 0){
                    nd = 4; nx = 0; ny = M - now.p.y - 1;
                }
                else if (ny >= M){
                    nd = 1; nx = now.p.x; ny = M - now.p.y - 1;
                }
                else if (ny < 0){
                    nd = 0; nx = now.p.x; ny = M - now.p.y - 1;
                }
            }

            if (cubeVisited[nd][nx][ny] != -1) continue;
            if(cube[nd][nx][ny] == 1) continue;
            q.push({nd, {nx, ny}});
            cubeVisited[nd][nx][ny] = cubeVisited[now.dir][now.p.x][now.p.y] + 1;
        }
    }
    return false;
}

bool bound_exit_bfs(){
    queue<Point> q;
    q.push({cubeExit.x, cubeExit.y});

    int nx, ny;
    while(!q.empty()){
        Point now = q.front(); q.pop();

        if(arr[now.x][now.y] == 4){
            return true;
        }

        for(int i=0; i<4; i++){
            nx = now.x + dx[i];
            ny = now.y + dy[i];

            if(!bound_check(nx, ny)) continue;
            if(arr[nx][ny] != 0 && arr[nx][ny] != 4) continue;
            if(timeVisited[nx][ny] != -1 && visited[now.x][now.y] + 1 >= timeVisited[nx][ny]) continue;
            if(visited[nx][ny] != 0) continue;

            q.push({nx, ny});
            visited[nx][ny] = visited[now.x][now.y] + 1;
        }
    }
    return false;
}


int main() {
    fastio;

    cin >> N >> M >> F;
    int nx, ny;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 5){
                Exit = {i, j};
            }

            else if (arr[i][j] == 3){
                minCube.x = min(minCube.x, i);
                minCube.y = min(minCube.y, j);
                maxCube.x = max(maxCube.x, i);
                maxCube.y = max(maxCube.y, j);

                for(int d=0; d<4; d++){
                    nx = i + dx[d];
                    ny = j + dy[d];

                    if(!bound_check(nx, ny)) continue;

                    if(arr[nx][ny] == 0){
                        Bound = {nx, ny};
                        cubeExit = {i, j};
                        break;
                    }
                }
            }

        }
    }

    for(int i=0; i<5; i++){
        for(int j=0; j<M; j++){
            for(int k=0; k<M; k++){
                cin >> cube[i][j][k];
                if(cube[i][j][k] == 2){
                    CubeMe = {i, {j, k}};
                }
            }
        }
    }

    int r, c, d, v;
    for(int i=0; i<F; i++){
        cin >> r >> c >> d >> v;
        totalTime.push_back({{r, c}, d, v});
    }

    time_bfs();

    if(!cube_exit_bfs()){
        // for(int i=0; i<5; i++){
        //     for(int j=0; j<M; j++){
        //         for(int k=0; k<M; k++){
        //             cout << cubeVisited[i][j][k] << ' ';
        //         }
        //         cout << '\n';
        //     }
        //     cout << '\n';
        // }


        cout << "-1\n";
        return 0;
    }

    // for(int i=0; i<5; i++){
    //     for(int j=0; j<M; j++){
    //         for(int k=0; k<M; k++){
    //             cout << cubeVisited[i][j][k] << ' ';
    //         }
    //         cout << '\n';
    //     }
    //     cout << '\n';
    // }

    if (bound_exit_bfs()){
        cout << visited[Exit.x][Exit.y] << '\n';
    }
    else{
        cout << "-1\n";
    }

    // for(int i=0; i<N; i++){
    //     for(int j=0; j<N; j++){
    //         cout << visited[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    // cout << minCube.x << ' ' << minCube.y << ' ' << maxCube.x << ' ' << maxCube.y << '\n'; 
    // cout << CubeMe.dir << ' ' << CubeMe.p.x << ' ' << CubeMe.p.y << '\n';
    // cout << Bound.x << ' ' << Bound.y << '\n';
    // cout << cubeExit.x << ' ' << cubeExit.y << '\n';    

    return 0;
}