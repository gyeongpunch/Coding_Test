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
};

const int MX = 100;

int N;
int arr[MX][MX];
int visited[MX][MX];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool bound_check(int x, int y){
    return 0<=x && x<N && 0<=y && y<N;
}

bool bfs(int s, int e){
    queue<Point> q;
    memset(visited, 0, sizeof(visited));
    visited[0][0] = 1;
    q.push({0, 0});

    while(!q.empty()){
        Point now = q.front(); q.pop();

        if(now.x == N-1 && now.y == N-1) return true;

        for(int i=0; i<4; i++){
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if(!bound_check(nx, ny)) continue;
            if(visited[nx][ny] == 1) continue;
            if(arr[nx][ny] < s || arr[nx][ny] > e) continue;

            q.push({nx, ny});
            visited[nx][ny] = 1;
        }
    }
    return false;
}

bool simulation(int mid){
    for(int s=arr[0][0]-mid; s<=arr[0][0]; s++){
        int e = s + mid;
        if(bfs(s, e)){
            return true;
        }
    }
    return false;
}

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> arr[i][j];
        }
    }

    int l=0, r=200;
    int result = 200;
    while(l <= r){
        // cout << l << ' ' << r << '\n';

        int mid = (l + r) / 2;
        
        bool flag = simulation(mid);

        if(flag){
            result = min(result, mid);
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }

    cout << result << '\n';

    return 0;
}