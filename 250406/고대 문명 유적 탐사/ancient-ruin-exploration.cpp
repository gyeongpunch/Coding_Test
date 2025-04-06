#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define MAX_M 300

struct Info{
    int value;
    int rCnt;
    int cx, cy;
};

struct Point{
    int x, y;
};

int K, M;
int arr[5][5];
int arrTmp[5][5];
int visited[5][5];
int newNum[MAX_M];
int newNumIdx = 0;
bool resultFlag = true;
int result = 0;
Info maxInfo;
vector<Point> bombTotal;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void arrPrint(){
    cout << "================\n";
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << "================\n";
}

void rotate(int x, int y){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            arrTmp[x+j][y+3-i-1] = arr[x+i][y+j];
        }
    }
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            arr[x+i][y+j] = arrTmp[x+i][y+j];
        }
    }
}

bool bound_check(int x, int y){
    return 0<=x && x<5 && 0<=y && y<5;
}

int bfs(int x, int y){
    queue<Point> q;
    q.push({x, y});
    int cnt = 0;
    visited[x][y] = 1;
    int nx, ny;
    while(!q.empty()){
        Point now = q.front(); q.pop();
        cnt++;
        for(int i=0; i<4; i++){
            nx = now.x + dx[i];
            ny = now.y + dy[i];

            if(!bound_check(nx, ny)) continue;
            if(visited[nx][ny] == 1) continue;
            if(arr[nx][ny] != arr[x][y]) continue;

            q.push({nx, ny});
            visited[nx][ny] = 1;
        }
    }

    if(cnt >= 3) {
        return cnt;
    }
    return 0;
}

void get_one_max(int x, int y, int rCnt){
    memset(visited, 0, sizeof(visited));
    int sum = 0;
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            if(visited[i][j] == 0){
                sum += bfs(i, j);
            }
        }
    }

    if(maxInfo.value < sum){
        maxInfo.value = sum;
        maxInfo.rCnt = rCnt;
        maxInfo.cy = y + 1;
        maxInfo.cx = x + 1;
    }
    else if (maxInfo.value == sum){
        if(maxInfo.rCnt > rCnt){
            maxInfo.rCnt = rCnt;
            maxInfo.cy = y + 1;
            maxInfo.cx = x + 1;
        }
        else if (maxInfo.rCnt == rCnt){
            if(maxInfo.cy > y + 1){
                maxInfo.cy = y + 1;
                maxInfo.cx = x + 1;
            }
            else if (maxInfo.cy == y + 1){
                if(maxInfo.cx > x + 1){
                    maxInfo.cx = x + 1;
                }
            }
        }
    }
}

void get_max_rotate(){
    for(int x=0; x<=2; x++){
        for(int y=0; y<=2; y++){
            for(int i=0; i<4; i++){
                rotate(x, y);

                // arrPrint();
                if(i<3) get_one_max(x, y, i);
                // cout << maxInfo.value << '\n';
            }
        }
    }
}

void bfs2(int x, int y){
    queue<Point> q;
    q.push({x, y});
    visited[x][y] = 1;
    int cnt = 0;
    vector<Point> tmp;

    int nx, ny;
    while(!q.empty()){
        Point now = q.front(); q.pop();

        tmp.push_back(now);

        cnt++;
        for(int i=0; i<4; i++){
            nx = now.x + dx[i];
            ny = now.y + dy[i];

            if(!bound_check(nx, ny)) continue;
            if(visited[nx][ny] == 1) continue;
            if(arr[nx][ny] != arr[x][y]) continue;

            q.push({nx, ny});
            visited[nx][ny] = 1;
        }
    }

    if(cnt >= 3) {
        for(const Point &p : tmp){
            bombTotal.push_back(p);
        }
    }
}

bool bomb(){
    memset(visited, 0, sizeof(visited));
    bombTotal.clear();
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            if(visited[i][j] == 0){
                bfs2(i, j);
            }
        }
    }
    
    if(bombTotal.empty()){
        return false;
    }

    for(const Point &p : bombTotal){
        arr[p.x][p.y] = 0;
        result++;
    }
    return true;
}

void fill_new(){
    for(int y=0; y<5; y++){
        for(int x=4; x>-1; x--){
            if(arr[x][y] == 0){
                arr[x][y] = newNum[newNumIdx++];
            }
        }
    }
}

void simulation(){
    maxInfo.value = -1;

    get_max_rotate();

    if(maxInfo.value == 0) {
        resultFlag = false;
        return;
    }
    rotate(maxInfo.cx-1, maxInfo.cy-1);
    bomb();
    // arrPrint();
    // cout << maxInfo.value << '\n';
    
    while(true){
        fill_new();
        if(!bomb()) return;
    }
}

int main() {
    fastio;

    cin >> K >> M;
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cin >> arr[i][j];
            arrTmp[i][j] = arr[i][j];
        }
    }

    for(int i=0; i<M; i++){
        cin >> newNum[i];
    }

    for(int k=0; k<K; k++){
        resultFlag = true;
        result = 0;
        simulation();

        if(resultFlag){
            cout << result << ' ';
        }
        else{
            break;
        }
    }
    return 0;
}