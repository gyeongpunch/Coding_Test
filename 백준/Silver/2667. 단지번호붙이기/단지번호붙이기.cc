#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;
vector<string> arr;
vector<vector<int>> visited;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int bfs(int x, int y){
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = 1;
    int size=1;

    while(!q.empty()){
        auto[x, y] = q.front();
        q.pop();
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0<=nx && nx<N && 0<=ny && ny<N && arr[nx][ny]=='1' && visited[nx][ny]==0){
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

    cin >> N;
    arr = vector<string>(N, " ");
    visited = vector<vector<int>>(N, vector<int>(N, 0));

    for(int i=0; i<N; i++){
        cin >> arr[i];
    }

    vector<int> result;
    int cnt;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(arr[i][j]=='1' && visited[i][j]==0){
                cnt++;
                result.push_back(bfs(i, j));
            }
        }
    }

    sort(result.begin(), result.end());

    cout << cnt << endl;
    for(int i=0; i<result.size(); i++){
        cout << result[i] << '\n';
    }

    return 0;
}