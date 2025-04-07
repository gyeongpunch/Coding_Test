#include <iostream>
#include <iomanip>
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
void nprint();

int L, N, Q;
int arr[MAX_L][MAX_L];
int arrNight[MAX_L][MAX_L];
Night night[MAX_N+1];
int damage[MAX_N+1];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool bound_check(int x, int y){
    return 0<=x && x<L && 0<=y && y<L;
}

void push_night(int idx, int dir, int is_hurt){
    Night &now = night[idx];

    int nx, ny;
    for(int i=now.x; i<now.x+now.h; i++){
        for(int j=now.y; j<now.y+now.w; j++){
            nx = i + dx[dir];
            ny = j + dy[dir];
 
            if(!bound_check(nx, ny)) return;
            if(arr[nx][ny] == 2) return;
        }
    }


    for(int i=now.x; i<now.x+now.h; i++){
        for(int j=now.y; j<now.y+now.w; j++){
            nx = i + dx[dir];
            ny = j + dy[dir];
 
            if(!bound_check(nx, ny)) return;
            if(arr[nx][ny] == 2) return;

            if(arrNight[nx][ny] != 0 && idx != arrNight[nx][ny]){
                push_night(arrNight[nx][ny], dir, 1);
                
                if(arrNight[nx][ny] != 0){
                    return;
                }
            }
        }
    }

    // nprint();
    // cout << "idx : " << idx << ' ' << is_hurt << '\n';
    for(int i=now.x; i<now.x+now.h; i++){
        for(int j=now.y; j<now.y+now.w; j++){
            arrNight[i][j] = 0;
        }
    }

    now.x += dx[dir];
    now.y += dy[dir];

    for(int i=now.x; i<now.x+now.h; i++){
        for(int j=now.y; j<now.y+now.w; j++){
            arrNight[i][j] = idx;

            if(arr[i][j] == 1 && is_hurt == 1){
                damage[idx]++;
            }
        }
    }

    if(damage[idx] >= now.k){
        for(int i=now.x; i<now.x+now.h; i++){
            for(int j=now.y; j<now.y+now.w; j++){
                arrNight[i][j] = 0;
            }
        }
    }

}

void simulation(int idx, int dir){
    
    push_night(idx, dir, 0);
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