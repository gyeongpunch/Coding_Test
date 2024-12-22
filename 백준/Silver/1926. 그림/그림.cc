#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int N, M;

vector<vector<int>> arr;
vector<vector<int>> visited;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int bfs(int x, int y){
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = 1;
    int erea = 1;

    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();

        erea = max(erea, visited[x][y]);

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(0<=nx && nx<N && 0<=ny && ny<M && arr[nx][ny]==1 && visited[nx][ny]==0){
                q.push({nx, ny});
                visited[nx][ny] = 1;
                erea++;
            }
        }
    }
    return erea;
}

int main(void){
    cin >> N >> M;
    arr = vector<vector<int>>(N, vector<int>(M));
    visited = vector<vector<int>>(N, vector<int>(M, 0));

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> arr[i][j];
        }
    }

    int cnt = 0, mx = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(arr[i][j] == 1 && visited[i][j] == 0){
                cnt++;
                mx = max(mx, bfs(i, j));
            }
        }
    }

    // for(int i=0; i<N; i++){
    //     for(int j=0; j<M; j++){
    //         cout << visited[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    cout << cnt << endl << mx << endl;

    return 0;
}