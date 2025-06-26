#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <cstring>

using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(nullptr);

struct Info{
    int x, y, t;
};

const int N = 8;

char arr[N][N];
int dx[9] = {-1, -1, -1, 0, 1, 1, 1, 0, 0};
int dy[9] = {-1, 0, 1, 1, 1, 0, -1, -1, 0};

bool bound_check(int x, int y){
    return 0<=x && x<N && 0<=y && y<N;
}

void drop_wall(int& prev){
    prev++;
    for(int x=N-1; x>-1; x--){
        for(int y=0; y<N; y++){
            if(arr[x][y] == '#'){
                if(x==N-1){
                    arr[x][y] = '.';
                }
                else{
                    arr[x][y] = '.';
                    arr[x+1][y] = '#';
                }
            }
        }
    }
}

int bfs(){
    queue<Info> q;
    q.push({N-1, 0, 0});
    int prev = 0;
    while(!q.empty()){
        Info now = q.front(); q.pop();

        if(now.t==8) return 1;
        if(now.t != prev) drop_wall(prev);

        for(int i=0; i<9; i++){
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if(!bound_check(nx, ny)) continue;
            if(arr[nx][ny] == '#') continue;
            if(nx!=0 && arr[nx-1][ny] == '#') continue;

            q.push({nx, ny, now.t+1});
        }
    }
    return 0;
}

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> arr[i][j];
        }
    }

    int result = bfs();

    cout << result << '\n';

    return 0;
}