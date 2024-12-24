#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void f_bfs(int N, int M, const vector<string>& arr, vector<vector<int>>& f_v, queue<pair<int, int>>& f_loc){
    while(!f_loc.empty()){
        auto[x, y] = f_loc.front();
        f_loc.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0<=nx && nx<N && 0<=ny && ny<M && arr[nx][ny]!='#' && f_v[nx][ny]==-1){
                f_loc.push({nx, ny});
                f_v[nx][ny] = f_v[x][y] + 1;
            }
        }
    }
}

int s_bfs(int N, int M, const vector<string>& arr, const vector<vector<int>>& f_v, vector<vector<int>>& s_v, queue<pair<int, int>>& s_loc){
    while(!s_loc.empty()){
        auto[x, y] = s_loc.front();
        if(x==0 || x==N-1 || y==0 || y==M-1){
            return s_v[x][y] + 1;
        }

        s_loc.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0<=nx && nx<N && 0<=ny && ny<M && arr[nx][ny]!='#' && s_v[nx][ny]==-1 && (f_v[nx][ny]==-1 || f_v[nx][ny] > s_v[x][y] + 1)){
                s_loc.push({nx, ny});
                s_v[nx][ny] = s_v[x][y] + 1;
            }
        }
    }
    return -1;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--){
        int N, M;
        cin >> M >> N;

        vector<string> arr(N);
        vector<vector<int>> f_v(N, vector<int>(M, -1));
        vector<vector<int>> s_v(N, vector<int>(M, -1));
        queue<pair<int, int>> f_loc;
        queue<pair<int, int>> s_loc;

        for(int i=0; i<N; i++){
            cin >> arr[i];
            for(int j=0; j<M; j++){
                if(arr[i][j] == '@'){
                    s_loc.push({i, j});
                    s_v[i][j] = 0;
                }
                else if(arr[i][j] == '*'){
                    f_loc.push({i, j});
                    f_v[i][j] = 0;
                }
            }
        }
        f_bfs(N, M, arr, f_v, f_loc);
        int result = s_bfs(N, M, arr, f_v, s_v, s_loc);

        if(result != -1){
            cout << result << endl;
        }
        else{
            cout << "IMPOSSIBLE" << endl;
        }
    }

    return 0;
}