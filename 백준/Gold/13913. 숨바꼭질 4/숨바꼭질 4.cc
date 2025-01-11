#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <deque>

#define MAX 1000001

using namespace std;

int N, K;
vector<int> visited;
deque<int> route;

int bfs(){
    queue<int> q;
    q.push(N);
    visited[N] = 0;

    while(!q.empty()){
        int now = q.front();
        q.pop();

        for(int nx : {now-1, now+1, now*2}){
            if(0<=nx && nx<MAX && visited[nx]==-1){
                q.push(nx);
                visited[nx] = visited[now] + 1;
            }
        }
    }

    int now = K;
    while(1){
        route.push_front(now);
        if(now==N){
            break;
        }
        if(now%2==0 && visited[now/2]==visited[now]-1){
            now /= 2;
        }
        else{
            for(int nx : {now-1, now+1}){
                if(0<=nx && nx<MAX && visited[nx]==visited[now]-1){
                    now = nx;
                    break;
                }
            }
        }
    }
    return visited[K];
}

int main(void){
    // freopen("input.txt", "r", stdin);

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    visited = vector<int>(MAX, -1);

    int result = bfs();

    cout << result << '\n';
    for(int r : route){
        cout << r << ' ';
    }

    return 0;
}