#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};

int bfs(int I, int x, int y, int target_x, int target_y){
    queue<pair<int, int>> q;
    vector<vector<int>> visited(I, vector<int>(I, -1));
    q.push({x, y});
    visited[x][y] = 0;

    while(!q.empty()){
        auto[cx, cy] = q.front();
        q.pop();
        if(cx==target_x && cy==target_y){
            return visited[cx][cy];
        }

        for(int i=0; i<8; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(0<=nx && nx<I && 0<=ny && ny<I && visited[nx][ny]==-1){
                q.push({nx, ny});
                visited[nx][ny] = visited[cx][cy] + 1;
            }
        }
    }
    return -1;
}

int main(void){
    int T;
    cin >> T;
    while(T--){
        int I;
        cin >> I;
        int cx, cy;
        cin >> cx >> cy;
        int target_x, target_y;
        cin >> target_x >> target_y;

        int result = bfs(I, cx, cy, target_x, target_y);

        cout << result << endl;
    }


    return 0;
}
