#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

#define MAX_N 10

struct Point{
    int x, y;
};

struct Info{
    int damage;
    int lastA, lastH;
    Point p;
};

int N, M, K;
int arr[MAX_N][MAX_N];
int timeMap[MAX_N][MAX_N];
int visited[MAX_N][MAX_N];
vector<Point> path;
Info attack, harm;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int ddx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int ddy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

void init_attack_harm(){
    attack.damage = 1e9;
    attack.lastA = -1;
    attack.p = {-1, -1};

    harm.damage = -1;
    harm.lastH = 1e9;
    harm.p = {MAX_N, MAX_N};
}

void get_attack_harm(){
    init_attack_harm();

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(arr[i][j] == 0) continue;

            if(attack.damage > arr[i][j] || 
            (attack.damage == arr[i][j] && (attack.lastA < timeMap[i][j] ||
            (attack.lastA == timeMap[i][j] && (attack.p.x + attack.p.y < i + j ||
            (attack.p.x + attack.p.y == i + j && (attack.p.y < j))))))){
                attack.damage = arr[i][j]; attack.p = {i, j}; attack.lastA = timeMap[i][j];
            }

            if(harm.damage < arr[i][j] ||
            (harm.damage == arr[i][j] && (harm.lastH > timeMap[i][j] ||
            (harm.lastH == timeMap[i][j] && (harm.p.x + harm.p.y > i + j ||
            (harm.p.x + harm.p.y == i + j && (harm.p.y > j))))))){
                harm.damage = arr[i][j]; harm.p = {i, j}; harm.lastH = timeMap[i][j];
            }

            // if(harm.damage < arr[i][j]){
            //     harm.damage = arr[i][j]; harm.p = {i, j}; harm.lastH = timeMap[i][j];
            // }
            // else if (harm.damage == arr[i][j]){
            //     if(harm.lastH > timeMap[i][j]){
            //         harm.damage = arr[i][j]; harm.p = {i, j}; harm.lastH = timeMap[i][j];
            //     }
            //     else if (harm.lastH == timeMap[i][j]){
            //         if(harm.p.x+harm.p.y > i + j){
            //             harm.damage = arr[i][j]; harm.p = {i, j}; harm.lastH = timeMap[i][j];
            //         }
            //         else if (harm.p.x+harm.p.y == i + j){
            //             if(harm.p.y > j){
            //                 harm.damage = arr[i][j]; harm.p = {i, j}; harm.lastH = timeMap[i][j];
            //             }
            //         }
            //     }
            // }
        }
    }
    if(attack.p.x == harm.p.x && attack.p.y == harm.p.y) return;

    arr[attack.p.x][attack.p.y] += N + M;
}

void pprint(){
    cout << "=================\n";
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << "=================\n";
}

bool harm2attack_bfs(){
    memset(visited, -1, sizeof(visited));
    path.clear();

    queue<Point> q;
    visited[harm.p.x][harm.p.y] = 0;
    q.push(harm.p);

    int nx, ny;
    while(!q.empty()){
        Point now = q.front(); q.pop();

        for(int i=0; i<4; i++){
            nx = (now.x + dx[i] + N) % N;
            ny = (now.y + dy[i] + M) % M;

            if(visited[nx][ny] != -1) continue;
            if(arr[nx][ny] == 0) continue;

            q.push({nx, ny});
            visited[nx][ny] = visited[now.x][now.y] + 1;
        }
    }
    
    if(visited[attack.p.x][attack.p.y] == -1) return false;

    Point now = attack.p;
    int target = visited[attack.p.x][attack.p.y] - 1;
    while(true){
        if(target == -1){
            break;
        }
        for(int i=0; i<4; i++){
            nx = (now.x + dx[i] + N) % N;
            ny = (now.y + dy[i] + M) % M;

            if(visited[nx][ny] == -1) continue;

            if(visited[nx][ny] == target){
                path.push_back({nx, ny});
                target--;
                now.x = nx;
                now.y = ny;
                break;
            }
        }
    }
    // pprint();
    return true;
}

void laser(int t){
    memset(visited, 0, sizeof(visited));
    visited[attack.p.x][attack.p.y] = 1;
    for(const Point &p : path){
        visited[p.x][p.y] = 1;
        if(p.x == harm.p.x && p.y == harm.p.y){
            arr[p.x][p.y] = max(0, arr[p.x][p.y] - arr[attack.p.x][attack.p.y]);
        }
        else{
            arr[p.x][p.y] = max(0, arr[p.x][p.y] - arr[attack.p.x][attack.p.y] / 2);
        }
    }
}

void popo(int t){
    memset(visited, 0, sizeof(visited));
    visited[attack.p.x][attack.p.y] = 1;
    visited[harm.p.x][harm.p.y] = 1;
    arr[harm.p.x][harm.p.y] = max(0, arr[harm.p.x][harm.p.y] - arr[attack.p.x][attack.p.y]);
    
    
    int nx, ny;
    for(int i=0; i<8; i++){
        nx = (harm.p.x + ddx[i] + N) % N;
        ny = (harm.p.y + ddy[i] + M) % M;

        // cout << nx << ' ' << ny << '\n';

        if(attack.p.x == nx && attack.p.y == ny) continue;

        visited[nx][ny] = 1;
        arr[nx][ny] = max(0, arr[nx][ny] - arr[attack.p.x][attack.p.y] / 2);
    }
}

void fix(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(arr[i][j] == 0) continue;
            if(visited[i][j] == 1) continue;

            arr[i][j]++;
        }
    }
}

int main() {
    fastio;

    cin >> N >> M >> K;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> arr[i][j];
        }
    }
    for(int i=1; i<=K; i++){
        get_attack_harm();

        // cout << attack.p.x << ' ' << attack.p.y << ' ' << harm.p.x << ' ' << harm.p.y << '\n';

        if(attack.p.x == harm.p.x && attack.p.y == harm.p.y){
            break;
        }

        if(harm2attack_bfs()){

            // for(Point p : path){
            //     cout << p.x << ' ' << p.y << '\n';
            // }
            laser(i);
        }
        else{
            popo(i);
        }
        fix();
        timeMap[attack.p.x][attack.p.y] = i;
        // pprint();
    }

    get_attack_harm();

    cout << harm.damage << '\n';

    return 0;
}