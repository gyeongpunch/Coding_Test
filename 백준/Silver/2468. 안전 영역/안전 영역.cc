#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;
vector<vector<int>> arr;
vector<vector<int>> visited;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void bfs(int x, int y, int h){
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = 1;

    while(!q.empty()){
        auto[x, y] = q.front();
        q.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0<=nx && nx<N && 0<=ny && ny<N && arr[nx][ny]>h && visited[nx][ny]==0){
                q.push({nx, ny});
                visited[nx][ny] = 1;
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    arr = vector<vector<int>>(N, vector<int>(N, 0));
    int max_h = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> arr[i][j];
            max_h = max(max_h, arr[i][j]);
        }
    }

    int max_cnt = 0;
    for(int h=0; h<=max_h; h++){
        visited = vector<vector<int>>(N, vector<int>(N, 0));
        int cnt = 0;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(arr[i][j]>h && visited[i][j]==0){
                    bfs(i, j, h);
                    cnt++;
                }
            }
        }
        max_cnt = max(max_cnt, cnt);
    }

    cout << max_cnt << endl;

    return 0;
}
