#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <cstring>

using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(nullptr);

struct Horse{
    int x, y, d;
};

const int MX = 14;
const int MXH = 11;

int N, K;
int arr[MX][MX];
vector<int> horseMap[MX][MX];
Horse horseLoc[MXH];
int result;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

bool game_over(){
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(horseMap[i][j].size() >= 4) return true;
        }
    }
    return false;
}

void move(int num){
    Horse now = horseLoc[num];

    if(horseMap[now.x][now.y][0] != num) return;

    int nx = now.x + dx[now.d];
    int ny = now.y + dy[now.d];

    if(arr[nx][ny] == 0){
        for(int n : horseMap[now.x][now.y]){
            horseMap[nx][ny].push_back(n);
            horseLoc[n].x = nx;
            horseLoc[n].y = ny;
        }
        horseMap[now.x][now.y].clear();
    }
    else if(arr[nx][ny] == 1){
        for(int i = horseMap[now.x][now.y].size()-1; i>-1; i--){
            int n = horseMap[now.x][now.y][i];

            horseMap[nx][ny].push_back(n);
            horseLoc[n].x = nx;
            horseLoc[n].y = ny;
        }
        horseMap[now.x][now.y].clear();
    }
    else if(arr[nx][ny] == 2){
        int nd = now.d<2 ? 1-now.d : 5-now.d;

        int nx = now.x + dx[nd];
        int ny = now.y + dy[nd];

        if(arr[nx][ny] == 2){
            horseLoc[num].d = nd;
        }
        else{
            horseLoc[num].d = nd;
            move(num);
        }
    }
}

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    cin >> N >> K;
    for(int i=0; i<N+2; i++){
        for(int j=0; j<N+2; j++){
            if(i==0) arr[i][j] = 2;
            else if(i==N+1) arr[i][j] = 2;
            else {
                if(j==0||j==N+1) arr[i][j] = 2;
                else cin >> arr[i][j];
            }
        }
    }
    int x, y, d;
    for(int i=1; i<=K; i++){
        cin >> x >> y >> d;
        d--;
        horseMap[x][y].push_back(i);
        horseLoc[i] = {x, y, d};
    }

    while(true){
        if(game_over()) break;
        if(result > 1000) break;

        for(int i=1; i<=K; i++){
            move(i);
            // cout << "Move " << i << '\n';
            // for(int i=1; i<=N; i++){
            //     for(int j=1; j<=N; j++){
            //         if(!horseMap[i][j].empty()){
            //             cout << i << ' ' << j << '\n';
            //             for(int n : horseMap[i][j]){
            //                 cout << n << ' ';
            //             }
            //             cout << '\n';
            //         }
            //     }
            // }
            // cout << "\n\n";
        }


        // for(int i=1; i<=N; i++){
        //     for(int j=1; j<=N; j++){
        //         if(!horseMap[i][j].empty()){
        //             cout << i << ' ' << j << '\n';
        //             for(int n : horseMap[i][j]){
        //                 cout << n << ' ';
        //             }
        //             cout << '\n';
        //         }
        //     }
        // }
        // cout << "\n\n";
        // if(result == 5) break;
        result++;
    }
    if(result == 1001) result = -1;
    cout << result << '\n';

    return 0;
}