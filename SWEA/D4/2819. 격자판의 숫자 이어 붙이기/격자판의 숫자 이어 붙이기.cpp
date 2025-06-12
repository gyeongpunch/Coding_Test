#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <cstring>
#include <stack>

using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(nullptr);

const int N = 4;
char arr[N][N];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int result;
unordered_set<string> set;

void init(){
    set.clear();
}

void input(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> arr[i][j];
        }
    }
}

bool bound_check(int x, int y){
    return 0<=x && x<N && 0<=y && y<N;
}

void dfs(int x, int y, int depth, string str){
    if(depth == 6){
        str += arr[x][y];
        set.insert(str);
        return;
    }

    int nx, ny;
    for(int i=0; i<4; i++){
        nx=x+dx[i];
        ny=y+dy[i];

        if(!bound_check(nx, ny)) continue;

        dfs(nx, ny, depth+1, str+arr[x][y]);        
    }
}

void solution(){
    
    string s = "";
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            dfs(i, j, 0, s);
        }
    }

    result = set.size();
}

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    int T;
    cin >> T;
    for(int t=1; t<=T; t++){    
        init();
        input();
        solution();

        cout << '#' << t << ' ' << result << '\n';
    }

    return 0;
}