#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <tuple>

using namespace std;

vector<vector<vector<char>>> arr;
vector<vector<vector<int>>> visited;

int L, R, C;

int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

struct Point{
    int x, y, z;
    Point() : x(0), y(0), z(0) {}
    Point(int x, int y, int z) : x(x), y(y), z(z) {}
};

Point Start;
Point End;

int bfs(){
    queue<tuple<int, int, int>> q;
    q.push({Start.x, Start.y, Start.z});
    visited[Start.z][Start.x][Start.y] = 0;

    while(!q.empty()){
        auto[x, y, z] = q.front();
        q.pop();

        if(x==End.x && y==End.y && z==End.z){
            return visited[z][x][y];
        }

        for(int i=0; i<6; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];
            if(0<=nx && nx<R && 0<=ny && ny<C && 0<=nz && nz<L && arr[nz][nx][ny]!='#' && visited[nz][nx][ny]==-1){
                q.push({nx, ny, nz});
                visited[nz][nx][ny] = visited[z][x][y] + 1;
            }
        }
    }
    return -1;
}

int main(void){
    // freopen("input.txt", "r", stdin);

    ios::sync_with_stdio(false);
    cin.tie(0);

    while(1){
        cin >> L >> R >> C;
        if(L==0 && R==0 && C==0) return 0;

        arr = vector<vector<vector<char>>>(L, vector<vector<char>>(R, vector<char>(C)));
        visited = vector<vector<vector<int>>>(L, vector<vector<int>>(R, vector<int>(C, -1)));
        
        for(int i=0; i<L; i++){
            if (i > 0) cin.ignore();
            for(int j=0; j<R; j++){
                string row;
                cin >> row;
                for(int k=0; k<C; k++){
                    arr[i][j][k] = row[k];
                    if(arr[i][j][k] == 'S'){
                        Start = {j, k, i};
                    }
                    if(arr[i][j][k] == 'E'){
                        End = {j, k, i};
                    }
                }
            }
        }

        int result = bfs();

        if(result==-1){
            cout << "Trapped!" << endl;
        }
        else{
            cout << "Escaped in " << result << " minute(s)." << endl;
        }

    }
    return 0;
}