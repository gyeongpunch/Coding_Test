#include <iostream>
#include <iomanip>
#include <vector>
#include <cstring>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define MAX_L 40
#define MAX_N 30

struct Night{
    int x, y, h, w, k;
};

struct Point{
    int x, y;
};

struct Info{
    int idx, is_hurt;
};

void nprint();

int L, N, Q;
int arr[MAX_L][MAX_L];
int arrNight[MAX_L][MAX_L];
Night night[MAX_N+1];
int damage[MAX_N+1];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
vector<Info> tmp;
int visited[MAX_N + 1];
bool flag = true;
bool bound_check(int x, int y){
    return 0<=x && x<L && 0<=y && y<L;
}

bool is_okay(int idx, int dir){
    const Night &now = night[idx];
    int nx, ny;

    for(int i=now.x; i<now.x+now.h; i++){
        for(int j=now.y; j<now.y+now.w; j++){
            nx = i + dx[dir];
            ny = j + dy[dir];
 
            if(!bound_check(nx, ny)) return false;
            if(arr[nx][ny] == 2) return false;
        }
    }
    return true;
}

void get_tmp(int idx, int dir){
    Night &now = night[idx];

    int nx, ny;
    for(int i=now.x; i<now.x+now.h; i++){
        for(int j=now.y; j<now.y+now.w; j++){
            nx = i + dx[dir];
            ny = j + dy[dir];
            
            if(!bound_check(nx, ny)){
                flag = false;
                return;
            }
            if(arr[nx][ny] == 2){
                flag = false;
                return;
            }

            if(arrNight[nx][ny] != 0 && idx != arrNight[nx][ny]){
                if(visited[arrNight[nx][ny]] == 0){
                    visited[arrNight[nx][ny]] = 1;
                    tmp.push_back({arrNight[nx][ny], 1});
                    get_tmp(arrNight[nx][ny], dir);
                }
            }
        }
    }
}

void push_night(int idx, int dir){
    visited[idx] = 1;
    tmp.push_back({idx, 0});
    flag = true;
    get_tmp(idx, dir);

    if(!flag){
        return;
    }

    // for(Info info : tmp){
    //     cout << info.idx << ' ' << info.is_hurt << '\n';
    // }
    
    for(int i=tmp.size()-1; i>-1; i--){
        Night &now = night[tmp[i].idx];

        for(int x=now.x; x<now.x+now.h; x++){
            for(int y=now.y; y<now.y+now.w; y++){
                arrNight[x][y] = 0;
            }
        }

        now.x += dx[dir];
        now.y += dy[dir];


        for(int x=now.x; x<now.x+now.h; x++){
            for(int y=now.y; y<now.y+now.w; y++){
                arrNight[x][y] = tmp[i].idx;
    
                if(arr[x][y] == 1 && tmp[i].idx != idx){
                    damage[tmp[i].idx]++;
                }
            }
        }
    
        if(damage[tmp[i].idx] >= now.k){
            for(int x=now.x; x<now.x+now.h; x++){
                for(int y=now.y; y<now.y+now.w; y++){
                    arrNight[x][y] = 0;
                }
            }
        }

    }
}

void simulation(int idx, int dir){
    memset(visited, 0, sizeof(visited));
    tmp.clear();
    push_night(idx, dir);
}

int get_result(){
    int sum = 0;
    for(int i=1; i<=N; i++){
        if(night[i].k > damage[i]){
            sum += damage[i];
        }
    }
    return sum;
}

int main(void){
    fastio;

    // freopen("input.txt", "r", stdin);

    cin >> L >> N >> Q;
    for(int i=0; i<L; i++){
        for(int j=0; j<L; j++){
            cin >> arr[i][j];
        }
    }

    int x, y, h, w, k;
    for(int i=1; i<=N; i++){
        cin >> x >> y >> h >> w >> k;
        x--;
        y--;
        night[i] = {x, y, h, w, k};
        for(int j=x; j<x+h; j++){
            for(int k=y; k<y+w; k++){
                arrNight[j][k] = i;
            }
        }
    }
    // nprint();
    int idx, d;
    for(int i=0; i<Q; i++){
        cin >> idx >> d;
        if(damage[idx] >= night[idx].k) continue;
        simulation(idx, d);
        // nprint();
    }

    cout << get_result() << '\n';

    return 0;
}

void nprint(){
    cout << "===============\n";
    for(int i=0; i<L; i++){
        for(int j=0; j<L; j++){
            cout << setfill(' ') << setw(2) << arrNight[i][j] << ' ';
        }
        cout << '\n';
    }

    cout << '\n';
    for(int i=1; i<=N; i++){
        cout << damage[i] << ' ';
    }
    cout << '\n';

    cout << "===============\n";
}