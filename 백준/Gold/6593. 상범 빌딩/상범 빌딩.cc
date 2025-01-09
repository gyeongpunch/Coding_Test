#include <iostream>
#include <string>
#include <queue>

using namespace std;

int L, R, C;

char arr[30][30][30];

struct Point{
    int x, y, z;
};
Point Start;
Point End;

int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int bfs(){
    int visited[30][30][30] = {0};
    queue<Point> q;
    q.push(Start);
    visited[Start.z][Start.x][Start.y] = 1;

    while(!q.empty()){
        int cx = q.front().x;
        int cy = q.front().y;
        int cz = q.front().z;
        q.pop();

        if(cx==End.x && cy==End.y && cz==End.z){
            return visited[cz][cx][cy] - 1;
        }

        for(int i=0; i<6; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            int nz = cz + dz[i];
            if(0<=nx && nx<R && 0<=ny && ny<C && 0<=nz && nz<L && arr[nz][nx][ny]!='#' && visited[nz][nx][ny]==0){
                q.push({nx, ny, nz});
                visited[nz][nx][ny] = visited[cz][cx][cy] + 1;
            }
        }
    }
    return -1;
}

int main(void){
    // freopen("input.txt", "r", stdin);

    ios::sync_with_stdio(false);
    cin.tie(0);

    while (1){
        cin >> L >> R >> C;
        if(L==0 && R==0 && C==0){
            break;
        }
        for(int i=0; i<L; i++){
            for(int j=0; j<R; j++){
                string row;
                cin >> row;
                for(int k=0; k<C; k++){
                    arr[i][j][k] = row[k];
                    if(arr[i][j][k] == 'S'){
                        Start = {j, k, i};
                    }
                    else if(arr[i][j][k] == 'E'){
                        End = {j, k, i};
                    }
                }
            }
        }

        int result = bfs();
        if(result != -1){
            cout << "Escaped in " << result << " minute(s)." << '\n';
        }
        else{
            cout << "Trapped!" << '\n';
        }

    }

    return 0;
}