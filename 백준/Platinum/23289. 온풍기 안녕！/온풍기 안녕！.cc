#include <iostream>
#include <vector>
#include <cstring>
#include <unordered_map>
using namespace std;

const int MX = 20;

struct Point{
    int x, y;
};

int N, M, K;
int arr[MX][MX];
int cool[MX][MX];
int coolTmp[MX][MX];
int wall[MX][MX][4];
int visited[MX][MX];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
vector<Point> air_condition;
int result;

bool bound_check(int x, int y){
    return 0<=x && x<N && 0<=y && y<M;
}

bool wall_check(int x, int y, int d){
    return wall[x][y][d] == 0;
}

void input(){
    cin >> N >> M >> K;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> arr[i][j];
            if(1<=arr[i][j] && arr[i][j]<=4){
                air_condition.push_back({i, j});
            }
        }
    }
    int L;
    cin >> L;
    int x, y, d;
    for(int i=0; i<L; i++){
        cin >> x >> y >> d;
        x--; y--;
        if(d==0) d = 2;
		else d = 0;
        int nx = x+dx[d];
        int ny = y+dy[d];
        wall[x][y][d] = 1;
        wall[nx][ny][d+1] = 1;
    }
}

unordered_map<int, int> ld = {
	{0, 2}, {1, 3}, {2, 1}, {3, 0}
};
unordered_map<int, int> rd = {
	{0, 3}, {1, 2}, {2, 0}, {3, 1}
};

void wind(int x, int y, int d, int w){
    if(w == 0) return;
    int lx = x + dx[ld[d]];
    int ly = y + dy[ld[d]];
    int rx = x + dx[rd[d]];
    int ry = y + dy[rd[d]];
    int nx = x + dx[d];
    int ny = y + dy[d];
    
    cool[x][y] += w;
    visited[x][y] = 1;

    if(bound_check(lx, ly) && wall_check(x, y, ld[d]) && wall_check(lx, ly, d)){
        int llx = lx + dx[d];
        int lly = ly + dy[d];
        
        if(bound_check(llx, lly) && visited[llx][lly]==0) wind(llx, lly, d, w-1);
    }
    if(bound_check(rx, ry) && wall_check(x, y, rd[d]) && wall_check(rx, ry, d)){
        int rrx = rx + dx[d];
        int rry = ry + dy[d];
        if(bound_check(rrx, rry) && visited[rrx][rry]==0) wind(rrx, rry, d, w-1);
    }
    if(bound_check(nx, ny) && wall_check(x, y, d) && visited[nx][ny]==0){
        wind(nx, ny, d, w-1);
    }
}

void air_conditioner(){
    for(const Point &p : air_condition){
        memset(visited, 0, sizeof(visited));
        int d = arr[p.x][p.y] - 1;
        int nx = p.x + dx[d];
        int ny = p.y + dy[d];
        if(!bound_check(nx, ny)) continue;
        wind(nx, ny, d, 5);
    }
}

void mix(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            coolTmp[i][j] = cool[i][j];
        }
    }

    for(int x=0; x<N; x++){
        for(int y=0; y<M; y++){
            if(cool[x][y] == 0) continue;
            for(int i=0; i<4; i++){
                int nx = x+dx[i];
                int ny = y+dy[i];

                if(!bound_check(nx, ny)) continue;
                if(cool[x][y] < cool[nx][ny]) continue;
                if(!wall_check(x, y, i)) continue;
                int dist = (cool[x][y] - cool[nx][ny]) / 4;
                coolTmp[x][y] -= dist;
                coolTmp[nx][ny] += dist;
            }
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cool[i][j] = coolTmp[i][j];
        }
    }

}

void warm(){
    for(int i=1; i<N-1; i++){
        if(cool[i][0] != 0) cool[i][0]--;
        if(cool[i][M-1] != 0) cool[i][M-1]--;
    }
    for(int i=1; i<M-1; i++){
        if(cool[0][i] != 0) cool[0][i]--;
        if(cool[N-1][i] != 0) cool[N-1][i]--;
    }
    if(cool[0][0] != 0) cool[0][0]--;
    if(cool[0][M-1] != 0) cool[0][M-1]--;
    if(cool[N-1][0] != 0) cool[N-1][0]--;
    if(cool[N-1][M-1] != 0) cool[N-1][M-1]--;
}

bool all_check(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(arr[i][j]==5 && cool[i][j] < K) return false;
        }
    }
    return true;
}

int simulation(){
    for(int i=1; i<=100; i++){
        air_conditioner();

        mix();
        
        warm();

        if(all_check()) return i;
    }
    return 101;
}

int main(void){
    input();

    result = simulation();

    cout << result << '\n';

    return 0;
}