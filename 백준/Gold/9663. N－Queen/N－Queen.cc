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

const int MX = 15;

int N, total;
int visited[MX][MX];
int result;
vector<Point> path;

int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

bool bound_check(int x, int y){
    return 0<=x && x<N && 0<=y && y<N;
}

void dfs(int x){
    if(x==N) {
        result++;
        return;
    }

    for(int y=0; y<N; y++){
        bool flag = true;

        for(const Point& p : path){
            if(p.y == y || abs(p.x-x)==abs(p.y-y)){
                flag = false;
                break;
            }
        }

        if(!flag) continue;

        path.push_back({x, y});

        dfs(x+1);

        path.pop_back();
    }
}

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    cin >> N;
    total = N*N;

    dfs(0);

    cout << result << '\n';

    return 0;
}