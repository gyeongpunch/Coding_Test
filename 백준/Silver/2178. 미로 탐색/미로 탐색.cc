#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int N, M;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

vector<vector<int>> arr;
vector<vector<int>> visited;

int bfs(){
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = 1;

    while(!q.empty()){
        auto[x, y] = q.front();
        q.pop();

        if(x==N-1 && y==M-1){
            return visited[x][y];
        }

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0<=nx && nx<N && 0<=ny && ny<M && arr[nx][ny]==1 && visited[nx][ny]==0){
                q.push({nx, ny});
                visited[nx][ny] = visited[x][y] + 1;
            }
        }
    }
    return -1;
}

int main(void){
    cin >> N >> M;
    arr = vector<vector<int>>(N, vector<int>(M, 0));
    visited = vector<vector<int>>(N, vector<int>(M, 0));

    for(int i=0; i<N; i++){
        string str;
        cin >> str;
        for(int j=0; j<str.size(); j++){
            arr[i][j] = str[j] - '0';
        }
    }
    
    cout << bfs() << endl;

    return 0;
}