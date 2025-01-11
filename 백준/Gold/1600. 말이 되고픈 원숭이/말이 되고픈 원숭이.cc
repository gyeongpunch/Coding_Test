#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;

int K, N, M;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int hx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int hy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

vector<vector<int>> arr;
vector<vector<vector<int>>> visited;

int bfs(){
    queue<tuple<int, int, int>> q;
    q.push({0, 0, K});
    visited[0][0][K] = 0;

    while(!q.empty()){
        auto[x, y, rest] = q.front();
        q.pop();
        if(x==N-1 && y==M-1){
            return visited[x][y][rest];
        }

        if(rest>0){
            for(int i=0; i<8; i++){
                int nx = x+hx[i];
                int ny = y+hy[i];
                if(0<=nx && nx<N && 0<=ny && ny<M && visited[nx][ny][rest-1]==-1 && arr[nx][ny]==0){
                    q.push({nx, ny, rest-1});
                    visited[nx][ny][rest-1] = visited[x][y][rest] + 1;
                }
            }
        }
        for(int i=0; i<4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(0<=nx && nx<N && 0<=ny && ny<M && visited[nx][ny][rest]==-1 && arr[nx][ny]==0){
                q.push({nx, ny, rest});
                visited[nx][ny][rest] = visited[x][y][rest] + 1;
            }
        }
    }
    return -1;

}

int main(void){
    cin >> K >> M >> N;

    arr.resize(N, vector<int>(M, 0));
    visited.resize(N, vector<vector<int>>(M, vector<int>(K+1, -1)));

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> arr[i][j];
        }
    }
    
    int result = bfs();

    cout << result << '\n';

    return 0;
}