#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define MAX_N 50

struct Point{
    int x, y;
};

int N, L, R;
int arr[MAX_N][MAX_N];
int section[2][MAX_N][MAX_N];
int visited[MAX_N][MAX_N];
int result=0;
bool flag;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void pprint(){
    cout << "=================\n";
    cout << "arr : \n";
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << "=================\n";
}

void remove(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(j != N-1 && section[1][i][j] == 0 && L<=abs(arr[i][j] - arr[i][j+1]) && abs(arr[i][j] - arr[i][j+1]) <= R){
                section[1][i][j] = 1;
            }
            if(i != N-1 && section[0][i][j] == 0 && L<=abs(arr[i][j] - arr[i+1][j]) && abs(arr[i][j] - arr[i+1][j]) <= R){
                section[0][i][j] = 1;
            }
        }
    }
}

bool bound_check(int x, int y){
    return 0<=x && x<N && 0<=y && y<N;
}

void bfs(int x, int y){
    queue<Point> q;
    visited[x][y] = 1;
    q.push({x, y});
    vector<Point> v;
    int vSum = 0;

    int nx, ny;
    while(!q.empty()){
        Point now = q.front(); q.pop();
        vSum += arr[now.x][now.y];
        v.push_back({now.x, now.y});

        for(int i=0; i<4; i++){
            nx = now.x + dx[i];
            ny = now.y + dy[i];

            if(!bound_check(nx, ny)) continue;
            if(visited[nx][ny] != 0) continue;
            
            if(i == 0 && section[0][nx][ny] == 1){
                q.push({nx, ny});
                visited[nx][ny] = 1;
            }
            else if (i == 1 && section[1][now.x][now.y] == 1){
                q.push({nx, ny});
                visited[nx][ny] = 1;
            }
            else if (i == 2 && section[0][now.x][now.y] == 1){
                q.push({nx, ny});
                visited[nx][ny] = 1;
            }
            else if(i == 3 && section[1][nx][ny] == 1){
                q.push({nx, ny});
                visited[nx][ny] = 1;
            }
        }
    }
    if(v.size() > 1){
        for(const Point &p : v){
            if(arr[p.x][p.y] != vSum / v.size()) flag = false;
            arr[p.x][p.y] = vSum / v.size();
        }
    }
}

void merge(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(visited[i][j] == 0){
                bfs(i, j);
            }
        }
    }
}

void simulation(){
    memset(section, 0, sizeof(section));
    memset(visited, 0, sizeof(visited));

    remove();

    merge();
}

int main() {
    fastio;

    // freopen("input.txt", "r", stdin);

    cin >> N >> L >> R;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> arr[i][j];
        }
    }
    // pprint();
    while(true){
        flag = true;
        simulation();
        // pprint();
        if(flag){
            break;
        }
        result++;
    }

    cout << result << '\n';

    return 0;
}