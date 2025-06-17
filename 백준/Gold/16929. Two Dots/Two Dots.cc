#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <queue>
#include <cstring>

using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(nullptr);

const int MX = 50;

int N, M;
char arr[MX][MX];
int visited[MX][MX];
int cycle[MX][MX];
string result = "No";

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool bound_check(int x, int y){
    return 0<=x && x<N && 0<=y && y<M;
}

void dfs(int x, int y, char target){

    for(int i=0; i<4; i++){
        int nx=x+dx[i];
        int ny=y+dy[i];

        if(!bound_check(nx, ny)) continue;
        if(arr[nx][ny] != target) continue;

        

        if(visited[nx][ny] != 0) {
            if(cycle[nx][ny]-cycle[x][y] >= 3){
                result = "Yes";
                return;
            }
            continue;
        }
        else{
            visited[nx][ny] = target-'A'+1;
            cycle[nx][ny] = cycle[x][y] + 1;
            dfs(nx, ny, target);
        }
    }
}

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    cin >> N >> M;
    string s;
    for(int i=0; i<N; i++){
        cin >> s;
        for(int j=0; j<M; j++){
            arr[i][j] = s[j];
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(visited[i][j] != 0) continue;

            cycle[i][j] = 1;
            visited[i][j] = arr[i][j]-'A'+1;
            dfs(i, j, arr[i][j]);
        }
    }

    // for(int i=0; i<N; i++){
    //     for(int j=0; j<M; j++){
    //         cout << visited[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';

    // for(int i=0; i<N; i++){
    //     for(int j=0; j<M; j++){
    //         cout << cycle[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';

    cout << result << '\n';

    return 0;
}