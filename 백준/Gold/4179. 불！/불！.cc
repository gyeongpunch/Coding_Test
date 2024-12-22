#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

int N, M;

vector<vector<char>> arr;
vector<vector<int>> j_visited;
vector<vector<int>> f_visited;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

queue<pair<int, int>> f_q;
queue<pair<int, int>> j_q;

void f_bfs(){
    while(!f_q.empty()){
        auto[x, y] = f_q.front();
        f_q.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0<=nx && nx<N && 0<=ny && ny<M && arr[nx][ny]!='#' && f_visited[nx][ny]==-1){
                f_q.push({nx, ny});
                f_visited[nx][ny] = f_visited[x][y] + 1;
            }
        }
    }
}

int j_bfs(){
    while(!j_q.empty()){
        auto[x, y] = j_q.front();
        j_q.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx<0 || nx>=N || ny<0 || ny>=M){
                return j_visited[x][y] + 1;
            }

            if(0<=nx && nx<N && 0<=ny && ny<M && arr[nx][ny]!='#' && j_visited[nx][ny]==-1 && (f_visited[nx][ny]==-1 || f_visited[nx][ny] > j_visited[x][y] + 1)){
                j_q.push({nx, ny});
                j_visited[nx][ny] = j_visited[x][y] + 1;
            }
        }
    }
    return -1;
}

int main(void){
    cin >> N >> M;

    arr = vector<vector<char>>(N, vector<char>(M, ' '));
    j_visited = vector<vector<int>>(N, vector<int>(M, -1));
    f_visited = vector<vector<int>>(N, vector<int>(M, -1));

    for(int i=0; i<N; i++){
        string str;
        cin >> str;
        for(int j=0; j<str.size(); j++){
            arr[i][j] = str[j];
            if(arr[i][j] == 'F'){
                f_q.push({i, j});
                f_visited[i][j] = 0;
            }
            else if(arr[i][j] == 'J'){
                j_q.push({i, j});
                j_visited[i][j] = 0;
            }
        }
    }

    f_bfs();

    int result = j_bfs();
    if(result==-1){
        cout << "IMPOSSIBLE" << endl;
    }
    else{
        cout << result << endl;
    }

    return 0;
}