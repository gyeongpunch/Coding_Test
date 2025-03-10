#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <cstring>

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(nullptr);

using namespace std;

struct Point{
    int x, y;
};

const int N = 12;
const int M = 6;

char arr[N][M];
char arrTmp[N][M];
int visited[N][M];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool flag;

void pprint(){
    cout << "=====================\n";
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << "=====================\n";
}

bool bound_check(int x, int y){
    return 0<=x && x<N && 0<=y && y<M;
}

void bfs(int x, int y){
    queue<Point> q;
    vector<Point> v;

    q.push({x, y});
    v.push_back({x, y});
    visited[x][y] = 1;

    int nx, ny;
    int cnt = 1;
    while(!q.empty()){
        Point now = q.front(); q.pop();

        for(int i=0; i<4; i++){
            nx = now.x + dx[i];
            ny = now.y + dy[i];

            if(bound_check(nx, ny) && arrTmp[nx][ny] == arrTmp[x][y] && visited[nx][ny] == 0){
                q.push({nx, ny});
                v.push_back({nx, ny});
                visited[nx][ny] = 1;
                cnt++;
            }
        }
    }

    if(cnt >= 4){
        for(const Point &p : v){
            arr[p.x][p.y] = '.';
        }
        flag = true;
    }
}

void crush(){
    memset(visited, 0, sizeof(visited));

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            arrTmp[i][j] = arr[i][j];
        }
    }


    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(arr[i][j] != '.' && visited[i][j] == 0){
                bfs(i, j);
            }
        }
    }
}

void drop(){
    for(int col=0; col<M; col++){
        int rowTmp = N-1;
        for(int row=N-1; row>-1; row--){
            if(arr[row][col] != '.'){
                if(row==rowTmp){
                    rowTmp--;
                }
                else{
                    arr[rowTmp--][col] = arr[row][col];
                    arr[row][col] = '.';
                }
            }
        }
    }
}

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> arr[i][j];
        }
    }

    int result = 0;
    while(true){
        flag = false;
        crush();
        if(!flag){
            break;
        }

        drop();

        result++;
        // pprint();
    }

    cout << result << '\n';

    

    return 0;
}