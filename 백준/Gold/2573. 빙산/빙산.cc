#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int arr[300][300];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

vector<pair<int, int>> ice;
vector<pair<int, int>> new_ice;

void bfs(int x, int y, vector<vector<int>>& visited){
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = 1;

    while(!q.empty()){
        auto[cx, cy] = q.front();
        q.pop();

        for(int i=0; i<4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(0<=nx && nx<N && 0<=ny && ny<M && arr[nx][ny]>0 && visited[nx][ny]==0){
                q.push({nx, ny});
                visited[nx][ny] = 1;
            }
        }
    }
}

int Count(){
    vector<vector<int>> visited(N, vector<int>(M, 0));

    int cnt=0;
    for(auto[x, y] : ice){
        if(arr[x][y] > 0 && visited[x][y]==0){
            bfs(x, y, visited);
            cnt++;
            if(cnt >= 2){
                return cnt;
            }
        }
    }
    return cnt;
}

void Melt(){
    vector<tuple<int, int, int>> change;
    for(auto[x, y] : ice){
        int cnt = 0;
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0<=nx && nx<N && 0<=ny && ny<M && arr[nx][ny]==0){
                cnt++;
            }
        }
        int rest = max(arr[x][y]-cnt, 0);
        change.push_back({x, y, rest});
        if(rest>0){
            new_ice.push_back({x, y});
        }
    }
    for(auto[x, y, i] : change){
        arr[x][y] = i;
    }
    ice = new_ice;
    new_ice.clear();
}

int main(void){
    // freopen("input.txt", "r", stdin);

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> arr[i][j];
            if(arr[i][j]>0){
                ice.push_back({i, j});
            }
        }
    }

    int result = 0;
    while(1){
        Melt();
        result++;
        int num = Count();
        if(num >= 2){
            break;
        }
        else if(num==0){
            result = 0;
            break;
        }
    }

    cout << result << '\n';

    return 0;
}