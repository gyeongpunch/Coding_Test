#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <string>

using namespace std;

int N, M;

vector<vector<char>> arr;
vector<vector<int>> visited;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int bfs(){
    queue<tuple<int, int, int, int>> q;
    q.push({0, 0, 1, 1});
    visited[0][0] = 1;

    while(!q.empty()){
        auto[x, y, cnt, distance] = q.front();
        q.pop();
        if(x==N-1 && y==M-1){
            return distance;
        }

        for(int i=0; i<4; i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(0<=nx && nx<N && 0<=ny && ny<M){
                if(cnt==1){
                    if(visited[nx][ny]!=1){
                        if(arr[nx][ny]=='0'){
                            q.push({nx, ny, cnt, distance+1});
                            visited[nx][ny] = 1;
                        }
                        else{
                            q.push({nx, ny, 0, distance+1});
                            visited[nx][ny] = 2;
                        }
                    }
                }
                else{
                    if(visited[nx][ny]==0 && arr[nx][ny]=='0'){
                        q.push({nx, ny, cnt, distance+1});
                        visited[nx][ny] = 2;
                    }
                }
            }
        }
    }
    return -1;
}

int main(void){
    // freopen("input.txt", "r", stdin);

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    arr = vector<vector<char>>(N, vector<char>(M, 0));
    visited = vector<vector<int>>(N, vector<int>(M, 0));

    for(int i=0; i<N; i++){
        string row;
        cin >> row;
        for(int j=0; j<M; j++){
            arr[i][j] = row[j];
        }
    }

    int result = bfs();

    cout << result << endl;

    return 0;
}