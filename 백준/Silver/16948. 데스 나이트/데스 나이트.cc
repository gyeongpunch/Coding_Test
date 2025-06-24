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

struct Point{
    int x, y;

    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
};

const int MX=200;

int N;
int visited[MX][MX];
Point st, ed;
int result=-1;

int dx[6] = {-2, -2, 0, 0, 2, 2};
int dy[6] = {-1, 1, -2, 2, -1, 1};

bool bound_check(int x, int y){
    return 0<=x && x<N && 0<=y && y<N;
}

void bfs(){
    memset(visited, -1, sizeof(visited));
    queue<Point> q;
    q.push(st);
    visited[st.x][st.y] = 0;

    while(!q.empty()){
        Point now = q.front(); q.pop();

        if(now==ed) {
            result = visited[ed.x][ed.y];
            return;
        }

        for(int i=0; i<6; i++){
            int nx=now.x+dx[i];
            int ny=now.y+dy[i];

            if(!bound_check(nx, ny)) continue;
            if(visited[nx][ny]!=-1) continue;

            q.push({nx, ny});
            visited[nx][ny] = visited[now.x][now.y]+1;
        }
    }
}

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);


    cin >> N;
    cin >> st.x >> st.y >> ed.x >> ed.y;

    bfs();

    cout << result << '\n';

    return 0;
}