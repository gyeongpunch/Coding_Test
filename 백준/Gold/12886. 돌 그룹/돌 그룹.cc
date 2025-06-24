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
    int x, y;
};

const int MX = 1000;

int A, B, C;
int visited[MX][MX];
int result;

bool bound_check(int x, int y){
    return 0<=x && x<MX && 0<=y && y<MX;
}

void bfs(){
    int sum=A+B+C;
    if(sum%3 != 0) return;

    if(A>B) swap(A, B);
    if(A>C) swap(A, C);
    if(B>C) swap(B, C);

    memset(visited, -1, sizeof(visited));
    queue<Info> q;
    q.push({A, B});
    visited[A][B] = 0;

    while(!q.empty()){
        Info now = q.front(); q.pop();
        int x = now.x;
        int y = now.y;
        int z = sum-x-y;

        if(x==y && y==z){
            result = 1;
            return;
        }

        int sm, bg, rest;
        for(int i=0; i<3; i++){
            if(i==0 && x!=y){
                rest=z;
                sm=min(x, y);
                bg=max(x, y);
            }
            else if(i==1 && x!=z){
                rest=y;
                sm=min(x, z);
                bg=max(x, z);
            }
            else if(i==2 && y!=z){
                rest=x;
                sm=min(y, z);
                bg=max(y, z);
            }

            bg-=sm;
            sm*=2;

            int tmp[3] = {sm, bg, rest};
            sort(tmp, tmp+3);

            if(!bound_check(tmp[0], tmp[1])) continue;
            if(visited[tmp[0]][tmp[1]] != -1) continue;

            q.push({tmp[0], tmp[1]});
            visited[tmp[0]][tmp[1]] = visited[x][y] + 1;
        }
    }
}

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    cin >> A >> B >> C;

    bfs();

    cout << result << '\n';
    
    return 0;
}