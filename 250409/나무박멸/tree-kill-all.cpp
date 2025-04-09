#include <iostream>
#include <cstring>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define MAX_N 20

struct Point{
    int x, y;
};

bool bound_check(int x, int y);
void input();
void pprint();
void grow();
void spread();
void dprint();

int N, M, K, C;
int arrTree[MAX_N][MAX_N];
int arrTreeTmp[MAX_N][MAX_N];
int deathTimer[MAX_N][MAX_N];
int result = 0;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int ddx[4] = {-1, -1, 1, 1};
int ddy[4] = {-1, 1, -1, 1};

void one_kill_simul(int x, int y, Point &maxKillPoint, int &maxKill){
    int sum = arrTree[x][y];

    int nx, ny;
    for(int i=0; i<4; i++){
        for(int j=1; j<=K; j++){
            nx = x + ddx[i] * j;
            ny = y + ddy[i] * j;

            if(!bound_check(nx, ny)) break;
            if(arrTree[nx][ny] == -1) break;    
            if(deathTimer[nx][ny] == 0){
                sum += arrTree[nx][ny];
            }
            if(arrTree[nx][ny] == 0) break;
        }
    }

    if(maxKill < sum){
        maxKill = sum;
        maxKillPoint = {x, y};
    }
}

void gogo_kill(const Point &now, int t){
    int nx, ny;
    deathTimer[now.x][now.y] = t;
    for(int i=0; i<4; i++){
        for(int j=1; j<=K; j++){
            nx = now.x + ddx[i] * j;
            ny = now.y + ddy[i] * j;

            if(!bound_check(nx, ny)) break;
            if(arrTree[nx][ny] == -1) break;

            deathTimer[nx][ny] = t;

            if(arrTree[nx][ny] == 0) break;
        }
    }
}

void kill_grass(int t){
    Point maxKillPoint;
    int maxKill = -1;

    for(int x=0; x<N; x++){
        for(int y=0; y<N; y++){
            if(arrTree[x][y] <= 0) continue;
            if(deathTimer[x][y] != 0) continue;

            one_kill_simul(x, y, maxKillPoint, maxKill);
        }
    }

    result += maxKill;
    gogo_kill(maxKillPoint, t);
}

void remove_death(int nowTime){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(deathTimer[i][j] == 0) continue;

            if(deathTimer[i][j] == nowTime - C){
                deathTimer[i][j] = 0;
                arrTree[i][j] = 0;
            }
        }
    }
}

void simulation(int t){
    grow();
    // pprint();

    spread();
    // pprint();

    kill_grass(t);
    // dprint();
    remove_death(t);
}

int main(void){
    fastio;

    // freopen("input.txt", "r", stdin);

    input();

    for(int t=1; t<=M; t++){
        simulation(t);
        // pprint();
        // dprint();
    }

    cout << result << '\n';

    return 0;
}

void spread(){
    memset(arrTreeTmp, 0, sizeof(arrTreeTmp));

    int nx, ny;

    for(int x=0; x<N; x++){
        for(int y=0; y<N; y++){
            if(arrTree[x][y] <= 0) continue;
            if(deathTimer[x][y] != 0) continue;

            int cnt = 0;
            for(int i=0; i<4; i++){
                nx = x+dx[i];
                ny = y+dy[i];

                if(!bound_check(nx, ny)) continue;
                if(arrTree[nx][ny] != 0) continue;
                if(deathTimer[nx][ny] != 0) continue;

                cnt++;
            }

            arrTreeTmp[x][y] += arrTree[x][y];

            for(int i=0; i<4; i++){
                nx = x+dx[i];
                ny = y+dy[i];

                if(!bound_check(nx, ny)) continue;
                if(deathTimer[nx][ny] != 0) continue;
                if(arrTree[nx][ny] != 0) continue;
                
                arrTreeTmp[nx][ny] += arrTree[x][y] / cnt;
            }
        }
    }

    for(int x=0; x<N; x++){
        for(int y=0; y<N; y++){
            if(arrTreeTmp[x][y] <= 0) continue;
            if(deathTimer[x][y] != 0) continue;

            arrTree[x][y] = arrTreeTmp[x][y];
        }
    }
}

void grow(){
    int nx, ny;

    for(int x=0; x<N; x++){
        for(int y=0; y<N; y++){
            if(arrTree[x][y] <= 0) continue;
            if(deathTimer[x][y] != 0) continue;

            int cnt = 0;
            for(int i=0; i<4; i++){
                nx = x+dx[i];
                ny = y+dy[i];

                if(!bound_check(nx, ny)) continue;
                if(arrTree[nx][ny] <= 0) continue;
                if(deathTimer[nx][ny] != 0) continue;

                cnt++;
            }

            arrTree[x][y] += cnt;
        }
    }
}

void input(){
    cin >> N >> M >> K >> C;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> arrTree[i][j];
        }
    }
}

bool bound_check(int x, int y){
    return 0<=x && x<N && 0<=y && y<N;
}


void pprint(){
    cout << "====================\n";
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << arrTree[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << "====================\n";
}

void dprint(){
    cout << "====================\n";
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << deathTimer[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << "====================\n";
}