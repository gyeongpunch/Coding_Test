#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <cstring>

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(nullptr);

using namespace std;

struct Info{
    int cctv, x, y;
};

const int MAX_SIZE = 8;

int N, M, total_cctv = 0;
int arr[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE][MAX_SIZE] = {0};
vector<Info> cctvs;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int min_result;

vector<vector<vector<int>>> total_dirs = {
    {},
    {{0}, {1}, {2}, {3}},
    {{0, 2}, {1, 3}},
    {{0, 1}, {1, 2}, {2, 3}, {3, 0}},
    {{3, 0, 1}, {0, 1, 2}, {1, 2, 3}, {2, 3, 0}},
    {{0, 1, 2, 3}}
};

bool bound_check(int x, int y){
    return 0<=x && x<N && 0<=y && y<M;
}

void gogo_cctv(const vector<int>& dir, int x, int y){
    int cx, cy;
    for(int d : dir){
        cx = x;
        cy = y;
        while(true){
            cx += dx[d];
            cy += dy[d];
            if(!bound_check(cx, cy)) break;
            if(arr[cx][cy] == 6) break;

            visited[cx][cy]++;
        }
    }
}

void remove(const vector<int>& dir, int x, int y){
    int cx, cy;
    for(int d : dir){
        cx = x;
        cy = y;
        while(true){
            cx += dx[d];
            cy += dy[d];
            if(!bound_check(cx, cy)) break;
            if(arr[cx][cy] == 6) break;

            visited[cx][cy]--;
        }
    }
}

void pprint(){
    cout << "==========================\n";
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cout << visited[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << "==========================\n";
}

void calc(){
    int cnt = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(visited[i][j]==0 && arr[i][j]==0){
                cnt++;
            }
        }
    }
    min_result = min(min_result, cnt);
}

void dfs(int depth){
    if(depth == total_cctv){
        calc();
        return;
    }

    Info c_info = cctvs[depth];
    int cctv = c_info.cctv;
    int x = c_info.x;
    int y = c_info.y;

    for(const vector<int> &dirs : total_dirs[cctv]){
        gogo_cctv(dirs, x, y);
        dfs(depth + 1);
        remove(dirs, x, y);
    }
}

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> arr[i][j];
            if(1<=arr[i][j] && arr[i][j]<=5){
                cctvs.push_back({arr[i][j], i, j});
                total_cctv++;
            }
        }
    }


    min_result = N * M;
    dfs(0);

    cout << min_result << '\n';

    return 0;
}