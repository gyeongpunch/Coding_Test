#include <iostream>
#include <queue>
#include <string>
#include <climits>
#include <unordered_set>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

const int N = 5;

int arr[N][N];
unordered_set<int> Set;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool bound_check(int x, int y){
    return 0<=x && x<N && 0<=y && y<N;
}

void dfs(int x, int y, int depth, int num){
    if(depth == 6){
        Set.insert(num);
        return;
    }

    for(int i=0; i<4; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];

        if(!bound_check(nx, ny)) continue;

        int nNum = num*10 + arr[nx][ny];

        dfs(nx, ny, depth+1, nNum);
    }
}

void get_result(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            dfs(i, j, 1, arr[i][j]);
        }
    }
}

int main(void) {
    fastio;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> arr[i][j];
        }
    }

    get_result();

    cout << Set.size() << '\n';
    
    return 0; 
}
