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
    int x, y, z;
};

const int N = 5;

int arr[N][N][N];
int arrTmp[N][N][N];
int arrTmp2[N][N][N];
int visited[N][N][N];
int result = 1e9;

int dx[6] = {-1, 1, 0, 0, 0, 0};
int dy[6] = {0, 0, -1, 1, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};

vector<int> location;
int vstLoc[N];

vector<int> rotateArr;

const int start_pos[8][3] = {
    {0,0,0}, {0,0,4}, {0,4,0}, {0,4,4}, {4,0,0}, {4,0,4}, {4,4,0}, {4,4,4}
};
Point startP, endP;

bool bound_check(int x, int y, int z){
    return 0<=x && x<N && 0<=y && y<N && 0<=z && z<N;
}

void bfs(){
    queue<Point> q;
    q.push(startP);
    memset(visited, -1, sizeof(visited));
    visited[startP.x][startP.y][startP.z] = 0;

    Point now;
    int nx, ny, nz;
    while(!q.empty()){
        now = q.front(); q.pop();

        if(now.x == endP.x && now.y == endP.y && now.z == endP.z){
            result = min(result, visited[now.x][now.y][now.z]);
            if(result == 12){
                cout << result << '\n';
                exit(0);
            }
            return;
        }

        for(int i=0; i<6; i++){
            nx = now.x + dx[i];
            ny = now.y + dy[i];
            nz = now.z + dz[i];

            if(!bound_check(nx, ny, nz)) continue;
            if(visited[nx][ny][nz] != -1) continue;
            if(arrTmp[nx][ny][nz] == 0) continue;

            q.push({nx, ny, nz});
            visited[nx][ny][nz] = visited[now.x][now.y][now.z] + 1;
            if(visited[nx][ny][nz] >= result) continue;
        }
    }
}

void rotate(int idx){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            arrTmp2[idx][j][N-i-1] = arrTmp[idx][i][j];
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            arrTmp[idx][i][j] = arrTmp2[idx][i][j];
        }
    }
}

void simulation(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            for(int k=0; k<N; k++){
                arrTmp[i][j][k] = arr[location[i]][j][k];
            }
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<rotateArr[i]; j++){
            rotate(i);
        }
    }
    if(arrTmp[startP.x][startP.y][startP.z] == 0 || arrTmp[endP.x][endP.y][endP.z] == 0) return;

    bfs();
}

void make_start_loc(){
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            if(i==j) continue;
            int diff = 0;
            for(int d=0; d<3; d++) if(start_pos[i][d] != start_pos[j][d]) diff++;
            if(diff == 3) {
                startP = {start_pos[i][0], start_pos[i][1], start_pos[i][2]};
                endP = {start_pos[j][0], start_pos[j][1], start_pos[j][2]};

                simulation();
            }
        }
    }
}

void make_rotate_perm(int depth){
    if(depth == N){
        make_start_loc();
        return;
    }

    for(int i=0; i<4; i++){
        rotateArr.push_back(i);

        make_rotate_perm(depth + 1);

        rotateArr.pop_back();
    }
}

void make_perm(int depth){
    if(depth == N){
        make_rotate_perm(0);
        return;
    }

    for(int i=0; i<N; i++){
        if(vstLoc[i]) continue;

        location.push_back(i);
        vstLoc[i] = 1;

        make_perm(depth + 1);

        location.pop_back();
        vstLoc[i] = 0;
    }
}

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            for(int k=0; k<N; k++){
                cin >> arr[i][j][k];
            }
        }
    }

    make_perm(0);

    if(result == 1e9){
        result = -1;
    }

    cout << result << '\n';

    return 0;
}