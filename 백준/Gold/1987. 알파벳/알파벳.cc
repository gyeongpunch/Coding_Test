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

const int MX = 20;

int N, M;
char arr[MX][MX];
int visited[26];
int result;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool bound_check(int x, int y){
    return 0<=x && x<N && 0<=y && y<M;
}

void dfs(int depth, int x, int y){
    result = max(result, depth);

    // cout << x << ' ' << y << '\n';

    for(int i=0; i<4; i++){
        int nx=x+dx[i];
        int ny=y+dy[i];

        if(!bound_check(nx, ny)) continue;
        if(visited[arr[nx][ny]-'A']==1) continue;

        visited[arr[nx][ny]-'A'] = 1;

        dfs(depth+1, nx, ny);

        visited[arr[nx][ny]-'A'] = 0;
    }
}

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> arr[i][j];
        }
    }

    visited[arr[0][0]-'A'] = 1;
    dfs(1, 0, 0);

    cout << result << '\n';

    return 0;
}