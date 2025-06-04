#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <cstring>

using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(nullptr);

struct Block{
    int size, rain, x, y;
};
struct Point{
    int x, y;
};

void input();
bool bound_check(int x, int y);
void vprint();
void aprint();

const int MAX_N = 20;

int N, M;
int arr[MAX_N][MAX_N];
int arrTmp[MAX_N][MAX_N];
int visited[MAX_N][MAX_N];
int result = 0;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
Block biggest;

bool has_block_group(){
    memset(visited, 0, sizeof(visited));
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(1<=arr[i][j] && arr[i][j]<=M && visited[i][j]==0){
                queue<Point> q;
                q.push({i, j});
                visited[i][j] = 1;
                int count = 1;
                int target = arr[i][j];
                
                while(!q.empty()){
                    Point now = q.front(); q.pop();
                    
                    for(int k=0; k<4; k++){
                        int nx = now.x + dx[k];
                        int ny = now.y + dy[k];
                        
                        if(!bound_check(nx, ny)) continue;
                        if(visited[nx][ny] == 1) continue;
                        if(arr[nx][ny] == 0 || arr[nx][ny] == target){
                            q.push({nx, ny});
                            visited[nx][ny] = 1;
                            count++;
                        }
                    }
                }
                
                if(count >= 2) return true;
                
                // 무지개 블록 방문 초기화
                for(int x=0; x<N; x++){
                    for(int y=0; y<N; y++){
                        if(arr[x][y] == 0) visited[x][y] = 0;
                    }
                }
            }
        }
    }
    return false;
}

bool is_change(Block &nowBlock){
    if(nowBlock.size == biggest.size){
        if(nowBlock.rain == biggest.rain){
            if(nowBlock.x == biggest.x){
                return nowBlock.y > biggest.y; // 기준 블록의 열이 가장 큰 것
            }
            return nowBlock.x > biggest.x; // 기준 블록의 행이 가장 큰 것
        }
        return nowBlock.rain > biggest.rain; // 무지개 블록이 가장 많은 것
    }
    return nowBlock.size > biggest.size; // 크기가 가장 큰 것
}

void bfs(int x, int y){
    queue<Point> q;
    q.push({x, y});
    visited[x][y] = 1;
    
    Block nowBlock;
    nowBlock.size = 1;
    nowBlock.rain = 0;
    nowBlock.x = x;
    nowBlock.y = y;

    Point now;
    int nx, ny;
    while(!q.empty()){
        now = q.front(); q.pop();

        for(int i=0; i<4; i++){
            nx = now.x + dx[i];
            ny = now.y + dy[i];
            if(!bound_check(nx, ny)) continue;
            if(visited[nx][ny] == 1) continue;
            if(arr[nx][ny] != 0 && arr[nx][ny] != arr[x][y]) continue;
            

            q.push({nx, ny});
            visited[nx][ny] = 1;
            nowBlock.size++;
            if(arr[nx][ny] == 0){
                nowBlock.rain++;
            }
            else if (arr[nx][ny] == arr[x][y]){
                // 기준 블록은 행이 가장 작은 것, 그 다음 열이 가장 작은 것
                if(nx < nowBlock.x || (nx == nowBlock.x && ny < nowBlock.y)) {
                    nowBlock.x = nx;
                    nowBlock.y = ny;
                }
            }
        }
    }

    if(nowBlock.size >= 2 && is_change(nowBlock)){
        biggest = nowBlock;
    }
}

void reset_rainbow_visit() {
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            if(arr[i][j] == 0)
                visited[i][j] = 0;
}

void find_biggest_block(){
    biggest.size = 0;
    memset(visited, 0, sizeof(visited));
    // 행과 열을 역순으로 탐색하여 기준 블록이 큰 그룹을 먼저 찾도록 함
    for(int i=N-1; i>=0; i--){
        for(int j=N-1; j>=0; j--){
            if(1<=arr[i][j] && arr[i][j]<=M && visited[i][j]==0){
                bfs(i, j);
                reset_rainbow_visit();
            }
        }
    }
}

void remove(){
    result += biggest.size * biggest.size;
    
    queue<Point> q;
    q.push({biggest.x, biggest.y});
    memset(visited, 0, sizeof(visited));
    visited[biggest.x][biggest.y] = 1;
    int target = arr[biggest.x][biggest.y];
    arr[biggest.x][biggest.y] = -2; // 제거된 블록 표시


    Point now;
    int nx, ny;
    while(!q.empty()){
        now = q.front(); q.pop();

        for(int i=0; i<4; i++){
            nx=now.x+dx[i];
            ny=now.y+dy[i];

            if(!bound_check(nx, ny)) continue;
            if(visited[nx][ny] == 1) continue;
            if(arr[nx][ny] == 0 || arr[nx][ny] == target){
                q.push({nx, ny});
                visited[nx][ny] = 1;
                arr[nx][ny] = -2; // 제거된 블록 표시
            }
        }
    }
}

void drop(){
    for(int j=0; j<N; j++){
        int bottom = N-1;
        for(int i=N-1; i>=0; i--){
            if(arr[i][j] == -1){
                bottom = i-1;
            }
            else if(arr[i][j] != -2){
                if(i != bottom){
                    arr[bottom][j] = arr[i][j];
                    arr[i][j] = -2;
                }
                bottom--;
            }
        }
    }
}

void rotate(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            arrTmp[i][j] = arr[j][N-i-1];
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            arr[i][j] = arrTmp[i][j];
        }
    }
}

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    input();
    
    while(true){
        if(!has_block_group()){
            break;
        }
        
        find_biggest_block();
        if(biggest.size <= 1) break;
        
        remove();
        drop();
        rotate();
        drop();
    }

    cout << result << '\n';

    return 0;
}

bool bound_check(int x, int y){
    return 0<=x && x<N && 0<=y && y<N;
}

void input(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> arr[i][j];
        }
    }
}

void vprint(){
    cout << "========================\n";
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << visited[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << "========================\n";
}

void aprint(){
    cout << "========================\n";
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << "========================\n\n\n";
}