#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define MAX_SZ 15

struct Point{
    int x, y, d;
};

int N, W, H;
int arr[MAX_SZ][MAX_SZ];
int arrOrigin[MAX_SZ][MAX_SZ];
int visited[MAX_SZ][MAX_SZ];
vector<int> path;
int result;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void pprint(){
    cout << "=============\n";
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << "=============\n";
}

void init(){
    result = MAX_SZ * MAX_SZ + 1;
}

void input(){
    cin >> N >> W >> H;
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cin >> arr[i][j];
            arrOrigin[i][j] = arr[i][j];
        }
    }

    // cout << N << W << H << '\n';
    // for(int i=0; i<H; i++){
    //     for(int j=0; j<W; j++){
    //         cout << arr[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
}

bool bound_check(int x, int y){
    return 0<=x && x<H && 0<=y && y<W;
}

void goosle_drop(int y){
    queue<Point> q;
    memset(visited, 0, sizeof(visited));

    for(int x=0; x<H; x++){
        if(arr[x][y] != 0){
            q.push({x, y, arr[x][y]});
            visited[x][y] = 1;
            // cout << '\n';
            // cout << x << ' ' << y << '\n';
            // cout << '\n';
            break;
        }
    }
    int nx, ny;
    int cnt=0;
    while(!q.empty()){
        Point now = q.front(); q.pop();
        // if(cnt++==2) break;  
        // cout << now.x << ' ' << now.y << '\n';

        for(int i=0; i<4; i++){
            for(int j=1; j<now.d; j++){
                nx = now.x + dx[i] * j;
                ny = now.y + dy[i] * j;

                if(!bound_check(nx, ny)) continue;
                if(visited[nx][ny] != 0) continue;
                if(arr[nx][ny] == 0) continue;

                q.push({nx, ny, arr[nx][ny]});
                arr[nx][ny] = 0;
                visited[nx][ny] = 1;
            }
        }
        arr[now.x][now.y] = 0;
    }
}

void block_drop(){
    for(int y=0; y<W; y++){
        int curX = H-1;
        for(int x=H-1; x>-1; x--){
            if(arr[x][y] != 0){
                if(x != curX){
                    arr[curX][y] = arr[x][y];
                    arr[x][y] = 0;
                }
                curX--;
            }
        }
    }
}

void get_result(){
    int cnt = 0;
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            if(arr[i][j] != 0) cnt++;
        }
    }
    result = min(result, cnt);
}

void simulation(){
    // cout << "!!!\n";
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            arr[i][j] = arrOrigin[i][j];
        }
    }

    for(const int &y : path){
        goosle_drop(y);

        // pprint();
        block_drop();
    }

    get_result();
}

void make_perm(int depth){
    // cout << depth << ' ' << N << '\n';

    if(depth == N){
        // for(int a : path) cout << a << ' ';
        // cout << '\n';

        simulation();
        return;
    }

    for(int i=0; i<W; i++){
        path.push_back(i);

        make_perm(depth + 1);

        path.pop_back();
    }
}

void solution(){
    make_perm(0);

    cout << result << '\n';
}

int main(void){
    fastio;

    // freopen("input.txt", "r", stdin);

    int T;
    cin >> T;
    for(int t=1; t<=T; t++){
        cout << "#" << t << " ";
        init();

        input();
        // cout << "!!\n";
        solution();
    }

    return 0;
}