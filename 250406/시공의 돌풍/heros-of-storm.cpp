#include <iostream>
#include <cstring>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define MAX_SZ 50

struct Point{
    int x, y;
};

int N, M, T;
int arr[MAX_SZ][MAX_SZ];
int arrTmp[MAX_SZ][MAX_SZ];
Point cleaner[2];
int result = 0;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool bound_check(int x, int y){
    return 0<=x && x<N && 0<=y && y<M;
}

void pprint(){
    cout << "=================\n";
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << "=================\n";
}

void dust(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            arrTmp[i][j] = arr[i][j];
        }
    }

    int nx, ny;
    for(int x=0; x<N; x++){
        for(int y=0; y<M; y++){
            if(arr[x][y] == -1) continue;
            int cnt = 0;

            for(int i=0; i<4; i++){
                nx = x+dx[i];
                ny = y+dy[i];

                if(!bound_check(nx, ny)) continue;
                if(arr[nx][ny] == -1) continue;
                cnt++;
                arrTmp[nx][ny] += arr[x][y] / 5;
            }
            arrTmp[x][y] -= (arr[x][y] / 5) * cnt;
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            arr[i][j] = arrTmp[i][j];
        }
    }

}

void upper_clean(){
    int tmp = arr[cleaner[0].x-1][0];

    for(int x=cleaner[0].x-1; x>0; x--){
        arr[x][0] = arr[x-1][0];
    }

    for(int y=0; y<M-1; y++){
        arr[0][y] = arr[0][y+1];
    }

    for(int x=0; x<cleaner[0].x; x++){
        arr[x][M-1] = arr[x+1][M-1];
    }

    for(int y=M-1; y>1; y--){
        arr[cleaner[0].x][y] = arr[cleaner[0].x][y-1];
    }
    arr[cleaner[0].x][1] = 0;
}

void lower_clean(){
    for(int x=cleaner[1].x+1; x <N-1; x++){
        arr[x][0] = arr[x+1][0];
    }

    for(int y=0; y<M-1; y++){
        arr[N-1][y] = arr[N-1][y+1];
    }

    for(int x=N-1; x>cleaner[1].x; x--){
        arr[x][M-1] = arr[x-1][M-1];
    }

    for(int y=M-1; y>1; y--){
        arr[cleaner[1].x][y] = arr[cleaner[1].x][y-1];
    }
    arr[cleaner[1].x][1] = 0;

}

void air_clean(){
    upper_clean();

    lower_clean();
}

void calc(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(arr[i][j] == -1) continue;

            result += arr[i][j];
        }
    }
}

int main() {
    fastio;

    cin >> N >> M >> T;
    int cnt = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> arr[i][j];
            if(arr[i][j] == -1){
                cleaner[cnt++] = {i, j};
            }
        }
    }

    for(int t=0; t<T; t++){
        dust();
        air_clean();
        // pprint();
    }

    calc();

    cout << result << '\n';

    return 0;
}