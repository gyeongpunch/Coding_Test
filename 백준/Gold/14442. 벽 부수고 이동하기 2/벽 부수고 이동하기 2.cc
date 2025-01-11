#include <iostream>
#include <tuple>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int N, M, K;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

vector<vector<int>> arr;
vector<vector<vector<int>>> visited;

int bfs(){
    queue<tuple<int, int, int>> q;
    q.push({0, 0, 0});
    visited[0][0][0] = 1;

    while(!q.empty()){
        auto[x, y, cnt] = q.front();
        q.pop();

        if(x==N-1 && y==M-1){
            return visited[x][y][cnt];
        }

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0<=nx && nx<N && 0<=ny && ny<M){
                if(cnt<K){
                    if(arr[nx][ny]==1 && visited[nx][ny][cnt+1]==0){
                        q.push({nx, ny, cnt+1});
                        visited[nx][ny][cnt+1] = visited[x][y][cnt] + 1;
                    }
                    else if(arr[nx][ny]==0 && visited[nx][ny][cnt]==0){
                        q.push({nx, ny, cnt});
                        visited[nx][ny][cnt] = visited[x][y][cnt] + 1;
                    }
                }
                else{
                    if(arr[nx][ny]==0 && visited[nx][ny][cnt]==0){
                        q.push({nx, ny, cnt});
                        visited[nx][ny][cnt] = visited[x][y][cnt] + 1;
                    }
                }
            }
        }
    }
    return -1;
}

int main(void){
    // freopen("input.txt", "r", stdin);

    cin >> N >> M >> K;
    
    arr = vector<vector<int>>(N, vector<int>(M, 0));
    visited = vector<vector<vector<int>>>(N, vector<vector<int>>(M, vector<int>(K+1, 0)));

    for(int i=0; i<N; i++){
        string row;
        cin >> row;
        for(int j=0; j<M; j++){
            arr[i][j] = row[j] - '0';
        }
    }

    int result = bfs();

    cout << result << '\n';

    return 0;
}