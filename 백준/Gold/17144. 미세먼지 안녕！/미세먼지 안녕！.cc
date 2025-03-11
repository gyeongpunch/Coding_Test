#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <cstring>

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(nullptr);

using namespace std;

const int MAX_N = 50;

int N, M, T;
int arr[MAX_N][MAX_N];
int arrTmp[MAX_N][MAX_N];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void pprint(){
    cout << "=======================\n";
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << "=======================\n";
}

bool bound_check(int x, int y){
    return 0<=x && x<N && 0<=y && y<M;
}

int get_cnt(int x, int y){
    int cnt = 0;
    for(int i=0; i<4; i++){
        if(bound_check(x+dx[i], y+dy[i]) && arr[x+dx[i]][y+dy[i]] != -1){
            cnt++;
        }
    }
    return cnt;
}

void dustPlay(){
    memset(arrTmp, 0, sizeof(arrTmp));

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(arr[i][j] <= 0) continue;

            int cnt = get_cnt(i, j);

            int nx, ny;
            for(int d=0; d<4; d++){
                nx = i + dx[d];
                ny = j + dy[d];

                if(bound_check(nx, ny) && arr[nx][ny] != -1){
                    arrTmp[nx][ny] += (arr[i][j] / 5);
                }
            }
            arrTmp[i][j] += arr[i][j] - (arr[i][j]/5) * cnt;
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(arr[i][j] == -1) continue;

            arr[i][j] = arrTmp[i][j];
        }
    }
}

void antiClock(int x, int y){
    for(int i=x-1; i>0; i--){
        arr[i][0] = arr[i - 1][0];
    }
    for(int i=0; i<M-1; i++){
        arr[0][i] = arr[0][i + 1];
    }

    for(int i=0; i<=x-1; i++){
        arr[i][M-1] = arr[i+1][M-1];
    }

    for(int i=M-1; i>1; i--){
        arr[x][i] = arr[x][i-1];
    }
    arr[x][y+1] = 0;
}

void Clock(int x, int y){
    for(int i=x+1; i<N-1; i++){
        arr[i][0] = arr[i + 1][0];
    }

    for(int i=0; i<M-1; i++){
        arr[N-1][i] = arr[N-1][i + 1];
    }

    for(int i=N-1; i>x; i--){
        arr[i][M-1] = arr[i-1][M-1];
    }

    for(int i=M-1; i>1; i--){
        arr[x][i] = arr[x][i-1];
    }
    arr[x][y+1] = 0;
}

void airCleaner(){
    for(int i=0; i<N-1; i++){
        if(arr[i][0] == -1){
            antiClock(i, 0);
            Clock(i + 1, 0);
            break;
        }
    }
}

int calc(){
    int result = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(arr[i][j] <= 0) continue;
            result += arr[i][j];
        }
    }
    return result;
}

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    cin >> N >> M >> T;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> arr[i][j];
        }
    }

    for(int t=0; t<T; t++){
        dustPlay();

        airCleaner();
    }


    int result = calc();

    cout << result << '\n';

    return 0;
}