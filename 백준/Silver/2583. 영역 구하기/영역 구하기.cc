#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, K;
vector<vector<int>> arr;
vector<vector<int>> visited;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int bfs(int x, int y){
    int size = 1;
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = 1;

    while(!q.empty()){
        auto[x, y] = q.front();
        q.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0<=nx && nx<N && 0<=ny && ny<M && arr[nx][ny]==0 && visited[nx][ny]==0){
                q.push({nx, ny});
                visited[nx][ny] = 1;
                size++;
            }
        }
    }
    return size;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);


    cin >> N >> M >> K;
    arr = vector<vector<int>>(N, vector<int>(M, 0));
    visited = vector<vector<int>>(N, vector<int>(M, 0));

    while(K--){
        int x1, y1, x2, y2;
        cin >> y1 >> x1 >> y2 >> x2;

        for(int i=x1; i<x2; i++){
            for(int j=y1; j<y2; j++){
                arr[i][j]++;
            }
        }
    }
    vector<int> result;
    int cnt = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(arr[i][j]==0 && visited[i][j]==0){
                result.push_back(bfs(i, j));
                cnt++;
            }
        }
    }

    sort(result.begin(), result.end());

    cout << cnt << endl;
    for(int i=0; i<result.size(); i++){
        cout << result[i] << ' ';
    }
    cout << endl;

    return 0;
}