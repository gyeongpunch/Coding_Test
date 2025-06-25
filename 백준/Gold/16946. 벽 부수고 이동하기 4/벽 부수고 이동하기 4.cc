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

const int MX=1000;

int N, M;
char arr[MX][MX];
int visited[MX][MX];
int groupMap[MX][MX];
int groupCnt[MX*MX];
int groupNum=0;
int result[MX][MX];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void print_result(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cout << result[i][j];
        }
        cout << '\n';
    }
}

bool bound_check(int x, int y){
    return 0<=x && x<N && 0<=y && y<M;
}

void bfs(int x, int y, int gn){
    queue<Point> q;
    q.push({x, y});
    visited[x][y] = 1;
    groupMap[x][y] = gn;
    groupCnt[gn]++;

    while(!q.empty()){
        Point now = q.front(); q.pop();

        for(int i=0; i<4; i++){
            int nx=now.x+dx[i];
            int ny=now.y+dy[i];

            if(!bound_check(nx, ny)) continue;
            if(visited[nx][ny] == 1) continue;
            if(arr[nx][ny] != '0') continue;

            q.push({nx, ny});
            visited[nx][ny] = 1;
            groupMap[nx][ny] = gn;
            groupCnt[gn]++;
        }
    }
}

void group_bfs(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(arr[i][j]=='0' && groupMap[i][j]==0){
                bfs(i, j, ++groupNum);
            }
        }
    }
}

void get_result(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(arr[i][j] == '0') continue;

            unordered_set<int> groupSet;
            result[i][j] = 1;
            for(int k=0; k<4; k++){
                int nx=i+dx[k];
                int ny=j+dy[k];
                
                if(!bound_check(nx, ny)) continue;
                if(arr[nx][ny] == '1') continue;
                if(groupSet.find(groupMap[nx][ny]) != groupSet.end()) continue;

                groupSet.insert(groupMap[nx][ny]);
                result[i][j] = (result[i][j] + groupCnt[groupMap[nx][ny]]) % 10;
            }
        }
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

    group_bfs();

    get_result();

    print_result();

    return 0;
}