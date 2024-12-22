#include <iostream>
#include <vector>
#include <queue>

#define MAX 100000

using namespace std;

int main(void){
    int N, K;
    cin >> N >> K;
    vector<int> visited(MAX+1, -1);
    visited[N] = 0;
    queue<int> q;
    q.push(N);

    while(!q.empty()){
        int x = q.front();
        q.pop();

        int next_x[] = {x-1, x+1, x*2};
        for(int nx : next_x){
            if(0<=nx && nx<MAX+1 && visited[nx]==-1){
                q.push(nx);
                visited[nx] = visited[x] + 1;
            }
        }
    }

    cout << visited[K] << endl;

    return 0;
}