#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int F, S, G, U, D;
vector<int> visited;

int bfs(){
    queue<int> q;
    q.push(S);
    visited[S] = 0;

    while(!q.empty()){
        int x = q.front();
        q.pop();

        int next[] = {x+U, x-D};
        for(int nx : next){
            if(0<nx && nx<F+1 && visited[nx]==-1){
                q.push(nx);
                visited[nx] = visited[x] + 1;
            }
        }
    }
    return visited[G];
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> F >> S >> G >> U >> D;
    visited = vector<int>(F+1, -1);

    int result = bfs();

    if(result==-1){
        cout << "use the stairs" << endl;
    }
    else{
        cout << result << endl;
    }

    return 0;
}