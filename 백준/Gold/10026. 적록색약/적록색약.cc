#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int N;
vector<vector<char>> arr;
vector<vector<int>> visited;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void bfs(int x, int y, bool is_nono){
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y]++;

    while(!q.empty()){
        auto[cx, cy] = q.front();
        q.pop();

        for(int i=0; i<4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(0 <= nx && nx < N && 0 <= ny && ny < N && visited[nx][ny] == visited[cx][cy] - 1){
                if(is_nono){
                    if (arr[nx][ny]!='B' && arr[cx][cy]!='B'){
                        q.push({nx, ny});
                        visited[nx][ny]++;
                    }
                    else if(arr[nx][ny]=='B' && arr[cx][cy]=='B'){
                        q.push({nx, ny});
                        visited[nx][ny]++;
                    }
                    
                }
                else{
                    if(arr[nx][ny]==arr[cx][cy]){
                        q.push({nx, ny});
                        visited[nx][ny]++;
                    }
                }
            }
        }
    }

}

int main(void){
    cin >> N;
    arr = vector<vector<char>> (N, vector<char>(N, ' '));
    visited = vector<vector<int>> (N, vector<int>(N, 0));

    for(int i=0; i<N; i++){
        string str;
        cin >> str;
        for(int j=0; j<str.size(); j++){
            arr[i][j] = str[j];
        }
    }

    int normal = 0;
    int nonormal = 0;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(visited[i][j]==0){
                bfs(i, j, false);
                normal++;
            }
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(visited[i][j]==1){
                bfs(i, j, true);
                nonormal++;
            }
        }
    }

    cout << normal << ' ' << nonormal << endl;

    return 0;
}