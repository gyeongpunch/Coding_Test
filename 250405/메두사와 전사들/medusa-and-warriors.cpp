#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define MAX_N 50

struct Point{
    int x, y;
};

struct Info{
    int moveSum;
    int rockCnt;
    int dieCnt;
};

int N, M;
Point medu, park;
int arr[MAX_N][MAX_N];
int visited[MAX_N][MAX_N];
vector<Point> soldier;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int maxRock = 0;
int maxDir = 0;

int ddx[4][3] = {
    {-1, -1, -1},
    {1, 1, 1},
    {1, 0, -1},
    {-1, 0, 1}
};
int ddy[4][3] = {
    {-1, 0, 1},
    {1, 0, -1},
    {-1, -1, -1},
    {1, 1, 1}
};

int result = -1;
vector<Point> path;
Info nowInfo;

bool bound_check(int x, int y){
    return 0<=x && x<N && 0<=y && y<N;
}

void getPath(){
    int now = visited[medu.x][medu.y];
    int nx, ny;
    while(true){
        
        if(medu.x == park.x && medu.y == park.y){
            return;
        }
        
        for(int i=0; i<4; i++){
            nx = medu.x + dx[i];
            ny = medu.y + dy[i];

            if(!bound_check(nx, ny)) continue;

            if(visited[nx][ny] == now-1){
                path.push_back({nx, ny});
                medu.x = nx;
                medu.y = ny;
                now--;
                break;
            }
        }
    }
}

bool parkBFS(){
    queue<Point> q;
    q.push(park);
    visited[park.x][park.y] = 1;

    int nx, ny;
    while(!q.empty()){
        Point now = q.front(); q.pop();

        if(now.x == medu.x && now.y == medu.y){
            return true;
        }

        for(int i=0; i<4; i++){
            nx = now.x + dx[i];
            ny = now.y + dy[i];

            if(!bound_check(nx, ny)) continue;
            if(arr[nx][ny] == 1) continue;
            if(visited[nx][ny] != 0) continue;

            q.push({nx, ny});
            visited[nx][ny] = visited[now.x][now.y] + 1;
        }
    }
    return false;
}

bool makePath(){
    if(!parkBFS()){
        return false;
    }
    getPath();
    return true;
}

void initInfo(){
    nowInfo.moveSum = 0;
    nowInfo.rockCnt = 0;
    nowInfo.dieCnt = 0;
}

void pprint(){
    cout << "============\n";
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << visited[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << "============\n";
}

void sprint(){
    cout << "==============\n";
    for(Point &s : soldier){
        cout << s.x << ' ' << s.y << '\n';
    }
    cout << "==============\n";
}

void straightBeam(const Point &p, int dir, int ch){
    queue<Point> q;
    q.push(p);

    int nx, ny;
    while(!q.empty()){
        Point now = q.front(); q.pop();

        nx = now.x + dx[dir];
        ny = now.y + dy[dir];
        if(!bound_check(nx, ny)) continue;
        visited[nx][ny] = ch;
        q.push({nx, ny});
    }
}

void rightBeam(const Point &p, int dir, int ch){
    queue<Point> q;
    q.push(p);
    int new_dx[2] = {ddx[dir][1], ddx[dir][2]};
    int new_dy[2] = {ddy[dir][1], ddy[dir][2]};
    int nx, ny;

    // cout << new_dx[0] << ' ' << new_dx[1] << '\n';

    while(!q.empty()){
        Point now = q.front(); q.pop();

        for(int i=0; i<2; i++){
            nx = now.x + new_dx[i];
            ny = now.y + new_dy[i];
            if(!bound_check(nx, ny)) continue;
            if(visited[nx][ny] == ch) continue;
            visited[nx][ny] = ch;
            q.push({nx, ny});
        }
    }
}

void leftBeam(const Point &p, int dir, int ch){
    queue<Point> q;
    q.push(p);
    int new_dx[2] = {ddx[dir][0], ddx[dir][1]};
    int new_dy[2] = {ddy[dir][0], ddy[dir][1]};
    int nx, ny;
    while(!q.empty()){
        Point now = q.front(); q.pop();

        for(int i=0; i<2; i++){
            nx = now.x + new_dx[i];
            ny = now.y + new_dy[i];
            if(!bound_check(nx, ny)) continue;
            if(visited[nx][ny] == ch) continue;
            visited[nx][ny] = ch;
            q.push({nx, ny});
        }
    }
}

int rockCalc(){
    int cnt = 0;
    for(const Point &s : soldier){
        if(visited[s.x][s.y] == 1){
            cnt++;
        }
    }
    return cnt;
}

void beamSimul(const Point &p, int dir){
    memset(visited, 0, sizeof(visited));

    straightBeam(p, dir, 1);
    rightBeam(p, dir, 1);
    leftBeam(p, dir, 1);
    // pprint();
    for(const Point &s : soldier){
        if(visited[s.x][s.y] == 1){
            if(dir == 0){
                if(p.y == s.y){
                    straightBeam(s, dir, 0);
                }
                else if (p.y < s.y){
                    rightBeam(s, dir, 0);
                }
                else{
                    leftBeam(s, dir, 0);
                }
            }

            else if (dir == 1){
                if(p.y == s.y){
                    straightBeam(s, dir, 0);
                }
                else if (p.y > s.y){
                    rightBeam(s, dir, 0);
                }
                else{
                    leftBeam(s, dir, 0);
                }
            }

            else if (dir == 2){
                if(p.x == s.x){
                    straightBeam(s, dir, 0);
                }
                else if (p.x > s.x){
                    rightBeam(s, dir, 0);
                }
                else{
                    leftBeam(s, dir, 0);
                }
            }

            else if (dir == 3){
                if(p.x == s.x){
                    straightBeam(s, dir, 0);
                }
                else if (p.x < s.x){
                    rightBeam(s, dir, 0);
                }
                else{
                    leftBeam(s, dir, 0);
                }
            }
        }
    }


    int cnt = rockCalc();

    if(cnt > maxRock){
        maxRock = cnt;
        maxDir = dir;
    }
}

void soldierMove(const Point &p){
    vector<Point> newSol;
    int nx, ny;
    // cout << p.x << ' ' << p.y << '\n';
    for(Point &s : soldier){
        if(s.x == p.x && s.y == p.y) continue;
        if(visited[s.x][s.y] == 1){
            newSol.push_back(s);
            nowInfo.rockCnt++;
            // cout << s.x << ' ' << s.y << '\n';
            continue;
        }

        for(int j=0; j<4; j++){
            nx = s.x + dx[j];
            ny = s.y + dy[j];

            if(!bound_check(nx, ny)) continue;
            if(visited[nx][ny] == 1) continue;
            if(abs(nx - p.x) + abs(ny - p.y) < abs(s.x - p.x) + abs(s.y - p.y)){
                s.x = nx;
                s.y = ny;
                nowInfo.moveSum++;
                break;
            }
        }

        if(s.x == p.x && s.y == p.y){
            nowInfo.dieCnt++;
            continue;
        }

        for(int j=2; j<6; j++){
            nx = s.x + dx[j%4];
            ny = s.y + dy[j%4];

            if(!bound_check(nx, ny)) continue;
            if(visited[nx][ny] == 1) continue;
            if(abs(nx - p.x) + abs(ny - p.y) < abs(s.x - p.x) + abs(s.y - p.y)){
                s.x = nx;
                s.y = ny;
                nowInfo.moveSum++;
                break;
            }
        }
        if(s.x == p.x && s.y == p.y){
            nowInfo.dieCnt++;
            continue;
        }

        newSol.push_back(s);
    }

    soldier = newSol;
}

void simulation(){
    for(const Point &p : path){
        if(p.x == park.x && p.y == park.y){
            cout << 0 << '\n';
            return;
        }

        initInfo();
        maxRock = 0;
        maxDir = 0;

        // cout << p.x << ' ' << p.y << '\n';

        for(int i=0; i<4; i++){
            beamSimul(p, i);
            // cout << p.x << ' ' << p.y << '\n';
            // pprint();
        }
        
        beamSimul(p, maxDir);
        // pprint();
        // cout << p.x << ' ' << p.y << '\n';
        // sprint();
        soldierMove(p);
        // sprint();

        cout << nowInfo.moveSum << ' ' << nowInfo.rockCnt << ' ' << nowInfo.dieCnt << '\n';
    }
}

int main() {
    fastio;

    cin >> N >> M;
    cin >> medu.x >> medu.y >> park.x >> park.y;
    int a, b;
    for(int i=0; i<M; i++){
        cin >> a >> b;
        soldier.push_back({a, b});
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> arr[i][j];
        }
    }

    if(!makePath()){
        cout << -1 << '\n';
    }
    else{
        simulation();
    }

    return 0;
}