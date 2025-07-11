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

struct Info{
    int x, y, s;
};

const int MX = 100;

int N, M;
char arr[MX][MX];
int visited[MX][MX];
vector<Info> result;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool bound_check(int x, int y){
    return 0<=x && x<N && 0<=y && y<M;
}

void gogo(int x, int y){
    
    for(int s=1; s<min(N, M); s++){

        for(int i=0; i<4; i++){
            int nx = x + dx[i]*s;
            int ny = y + dy[i]*s;

            if(!bound_check(nx, ny)) return;
            if(arr[nx][ny] != '*') return;
        }
        for(int i=0; i<4; i++){
            int nx = x + dx[i]*s;
            int ny = y + dy[i]*s;
            visited[nx][ny] = 1;
            visited[x][y] = 1;
        }
        result.push_back({x+1, y+1, s});
    }
}

bool is_avail(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(arr[i][j]=='*' && visited[i][j] != 1){
                return false;
            }
        }
    }
    return true;
}

int main(void){
    fastio;
    
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> arr[i][j];
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(arr[i][j] == '*'){
                gogo(i, j);
            }
        }
    }

    // for(int i=0; i<N; i++){
    //     for(int j=0; j<M; j++){
    //         cout << visited[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    if(is_avail()){
        cout << result.size() << '\n';
        for(const Info &r : result){
            cout << r.x << ' ' << r.y << ' ' << r.s << '\n';
        }
    }
    else{
        cout << -1 << '\n';
    }


    return 0;
}