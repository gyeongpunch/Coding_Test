#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define MAX_N 20
#define MAX_M 5
struct Point{
    int x, y;
};

int N, M, K;
int arr[MAX_N][MAX_N];
int visited[MAX_N][MAX_N];
vector<Point> team[MAX_M];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int result = 0;

bool bound_check(int x, int y){
    return 0<=x && x<N && 0<=y && y<N;
}

void group_bfs(int num, int groupIdx, int x, int y){
    queue<Point> q;
    q.push({x, y});
    visited[x][y] = 1;
    arr[x][y] = num;
    team[groupIdx].push_back({x, y});

    int nx, ny;
    while(!q.empty()){
        Point now = q.front(); q.pop();

        for(int i=0; i<4; i++){
            nx = now.x + dx[i];
            ny = now.y + dy[i];

            if(!bound_check(nx, ny)) continue;
            if(visited[nx][ny] == 1) continue;
            if(arr[nx][ny] != 2 && arr[nx][ny] != 3) continue;

            q.push({nx, ny});
            visited[nx][ny] = 1;
            arr[nx][ny] = num;
            team[groupIdx].push_back({nx, ny});
        }
    }

}

void path_bfs(int num, int x, int y){
    queue<Point> q;
    q.push({x, y});
    visited[x][y] = 1;
    arr[x][y] = num;

    int nx, ny;
    while(!q.empty()){
        Point now = q.front(); q.pop();

        for(int i=0; i<4; i++){
            nx = now.x + dx[i];
            ny = now.y + dy[i];

            if(!bound_check(nx, ny)) continue;
            if(visited[nx][ny] == 1) continue;
            if(arr[nx][ny] != 4 && arr[nx][ny] != num) continue;

            q.push({nx, ny});
            visited[nx][ny] = 1;
            arr[nx][ny] = num;
        }
    }
}

bool check(int x, int y, int groupIdx){
    for(int i=0; i<team[groupIdx].size(); i++){
        if(x==team[groupIdx][i].x && y==team[groupIdx][i].y){
            result += (i+1) * (i+1);
            return true;
        }
    }
    return false;
}

void change_head_tail(int groupIdx){
    vector<Point> tmp;
    for(int i=team[groupIdx].size()-1; i>-1; i--){
        tmp.push_back(team[groupIdx][i]);
    }

    team[groupIdx] = tmp;
}

void left_gogo(int x){
    for(int y=0; y<N; y++){
        if(arr[x][y] >= 5){
            if(check(x, y, arr[x][y]-5)){
                change_head_tail(arr[x][y]-5);
                break;
            }
        }
    }
}
void bottom_gogo(int y){
    for(int x=N-1; x>-1; x--){
        if(arr[x][y] >= 5){
            if(check(x, y, arr[x][y]-5)){
                change_head_tail(arr[x][y]-5);
                break;
            }
        }
    }
}
void right_gogo(int x){
    for(int y=N-1; y>-1; y--){
        if(arr[x][y] >= 5){
            if(check(x, y, arr[x][y]-5)){
                change_head_tail(arr[x][y]-5);
                break;
            }
        }
    }
}
void top_gogo(int y){
    for(int x=0; x<N; x++){
        if(arr[x][N-y-1] >= 5){
            if(check(x, y, arr[x][y]-5)){
                change_head_tail(arr[x][y]-5);
                break;
            }
        }
    }
}

void total_move(){
    for(int i=0; i<M; i++){
        vector<Point> tmp;

        int nx, ny;
        for(int j=0; j<4; j++){
            nx = team[i][0].x + dx[j];
            ny = team[i][0].y + dy[j];

            if(!bound_check(nx, ny)) continue;
            if(arr[nx][ny] == 0) continue;
            if(nx == team[i][1].x && ny == team[i][1].y) continue;
            
            tmp.push_back({nx, ny});
            break;
        }

        for(int j=0; j<team[i].size()-1; j++){
            tmp.push_back(team[i][j]);

            // cout << team[i][j].x << ' ' << team[i][j].y << '\n';
        }

        team[i] = tmp;
    }
}

int main() {
    fastio;

    cin >> N >> M >> K;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> arr[i][j];
        }
    }
    int num = 5;
    int groupIdx = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(visited[i][j] == 0 && arr[i][j] == 1){
                group_bfs(num, groupIdx, i, j);
                num++;
                groupIdx++;
            }
        }
    }

    memset(visited, 0, sizeof(visited));

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(visited[i][j] == 0 && arr[i][j] > 4){
                path_bfs(arr[i][j], i, j);
            }
        }
    }

    // for(int i=0; i<N; i++){
    //     for(int j=0; j<N; j++){
    //         cout << arr[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }



    for(int t=0; t<K; t++){
        total_move();

        // for(int i=0; i<M; i++){
        //     for(Point a : team[i]){
        //         cout << a.x << ' ' << a.y << '\n';
        //     }
        //     cout << "=======\n";
        // }

        t %= 4 * N;

        if(0<=t && t<N){
            left_gogo(t);
        }
        else if(N<=t && t<2*N){
            bottom_gogo(N-t);
        }
        else if(2*N<=t && t<3*N){
            right_gogo(2*N-t);
        }
        else if(3*N<=t && t<4*N){
            top_gogo(3*N-t);
        }

        // for(int i=0; i<M; i++){
        //     for(Point a : team[i]){
        //         cout << a.x << ' ' << a.y << '\n';
        //     }
        //     cout << "=======\n";
        // }
    }

    cout << result << '\n';

    return 0;
}