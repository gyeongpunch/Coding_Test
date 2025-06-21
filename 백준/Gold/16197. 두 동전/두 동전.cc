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

struct Point{
    int x, y;
};

const int MX = 20;

int N, M;
char arr[MX][MX];
int visited[MX][MX][MX][MX];
Point coin1 = {-1, -1}, coin2={-1, -1};
int result = 1e9;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool bound_check(int x, int y){
    return 0<=x && x<N && 0<=y && y<M;
}

void dfs(int depth, Point c1, Point c2){
    if(depth >= 10) return;
    if(c1.x==c2.x && c1.y==c2.y) return;
    if(result <= depth) return;

    for(int i=0; i<4; i++){
        Point c11 = {c1.x+dx[i], c1.y+dy[i]};
        Point c22 = {c2.x+dx[i], c2.y+dy[i]};

        // cout << c11.x << ' ' << c11.y << ' ' << c22.x << ' ' << c22.y << "\n\n";

        if(!bound_check(c11.x, c11.y) && !bound_check(c22.x, c22.y)) continue ;

        if(!bound_check(c11.x, c11.y) || !bound_check(c22.x, c22.y)){
            result = min(result, depth+1);
            return;
        }

        int cnt = 0;
        if(arr[c11.x][c11.y]=='#') {
            c11 = c1;
            cnt++;
        }
        if(arr[c22.x][c22.y]=='#') {
            c22 = c2;
            cnt++;
        }
        if(cnt == 2) continue;

        // cout << depth + 1 << '\n';
        // cout << c11.x << ' ' << c11.y << ' ' << c22.x << ' ' << c22.y << "\n\n";

        if(visited[c11.x][c11.y][c22.x][c22.y] == 1) continue;

        visited[c11.x][c11.y][c22.x][c22.y] = 1;
        dfs(depth+1, c11, c22);
        visited[c11.x][c11.y][c22.x][c22.y] = 0;
    }
}

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    cin >> N >> M;
    char c;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> c;
            if(c=='o'){
                if(coin1.x == -1) coin1 = {i, j};
                else coin2 = {i, j};
                c = '.';
            }
            arr[i][j] = c;
        }
    }

    // cout << coin1.x << ' ' << coin1.y << ' ' << coin2.x << ' ' << coin2.y << "\n\n";


    visited[coin1.x][coin1.y][coin2.x][coin2.y] = 1;
    dfs(0, coin1, coin2);

    if(result == 1e9) result = -1;

    cout << result << '\n';

    return 0;
}