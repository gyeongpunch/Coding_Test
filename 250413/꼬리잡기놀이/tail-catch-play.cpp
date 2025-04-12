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

struct Info{
    vector<Point> dq;
    int state;
};

int N, M, K;
int arr[MAX_N][MAX_N];
int groupMap[MAX_N][MAX_N];
int groupCnt[MAX_N];
int visited[MAX_N][MAX_N];
vector<Point> team[MAX_M];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int result = 0;

bool bound_check(int x, int y){
    return 0<=x && x<N && 0<=y && y<N;
}

void pprint(){
    cout << "\n\n";
    for(int i=0; i<M; i++){
        for(Point a : team[i]){
            cout << a.x << ' ' << a.y << '\n';
        }
        cout << "=======\n";
    }
    cout << "\n\n";
}

void group_bfs(int groupIdx, int x, int y){
    queue<Point> q;
    q.push({x, y});
    visited[x][y] = 1;
    groupMap[x][y] = groupIdx;
    team[groupIdx].push_back({x, y});

    int nx, ny;
    while(!q.empty()){
        Point now = q.front(); q.pop();
        if(1<=arr[now.x][now.y] && arr[now.x][now.y]<=3){
            groupCnt[groupIdx]++;
        }
        for(int i=0; i<4; i++){
            nx = now.x + dx[i];
            ny = now.y + dy[i];

            if(!bound_check(nx, ny)) continue;
            if(visited[nx][ny] == 1) continue;
            if(arr[nx][ny] == 0) continue;

            if(arr[x][y] == 1 && arr[nx][ny] == 3) continue;

            groupMap[nx][ny] = groupIdx;
            q.push({nx, ny});
            visited[nx][ny] = 1;
            team[groupIdx].push_back({nx, ny});
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
    memset(visited, 0, sizeof(visited));
    queue<Point> q;
    int x = team[groupIdx][groupCnt[groupIdx]-1].x;
    int y = team[groupIdx][groupCnt[groupIdx]-1].y;
    q.push({x, y});
    visited[x][y] = 1;

    int nx, ny;
    while(!q.empty()){
        Point now = q.front(); q.pop();
        
        tmp.push_back(now);

        for(int i=0; i<4; i++){
            nx = now.x + dx[i];
            ny = now.y + dy[i];

            if(!bound_check(nx, ny)) continue;
            if(visited[nx][ny] == 1) continue;
            if(arr[nx][ny] == 0) continue;

            if(arr[x][y] == 3 && arr[nx][ny] == 1) continue;

            q.push({nx, ny});
            visited[nx][ny] = 1;
        }
    }

    for(int j=0; j<team[groupIdx].size(); j++){
        if(j==0){
            arr[team[groupIdx][j].x][team[groupIdx][j].y] = 1;
        }
        else if(j<groupCnt[groupIdx]-1){
            arr[team[groupIdx][j].x][team[groupIdx][j].y] = 2;
        }
        else if (j==groupCnt[groupIdx]-1){
            arr[team[groupIdx][j].x][team[groupIdx][j].y] = 3;
        }
        else{
            arr[team[groupIdx][j].x][team[groupIdx][j].y] = 4;
        }
    }
}

void left_gogo(int x){
    for(int y=0; y<N; y++){
        if(1 <= arr[x][y] &&  arr[x][y] <= 3){
            for(int i=0; i < team[groupMap[x][y]].size(); i++){
                if(team[groupMap[x][y]][i].x == x && team[groupMap[x][y]][i].y == y){
                    result += (i+1) * (i+1);
                    change_head_tail(groupMap[x][y]);
                    return;
                }
            }
        }
    }
}
void bottom_gogo(int y){
    for(int x=N-1; x>-1; x--){
        if(1 <= arr[x][y] &&  arr[x][y] <= 3){
            for(int i=0; i < team[groupMap[x][y]].size(); i++){
                if(team[groupMap[x][y]][i].x == x && team[groupMap[x][y]][i].y == y){
                    result += (i+1) * (i+1);
                    change_head_tail(groupMap[x][y]);
                    return;
                }
            }
        }
    }
}
void right_gogo(int x){
    x = N - x - 1;
    for(int y=N-1; y>-1; y--){
        if(1 <= arr[x][y] &&  arr[x][y] <= 3){
            for(int i=0; i < team[groupMap[x][y]].size(); i++){
                if(team[groupMap[x][y]][i].x == x && team[groupMap[x][y]][i].y == y){
                    result += (i+1) * (i+1);
                    change_head_tail(groupMap[x][y]);
                    return;
                }
            }
        }
    }
}
void top_gogo(int y){
    y = N - y - 1;
    for(int x=0; x<N; x++){
        if(1 <= arr[x][y] &&  arr[x][y] <= 3){
            for(int i=0; i < team[groupMap[x][y]].size(); i++){
                if(team[groupMap[x][y]][i].x == x && team[groupMap[x][y]][i].y == y){
                    result += (i+1) * (i+1);
                    change_head_tail(groupMap[x][y]);
                    return;
                }
            }
        }
    }
}

void total_move(){
    for(int i=0; i<M; i++){
        Point tmp = team[i][0];

        for(int j=0; j<team[i].size()-1; j++){
            team[i][j] = team[i][j+1];
            // cout << team[i][j].x << ' ' << team[i][j].y << '\n';
        }
        team[i][team[i].size()-1] = tmp;
        
        for(int j=0; j<team[i].size(); j++){
            if(j==0){
                arr[team[i][j].x][team[i][j].y] = 1;
            }
            else if(j<groupCnt[i]-1){
                arr[team[i][j].x][team[i][j].y] = 2;
            }
            else if (j==groupCnt[i]-1){
                arr[team[i][j].x][team[i][j].y] = 3;
            }
            else{
                arr[team[i][j].x][team[i][j].y] = 4;
            }
        }
    }
}

void apring(){
    cout << "============\n";
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << "============\n";
}

int main() {
    fastio;

    cin >> N >> M >> K;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> arr[i][j];
        }
    }

    memset(groupMap, -1, sizeof(groupMap));

    int groupIdx = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(visited[i][j] == 0 && arr[i][j] == 1){
                group_bfs(groupIdx, i, j);
                groupIdx++;
            }
        }
    }

    for(int t=0; t<K; t++){
        total_move();

        t %= (N * 4);

        if(0<=t && t<N){
            left_gogo(t);
        }
        else if(N<=t && t<2*N){
            // pprint();
            bottom_gogo(t - N);
        }
        else if(2*N<=t && t<3*N){
            right_gogo(t - N*2);
        }
        else if(3*N<=t && t<4*N){
            top_gogo(t - N*3);
        }
        apring();
        // pprint();
    }

    cout << result << '\n';

    return 0;
}