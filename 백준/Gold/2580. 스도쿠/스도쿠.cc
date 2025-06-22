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

const int N = 9;

int arr[N][N];
int visited1[N][N+1], visited2[N][N+1], visited3[N][N+1];
vector<Point> epy;
bool flag = false;


void dfs(int depth){
    if(flag) return;

    if(depth==epy.size()){
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cout << arr[i][j] << ' ';
            }
            cout << '\n';
        }
        flag = true;
        return;
    }

    Point now = epy[depth];
    int cube = now.x/3*3 + now.y/3;

    for(int i=1; i<=9; i++){
        if(visited1[now.x][i] == 1) continue;
        if(visited2[now.y][i] == 1) continue;
        if(visited3[cube][i] == 1) continue;

        arr[now.x][now.y] = i;
        visited1[now.x][i] = visited2[now.y][i] = visited3[cube][i] = 1;
        
        dfs(depth+1);

        visited1[now.x][i] = visited2[now.y][i] = visited3[cube][i] = 0;
    }
}

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> arr[i][j];

            int cube = i/3*3 + j/3;

            if(arr[i][j] == 0){
                epy.push_back({i, j});
            }
            else{
                visited1[i][arr[i][j]] = 1;
                visited2[j][arr[i][j]] = 1;
                visited3[cube][arr[i][j]] = 1;
            }
        }
    }

    dfs(0);

    return 0;
}