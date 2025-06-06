#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <cstring>

using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(nullptr);

const int MX = 10;

int N, M, K;
int result = -40001;
int arr[MX][MX];
int visited[MX][MX];
int nowSum = 0;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool bound_check(int x, int y){
    return 0<=x && x<N && 0<=y && y<M;
}

bool is_avail(int x, int y){
    int nx, ny;
    for(int i=0; i<4; i++){
        nx = x+dx[i];
        ny = y+dy[i];

        if(!bound_check(nx, ny)) continue;
        if(visited[nx][ny] == 1) return false;
    }
    return true;
}

void get_result(int depth, int prev){
    if(depth == K){
        result = max(result, nowSum);
        return;
    }

    for(int idx=prev; idx<N*M; idx++){
        int i = idx/M, j = idx%M;
        if(visited[i][j] == 0 && is_avail(i, j)){
                visited[i][j] = 1;
                nowSum += arr[i][j];

                get_result(depth + 1, idx+1);

                visited[i][j] = 0;
                nowSum -= arr[i][j];
            }
    }
}

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    cin >> N >> M >> K;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> arr[i][j];
        }
    }

    get_result(0, 0);

    cout << result << '\n';

    return 0;
}