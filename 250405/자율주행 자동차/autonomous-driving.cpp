#include <iostream>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define MAX_SZ 50

struct Car{
    int x, y, d;
};

int N, M;
int arr[MAX_SZ][MAX_SZ];
int visited[MAX_SZ][MAX_SZ];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
Car now;
int result = 0;

void pprint(){
    cout << "================\n";
    cout << now.x << ' ' << now.y << ' ' << now.d << '\n';
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << visited[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << "================\n";
}

bool bound_check(int x, int y){
    return 0<=x && x<N && 0<=y && y<M;
}

void simulation(){
    int nx, ny;
    bool flag;
    while(true){
        // pprint();
        flag = false;
        for(int i=1; i<=4; i++){
            nx = now.x + dx[(now.d - i + 4) % 4];
            ny = now.y + dy[(now.d - i + 4) % 4];

            if(!bound_check(nx, ny)) continue;
            if(arr[nx][ny] == 1) continue;
            if(visited[nx][ny] == 1) continue;

            now.x = nx;
            now.y = ny;
            now.d = (now.d - i + 4) % 4;
            flag = true;
            visited[nx][ny] = 1;
            result++;
            break;
        }
        
        if(!flag){
            nx = now.x - dx[now.d];
            ny = now.y - dy[now.d];

            if(!bound_check(nx, ny)) break;
            if(arr[nx][ny] == 1) break;

            now.x = nx;
            now.y = ny;
        }
    }
}

int main() {
    fastio;
    cin >> N >> M;
    cin >> now.x >> now.y >> now.d;
    visited[now.x][now.y] = 1;
    result++;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> arr[i][j];
        }
    }

    simulation();

    cout << result << '\n';

    return 0;
}