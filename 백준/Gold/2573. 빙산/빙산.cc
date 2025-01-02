#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

vector<vector<int>> arr;
vector<vector<int>> visited;
vector<pair<int, int>> ice;
vector<pair<int, int>> new_ice;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int N, M;

void melt(){
    vector<tuple<int, int, int>> changes;

    for(auto[x, y] : ice){
        int cnt = 0;
        for(int i=0; i<4; i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(0<=nx && nx<N && 0<=ny && ny<M && arr[nx][ny]==0){
                cnt++;
            }
        }
        int new_h = max(arr[x][y] - cnt, 0);
        if(new_h>0){
            new_ice.push_back({x, y});
        }
        changes.push_back({x, y, new_h});
    }
    for(auto[x, y, h] : changes){
        arr[x][y] = h;
    }
    ice = new_ice;
    new_ice.clear();
}

void bfs(int x, int y){
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = 1;

    while(!q.empty()){
        auto[x, y] = q.front();
        q.pop();
        for(int i=0; i<4; i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(0<=nx && nx<N && 0<=ny && ny<M && arr[nx][ny]!=0 && !visited[nx][ny]){
                q.push({nx, ny});
                visited[nx][ny] = 1;
            }
        }
    }
}

bool count_ice(){
    visited = vector<vector<int>>(N, vector<int>(M, 0));
    int cnt=0;
    for(auto[x, y] : ice){
        if(!visited[x][y]){
            if(cnt==1){
                return true;
            }
            bfs(x, y);
            cnt++;
        }
    }
    return false;
}

int simulation(){
    int total = 0;

    while(1){
        melt();

        total++;

        if(count_ice()){
            return total;
        }

        if(ice.empty()){
            return 0;
        }
    }
}

int main(void){
    // freopen("input.txt", "r", stdin);

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    arr = vector<vector<int>>(N, vector<int>(M, 0));

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> arr[i][j];
            if(arr[i][j] != 0){
                ice.push_back({i, j});
            }
        }
    }

    int result = simulation();

    cout << result << endl;

    return 0;
}