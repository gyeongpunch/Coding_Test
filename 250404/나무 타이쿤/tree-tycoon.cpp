#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define MAX_N 15

struct Point{
    int x, y;
};

int N, M;
int arr[MAX_N][MAX_N];
int visited[MAX_N][MAX_N];
vector<Point> v;
int result = 0;
int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

void pprint(){
    cout << "=============\n";
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << "=============\n";
}

void vprint(){
    cout << "============\n";
    for(const Point &p : v){
        cout << p.x << ' ' << p.y << '\n';
    }
    cout << "============\n";
}

void move(int dir, int dist){
    for(Point &p : v){
        p.x = ((p.x + dx[dir] * dist) % N + N) % N;
        p.y = ((p.y + dy[dir] * dist) % N + N) % N;
    }
    // vprint();
}

void eat(){
    for(const Point &p : v){
        arr[p.x][p.y]++;
    }
}

bool bound_check(int x, int y){
    return 0<=x && x<N && 0<=y && y<N;
}

void diagonal(){
    int nx, ny;
    for(const Point &p : v){
        int cnt = 0;
        for(int i=1; i<8; i+=2){
            nx = p.x + dx[i];
            ny = p.y + dy[i];

            if(!bound_check(nx, ny)) continue;

            if(arr[nx][ny] > 0) cnt++;
        }

        arr[p.x][p.y] += cnt;
    }
}

void get_new_v(){
    memset(visited, 0, sizeof(visited));
    for(Point &p : v){
        visited[p.x][p.y] = 1;
    }

    v.clear();
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(arr[i][j] <= 1) continue;
            if(visited[i][j] == 1) continue;

            v.push_back({i, j});
            arr[i][j] -= 2;
        }
    }
}

void calc(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            result += arr[i][j];
        }
    }
}

void simulation(int dir, int dist){
    move(dir, dist);

    eat();

    diagonal();

    get_new_v();
}

int main() {
    fastio;

    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> arr[i][j];
        }
    }

    v.push_back({N-1, 0});
    v.push_back({N-1, 1});
    v.push_back({N-2, 0});
    v.push_back({N-2, 1});

    int a, b;
    for(int i=0; i<M; i++){
        cin >> a >> b;
        simulation(a-1, b);
        // pprint();
    }

    calc();

    cout << result << '\n';

    return 0;
}