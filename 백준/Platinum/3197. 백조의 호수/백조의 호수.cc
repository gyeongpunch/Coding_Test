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

const int MX = 1500;

int N, M, result = 0;
char arr[MX][MX];
int swanVisited[MX][MX], waterVisited[MX][MX];
vector<Point> swan;
queue<Point> swanQueue, swanQueue2;
queue<Point> waterQueue, waterQueue2;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool bound_check(int x, int y){
    return 0<=x && x<N && 0<=y && y<M;
}

bool swan_bfs(){
    Point now;
    int nx, ny;
    while(!swanQueue.empty()){
        now = swanQueue.front(); swanQueue.pop();

        for(int i=0; i<4; i++){
            nx=now.x+dx[i];
            ny=now.y+dy[i];

            if(!bound_check(nx, ny)) continue;
            if(swanVisited[nx][ny] == 1) continue;

            swanVisited[nx][ny] = 1;

            if(arr[nx][ny] == 'L'){
                if(swan[1].x == nx && swan[1].y == ny){
                    return true;
                }
            }
            else if(arr[nx][ny] == '.'){
                swanQueue.push({nx, ny});
            }
            else if(arr[nx][ny] == 'X'){
                swanQueue2.push({nx, ny});
            }
        }
    }
    return false;
}

void water_bfs(){
    Point now;
    int nx, ny;

    while(!waterQueue.empty()){
        now = waterQueue.front(); waterQueue.pop();

        for(int i=0; i<4; i++){
            nx=now.x+dx[i];
            ny=now.y+dy[i];

            if(!bound_check(nx, ny)) continue;
            if(waterVisited[nx][ny]) continue;

            if(arr[nx][ny] == 'X'){
                arr[nx][ny] = '.';
                waterQueue2.push({nx, ny});
                waterVisited[nx][ny] = 1;
            }
        }
    }
}

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 'L'){
                swan.push_back({i, j});
            }
            if(arr[i][j]!='X'){
                waterQueue.push({i, j});
                waterVisited[i][j] = 1;
            }
        }
    }

    swanVisited[swan[0].x][swan[0].y] = 1;
    swanQueue.push(swan[0]);

    while(true){
        if(swan_bfs()){
            break;
        }
        water_bfs();

        swap(swanQueue, swanQueue2);
        swap(waterQueue, waterQueue2);

        result++;
    }

    cout << result << '\n';

    return 0;
}