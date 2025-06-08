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
    int x, y;
};

const int MX = 16;

int N;
int arr[MX][MX];
int visited[MX][MX];
int result = 0;

bool bound_check(int x, int y){
    return 0<=x && x<N && 0<=y && y<N;
}

void simulation(int x, int y){
    if(x == N-1 && y == N-1){
        result++;
        return;
    }

    int nx, ny;
    for(int idx=1; idx<=3; idx++){
        if(idx==1){
            if(visited[x][y] == 3) continue;
            ny = y + 1;

            if(!bound_check(x, ny)) continue;
            if(arr[x][ny] == 1) continue;
            visited[x][ny] = 1;
            simulation(x, ny);
            visited[x][ny] = 0;
        }
        else if(idx==2){
            nx = x + 1;
            ny = y + 1;

            if(!bound_check(nx, ny)) continue;
            if(arr[x][y]==1 || arr[x+1][y]==1 || arr[x][y+1]==1 || arr[x+1][y+1]==1) continue;
            visited[nx][ny] = 2;
            simulation(nx, ny);
            visited[nx][ny] = 0;
        }
        else{
            if(visited[x][y] == 1) continue;
            nx = x + 1;

            if(!bound_check(nx, y)) continue;
            if(arr[nx][y] == 1) continue;
            visited[nx][y] = 3;
            simulation(nx, y);
            visited[nx][y] = 0;
        }
    }

}

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> arr[i][j];
        }
    }
    visited[0][0] = visited[0][1] = 1;

    simulation(0, 1);

    cout << result << '\n';

    return 0;
}