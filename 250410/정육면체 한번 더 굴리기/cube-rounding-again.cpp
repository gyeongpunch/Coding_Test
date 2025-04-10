#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define MAX_N 20

struct Dice{
    int state[4][3] = {
        {0, 5, 0},
        {4, 6, 3},
        {0, 2, 0},
        {0, 1, 0}
    };
    int x = 0, y = 0, dir = 1;
};

struct Point{
    int x, y;
};

int N, M;
int arr[MAX_N][MAX_N];
int visited[MAX_N][MAX_N];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int result = 0;
Dice dice;

bool bound_check(int x, int y){
    return 0<=x && x<N && 0<=y && y<N;
}

void move(){
    int nx = dice.x + dx[dice.dir];
    int ny = dice.y + dy[dice.dir];

    if(!bound_check(nx, ny)){
        dice.dir = (dice.dir + 2) % 4;
        dice.x += dx[dice.dir];
        dice.y += dy[dice.dir];
    }
    else{
        dice.x = nx;
        dice.y = ny;
    }

    if(dice.dir == 2){
        int tmp = dice.state[0][1];
        for(int i=0; i<3; i++){
            dice.state[i][1] = dice.state[i+1][1];
        }
        dice.state[3][1] = tmp;
    }
    else if(dice.dir == 0){
        int tmp = dice.state[3][1];
        for(int i=3; i>0; i--){
            dice.state[i][1] = dice.state[i-1][1];
        }
        dice.state[0][1] = tmp;
    }
    else if(dice.dir == 1){
        int tmp = dice.state[3][1];
        dice.state[3][1] = dice.state[1][0];
        dice.state[1][0] = dice.state[1][1];
        dice.state[1][1] = dice.state[1][2];
        dice.state[1][2] = tmp;
    }
    else if (dice.dir == 3){
        int tmp = dice.state[3][1];
        dice.state[3][1] = dice.state[1][2];
        dice.state[1][2] = dice.state[1][1];
        dice.state[1][1] = dice.state[1][0];
        dice.state[1][0] = tmp;
    }

    if(arr[dice.x][dice.y] < dice.state[1][1]){
        dice.dir = (dice.dir + 1) % 4;
    }
    else if(arr[dice.x][dice.y] > dice.state[1][1]){
        dice.dir = (dice.dir + 3) % 4;
    }
}

void update_result(){
    memset(visited, 0, sizeof(visited));

    queue<Point> q;
    q.push({dice.x, dice.y});
    visited[dice.x][dice.y] = 1;
    
    int nx, ny;
    int cnt = 0;
    while(!q.empty()){
        Point now = q.front(); q.pop();
        cnt++;
        for(int i=0; i<4; i++){
            nx = now.x + dx[i];
            ny = now.y + dy[i];

            if(!bound_check(nx, ny)) continue;
            if(visited[nx][ny] == 1) continue;
            if(arr[nx][ny] != arr[dice.x][dice.y]) continue;

            q.push({nx, ny});
            visited[nx][ny] = 1;
        }
    }

    // cout << dice.x << ' ' << dice.y << ' ' << dice.dir << '\n';
    // cout << dice.state[1][1] << "=====\n";
    result += cnt * arr[dice.x][dice.y];
    // cout << cnt << ' ' << arr[dice.x][dice.y] << '\n';
    // cout << result << '\n';
    // cout << '\n';
}

void simulation(){
    move();

    update_result();
}
void pprint(){
    cout << "===============\n";
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << "===============\n";
}
void vprint(){
    cout << "===============\n";
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << visited[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << "===============\n";
}

int main(void){
    fastio;

    // freopen("input.txt", "r", stdin);

    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> arr[i][j];
        }
    }
    for(int i=0; i<M; i++){
        simulation();
        // vprint();
    }

    cout << result << '\n';

    return 0;
}