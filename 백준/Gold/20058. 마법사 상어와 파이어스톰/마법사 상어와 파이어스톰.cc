#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <cstring>
#include <cmath>

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(nullptr);

using namespace std;

#define MAX_N 64

struct Point{
    int x, y;
};

int N, Q;
int arr[MAX_N][MAX_N];
int arrTmp[MAX_N][MAX_N];
int visited[MAX_N][MAX_N];
int restSum = 0;
int bigSize = 0;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void pprint(){
    cout << "========================\n";
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << "========================\n";
}

void rotate(int l){
    if(l == 0) return;

    int Next = pow(2, l);

    for(int x=0; x<N; x+=Next){
        for(int y=0; y<N; y+=Next){
            for(int i=0; i<Next; i++){
                for(int j=0; j<Next; j++){
                    arrTmp[x+j][y+Next-i-1] = arr[x+i][y+j];
                }
            }
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            arr[i][j] = arrTmp[i][j];
        }
    }
}

bool bound_check(int x, int y){
    return 0<=x && x<N && 0<=y && y<N;
}

void melt(){
    vector<Point> v;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(arr[i][j] == 0) continue;

            int cnt = 0;
            int nx, ny;
            for(int d=0; d<4; d++){
                nx = i + dx[d];
                ny = j + dy[d];

                if(!bound_check(nx, ny)) continue;
                if(arr[nx][ny] > 0) cnt++;
            }

            if(cnt < 3){
                v.push_back({i, j});
            }
        }
    }

    for(const Point &p : v){
        arr[p.x][p.y]--;
    }
}

void bfs(int x, int y){
    queue<Point> q;
    q.push({x, y});
    visited[x][y] = 1;

    int nx, ny;
    int cnt = 0;
    while(!q.empty()){
        Point now = q.front(); q.pop();
        
        cnt++;
        restSum += arr[now.x][now.y];

        for(int i=0; i<4; i++){
            nx = now.x + dx[i];
            ny = now.y + dy[i];

            if(!bound_check(nx, ny)) continue;
            if(arr[nx][ny] == 0) continue;
            if(visited[nx][ny] == 1) continue;

            q.push({nx, ny});
            visited[nx][ny] = 1;
        }
    }

    bigSize = max(bigSize, cnt);
}

void calc(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(arr[i][j] > 0 && visited[i][j] == 0){
                bfs(i, j);
            }
        }
    }
}

void simulation(int l){
    // pprint();
    rotate(l);
    // pprint();
    melt();
    // pprint();
}

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    cin >> N >> Q;
    N = pow(2, N);

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> arr[i][j];
        }
    }
    int l;
    for(int i=0; i<Q; i++){
        cin >> l;
        simulation(l);
    }

    calc();

    cout << restSum << '\n' << bigSize << '\n';

    return 0;
}