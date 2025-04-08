#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define MAX_N 15
#define MAX_M 30

struct Point{
    int x, y;
};
void pprint();
int N, M;
int arr[MAX_N][MAX_N];
Point target_store[MAX_M+1];
Point curr_loc[MAX_M+1];
int visited[MAX_N][MAX_N];
vector<Point> basecamp;
int result = 0;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

bool is_over(){
    for(int i=1; i<=M; i++){
        if(arr[target_store[i].x][target_store[i].y] != 2) return false;
    }
    return true;
}

bool bound_check(int x, int y){
    return 0<=x && x<N && 0<=y && y<N;
}

void move(int idx){
    memset(visited, 0, sizeof(visited));
    queue<Point> q;
    q.push(target_store[idx]);
    visited[target_store[idx].x][target_store[idx].y] = 1;

    int nx, ny;
    while(!q.empty()){
        Point now = q.front(); q.pop();

        if(now.x == curr_loc[idx].x && now.y == curr_loc[idx].y) break;

        for(int i=0; i<4; i++){
            nx = now.x + dx[i];
            ny = now.y + dy[i];

            if(!bound_check(nx, ny)) continue;
            if(visited[nx][ny] != 0) continue;

            if(arr[nx][ny] == 2){
                if(nx == curr_loc[idx].x && ny == curr_loc[idx].y){
                    q.push({nx, ny});
                    visited[nx][ny] = visited[now.x][now.y] + 1;
                }
                else{
                    continue;
                }
            }
            else{
                q.push({nx, ny});
                visited[nx][ny] = visited[now.x][now.y] + 1;
            }            
        }
    }

    // cout << "visited: " << idx << '\n';
    // for(int i=0; i<N; i++){
    //     for(int j=0; j<N; j++){
    //         cout << visited[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';

    for(int i=0; i<4; i++){
        nx = curr_loc[idx].x + dx[i];
        ny = curr_loc[idx].y + dy[i];

        if(!bound_check(nx, ny)) continue;

        if(visited[nx][ny] == visited[curr_loc[idx].x][curr_loc[idx].y] - 1){
            curr_loc[idx] = {nx, ny};
            break;
        }
    }
}

void total_move(int now_time){
    for(int i=1; i<=min(now_time-1, M); i++){
        if(arr[target_store[i].x][target_store[i].y] == 2) continue;
        move(i);
    }
}

void block_store(int now_time){
    for(int i=1; i<=M; i++){
        if(arr[target_store[i].x][target_store[i].y] == 2) continue;

        if(target_store[i].x == curr_loc[i].x && target_store[i].y == curr_loc[i].y){
            arr[target_store[i].x][target_store[i].y] = 2;
        }
    }
}

void go_basecamp(int idx){
    memset(visited, 0, sizeof(visited));
    queue<Point> q;
    q.push(target_store[idx]);
    visited[target_store[idx].x][target_store[idx].y] = 1;

    int nx, ny;
    while(!q.empty()){
        Point now = q.front(); q.pop();

        for(int i=0; i<4; i++){
            nx = now.x + dx[i];
            ny = now.y + dy[i];

            if(!bound_check(nx, ny)) continue;
            if(visited[nx][ny] != 0) continue;
            if(arr[nx][ny] == 2) continue;

            q.push({nx, ny});
            visited[nx][ny] = visited[now.x][now.y] + 1;
        }
    }

    int min_dist = N * N + 1;
    Point min_basecamp;

    for(const Point &b : basecamp){
        if(arr[b.x][b.y] == 2) continue;
        if(visited[b.x][b.y] == 0) continue;
        if(visited[b.x][b.y] < min_dist){
            min_dist = visited[b.x][b.y];
            min_basecamp = b;
        }
    }

    curr_loc[idx] = min_basecamp;
    arr[min_basecamp.x][min_basecamp.y] = 2;
}

void simulation(int now_time){
    total_move(now_time);

    block_store(now_time);

    if(now_time <= M){
        go_basecamp(now_time);
    }
}

bool custom_compare(Point a, Point b){
    if(a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}

int main(void){
    fastio;

    // freopen("input.txt", "r", stdin);

    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 1){
                basecamp.push_back({i, j});
            }
        }
    }

    sort(basecamp.begin(), basecamp.end(), custom_compare);

    int x, y;
    for(int i=1; i<=M; i++){
        cin >> x >> y;
        target_store[i] = {x-1, y-1};
    }

    while(true){
        simulation(++result);
        // pprint();
        if(is_over()) break;

        // if(result == 10) break;
    }
    // pprint();
    cout << result << '\n';

    return 0;
}

void pprint(){
    cout << "==================\n";
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << "-----------------------\n";
    for(int i=1; i<=M; i++){
        cout << curr_loc[i].x + 1<< ' ' << curr_loc[i].y + 1 << '\n';
    }
    cout << "==================\n";
}