#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <cstring>
#include <stack>

using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(nullptr);

struct Info{
    int x, y, mem, dir;
};

const int MX = 20;

string result;
int N, M;
char arr[MX][MX];
int visited[MX][MX][16][4];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void init(){
    memset(visited, 0, sizeof(visited));
    result = "NO";
}

void input(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> arr[i][j];
        }
    }
}

void solution(){
    queue<Info> q;
    q.push({0, 0, 0, 0});
    visited[0][0][0][0] = 1;

    while(!q.empty()){
        Info now = q.front(); q.pop();

        char cmd = arr[now.x][now.y];

        if(cmd == '@'){
            result = "YES";
            return;
        }

        int nmem = now.mem, ndir = now.dir;
        bool question = false;
        if(cmd == '<') ndir = 2;
        else if(cmd == '>') ndir = 0;
        else if(cmd == '^') ndir = 3;
        else if(cmd == 'v') ndir = 1;
        else if(cmd == '_') ndir = (now.mem == 0 ? 0 : 2);
        else if(cmd == '|') ndir = (now.mem == 0 ? 1 : 3);
        else if(cmd == '+') nmem = (now.mem + 1) % 16;
        else if(cmd == '-') nmem = (now.mem == 0 ? 15 : now.mem - 1);
        else if('0'<=cmd && cmd<='9') nmem = cmd - '0';
        else if(cmd == '?') question = true;

        if(question){
            for(int d=0; d<4; d++){
                int nx = (now.x + dx[d] + N) % N;
                int ny = (now.y + dy[d] + M) % M;
                if(!visited[nx][ny][nmem][d]){
                    visited[nx][ny][nmem][d] = 1;
                    q.push({nx, ny, nmem, d});
                }
            }
        }else{
            int nx = (now.x + dx[ndir] + N) % N;
            int ny = (now.y + dy[ndir] + M) % M;
            if(!visited[nx][ny][nmem][ndir]){
                visited[nx][ny][nmem][ndir] = 1;
                q.push({nx, ny, nmem, ndir});
            }
        }
    }
}

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    int T;
    cin >> T;
    for(int t=1; t<=T; t++){    
        init();
        input();
        solution();

        cout << '#' << t << ' ' << result << '\n';
    }

    return 0;
}