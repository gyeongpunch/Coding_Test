#include <iostream>
#include <vector>
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define MAX_N 50

struct Atom{
    int m, s, d;
};
void input();
void calc_result();
void move();
int N, M, K;
int result = 0;
vector<Atom> arr[MAX_N][MAX_N];
vector<Atom> arrTmp[MAX_N][MAX_N];
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void seperate_atom(){
    for(int x=0; x<N; x++){
        for(int y=0; y<N; y++){
            if(arrTmp[x][y].empty()) continue;

            else if(arrTmp[x][y].size() == 1) arr[x][y] = arrTmp[x][y];

            else {
                int new_mass = 0;
                int new_speed = 0;
                int is_all_even = 0, is_all_odd = 0;

                for(const Atom &a : arrTmp[x][y]){
                    new_mass += a.m;
                    new_speed += a.s;
                    if(a.d % 2 == 0) is_all_even = 1;
                    else is_all_odd = 1;
                }
                
                new_mass /= 5;
                new_speed /= arrTmp[x][y].size();

                if(is_all_even * is_all_odd == 0){
                    for(int d=0; d<8; d+=2){
                        arr[x][y].push_back({new_mass, new_speed, d});
                    }
                }
                else{
                    for(int d=1; d<8; d+=2){
                        arr[x][y].push_back({new_mass, new_speed, d});
                    }
                }
            }
            arrTmp[x][y].clear();
        }
    }
}

void simulation(){
    move();

    seperate_atom();
}

int main(void){
    fastio;

    // freopen("input.txt", "r", stdin);

    input();

    for(int i=0; i<K; i++){
        simulation();
    }

    calc_result();

    cout << result << '\n';

    return 0;
}

void move(){
    int nx, ny;

    for(int x=0; x<N; x++){
        for(int y=0; y<N; y++){
            if(arr[x][y].empty()) continue;

            for(const Atom &a : arr[x][y]){
                nx = (x + dx[a.d] * a.s) % N;
                ny = (y + dy[a.d] * a.s) % N;
                if(nx < 0) nx += N;
                if(ny < 0) ny += N;

                
                arrTmp[nx][ny].push_back(a);
            }

            arr[x][y].clear();
        }
    }
}

void input(){
    cin >> N >> M >> K;
    int x, y, m, s, d;
    for(int i=0; i<M; i++){
        cin >> x >> y >> m >> s >> d;
        arr[x-1][y-1].push_back({m, s, d});
    }
}

void calc_result(){
    for(int x=0; x<N; x++){
        for(int y=0; y<N; y++){
            if(arr[x][y].empty()) continue;

            for(const Atom &a : arr[x][y]){
                result += a.m;
            }
        }
    }
}