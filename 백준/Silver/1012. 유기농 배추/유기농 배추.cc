#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int M, N, K;

vector<vector<int>> arr;
vector<vector<int>> visited;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void bfs(int x, int y){
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = 1;

    while(!q.empty()){
        auto[x, y] = q.front();
        q.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0<=nx && nx<N && 0<=ny && ny<M && arr[nx][ny]==1 && visited[nx][ny]==0){
                q.push({nx, ny});
                visited[nx][ny] = 1;
            }
        }
    }

}

int main(void){
    int T;
    cin >> T;

    for(int t=0; t<T; t++){
        cin >> M >> N >> K;
        int cnt = 0;

        arr = vector<vector<int>>(N, vector<int>(M, 0));
        visited = vector<vector<int>>(N, vector<int>(M, 0));
        vector<pair<int, int>> loc;

        for(int i=0; i<K; i++){
            int x, y;
            cin >> y >> x;

            arr[x][y] = 1;
            loc.push_back({x, y});
        }

        for(int i=0; i<K; i++){
            auto[x, y] = loc[i];
            if(arr[x][y]==1 && visited[x][y]==0){
                cnt++;
                bfs(x, y);
            }
        }
        cout << cnt << endl;
    }
    return 0;
}