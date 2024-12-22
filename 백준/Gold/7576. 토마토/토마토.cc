#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int M, N;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0,};

vector<vector<int>> arr;
vector<vector<int>> visited;
queue<pair<int, int>> q;

int bfs(){
    int total = 0;
    while(!q.empty()){
        auto[x, y] = q.front();
        q.pop();
        total = max(total, visited[x][y]);

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0<=nx && nx<N && 0<=ny && ny<M && arr[nx][ny]==0 && visited[nx][ny]==0){
                q.push({nx, ny});
                visited[nx][ny] = visited[x][y] + 1;
                arr[nx][ny] = 1;
            }
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(arr[i][j] == 0){
                return -1;
            }
        }
    }

    return total-1;
}


int main(void){
    cin >> M >> N;

    arr = vector<vector<int>>(N, vector<int>(M, 0));
    visited = vector<vector<int>>(N, vector<int>(M, 0));

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> arr[i][j];
            if(arr[i][j]==1){
                q.push({i, j});
                visited[i][j] = 1;
            }
        }
    }

    cout << bfs() << endl;

    return 0;
}