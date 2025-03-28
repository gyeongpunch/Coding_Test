#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

#define MAX_SZ 70

struct Point{
    int x, y;
};

struct Goll{
    Point p;
    int dir;
};

int N, M, K;
int arr[MAX_SZ+3][MAX_SZ];
int visited[MAX_SZ+3][MAX_SZ];
Goll goll;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int result = 0;

bool bound_check(int x, int y){
    return 0<=x && x <N+3 && 0<=y && y <M;
}

void pprint(){
    cout << "==============\n";
    for(int i=0; i<N+3; i++){
        for(int j=0; j<M; j++){
            cout.width(3);
            cout << arr[i][j];
        }
        cout << '\n';
    }
    cout << "result : " << result << '\n';
    cout << "==============\n";
}

bool drop_check(int x, int y){
    if(!bound_check(x + 1, y - 1)) return false;
    if(!bound_check(x + 2, y)) return false;
    if(!bound_check(x + 1, y + 1)) return false;

    if(arr[x + 1][y - 1] != 0) return false;
    if(arr[x + 2][y] != 0) return false;
    if(arr[x + 1][y + 1] != 0) return false; 
    
    return true;
}

bool left_check(int x, int y){
    if(!bound_check(x - 1, y - 1)) return false;
    if(!bound_check(x, y - 2)) return false;
    if(!bound_check(x + 1, y - 1)) return false;

    if(arr[x - 1][y - 1] != 0) return false;
    if(arr[x][y - 2] != 0) return false;
    if(arr[x + 1][y - 1] != 0) return false; 
    
    return true;
}

bool right_check(int x, int y){
    if(!bound_check(x - 1, y + 1)) return false;
    if(!bound_check(x, y + 2)) return false;
    if(!bound_check(x + 1, y + 1)) return false;

    if(arr[x - 1][y + 1] != 0) return false;
    if(arr[x][y + 2] != 0) return false;
    if(arr[x + 1][y + 1] != 0) return false; 
    
    return true;
}

void goMarking(int idx){
    arr[goll.p.x][goll.p.y] = idx;
    arr[goll.p.x-1][goll.p.y] = idx;
    arr[goll.p.x+1][goll.p.y] = idx;
    arr[goll.p.x][goll.p.y-1] = idx;
    arr[goll.p.x][goll.p.y+1] = idx;
    arr[goll.p.x + dx[goll.dir]][goll.p.y + dy[goll.dir]] = -idx;
}

void bfs(){
    queue<Point> q;
    
    memset(visited, 0, sizeof(visited));
    q.push(goll.p);
    visited[goll.p.x][goll.p.y] = 1;

    int subMax = 0;
    int nx, ny;
    while(!q.empty()){
        Point now = q.front(); q.pop();
        subMax = max(subMax, now.x);

        for(int i=0; i<4; i++){
            nx = now.x + dx[i];
            ny = now.y + dy[i];

            if(!bound_check(nx, ny)) continue;
            if(visited[nx][ny] != 0) continue;
            if(arr[nx][ny] == 0) continue;

            if(arr[now.x][now.y] < 0){
                q.push({nx, ny});
                visited[nx][ny] = 1;
            }
            else{
                if(arr[now.x][now.y] == arr[nx][ny] || arr[nx][ny] == -arr[now.x][now.y]){
                    q.push({nx, ny});
                    visited[nx][ny] = 1;
                }
            }
            
        }
    }

    result += subMax-2;

}

void simulation(int idx, int c, int dir){
    goll.p.x = 1;
    goll.p.y = c;
    goll.dir = dir;

    while(true){
        if(goll.p.x == N+1) break;

        if(drop_check(goll.p.x, goll.p.y)){
            goll.p.x++;
            continue;
        }
        else if (left_check(goll.p.x, goll.p.y) && drop_check(goll.p.x, goll.p.y-1)){
            goll.p.y--;
            goll.dir = (goll.dir + 3) % 4;
            goll.p.x++;
            continue;
        }
        else if(right_check(goll.p.x, goll.p.y) && drop_check(goll.p.x, goll.p.y+1)){
            goll.p.y++;
            goll.dir = (goll.dir + 1) % 4;
            goll.p.x++;
            continue;
        }
        break;
    }

    if(goll.p.x <= 3){
        memset(arr, 0, sizeof(arr));
        return;
    }

    goMarking(idx);
    bfs();
    // pprint();
}

int main() {
    fastio;

    cin >> N >> M >> K;
    int c, dir;
    for(int i=0; i<K; i++){
        cin >> c >> dir;
        simulation(i+1, c-1, dir);
    }

    cout << result << '\n';
    
    return 0;
}