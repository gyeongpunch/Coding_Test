#include <iostream>
#include <vector>

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
bool resultFlag = false;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void move(int num){
    Horse now = horseLoc[num];

    int idx;
    for(int i=0; i<horseMap[now.x][now.y].size(); i++){
        if(horseMap[now.x][now.y][i] == num){
            idx = i;
            break;
        }
    }

    int nx = now.x + dx[now.d];
    int ny = now.y + dy[now.d];

    if(arr[nx][ny] == 0){
        for(int i=idx; i<horseMap[now.x][now.y].size(); i++){
            int n = horseMap[now.x][now.y][i];

            horseMap[nx][ny].push_back(n);
            horseLoc[n].x = nx;
            horseLoc[n].y = ny;
            horseMap[now.x][now.y][i] = -1;
        }
        while(!horseMap[now.x][now.y].empty() && horseMap[now.x][now.y].back() == -1){
            horseMap[now.x][now.y].pop_back();
        }
        if(horseMap[nx][ny].size() >= 4){
            resultFlag = true;
            return;
        }

    }
    else if(arr[nx][ny] == 1){
        for(int i = horseMap[now.x][now.y].size()-1; i>=idx; i--){
            int n = horseMap[now.x][now.y][i];

            horseMap[nx][ny].push_back(n);
            horseLoc[n].x = nx;
            horseLoc[n].y = ny;
            horseMap[now.x][now.y][i] = -1;
        }
        while(!horseMap[now.x][now.y].empty() && horseMap[now.x][now.y].back() == -1){
            horseMap[now.x][now.y].pop_back();
        }
        if(horseMap[nx][ny].size() >= 4){
            resultFlag = true;
            return;
        }
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
        if(result > 1000) break;

        result++;
        for(int i=1; i<=K; i++){
            move(i);
            if(resultFlag) break;
        }
        if(resultFlag) break;
    }
    if(result == 1001) result = -1;
    cout << result << '\n';

    return 0;
}