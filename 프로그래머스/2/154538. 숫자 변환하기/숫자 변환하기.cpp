#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int x, int y, int n) {
    vector<int> answer(1000001, -1);
    queue<int> q;
    q.push(x);
    answer[x] = 0;
    
    while(!q.empty()){
        int x = q.front();
        if(x==y){
            return answer[y];
        }
        q.pop();
        for(int nx : {x+n, x*2, x*3}){
            if(nx<=1000000 && answer[nx]==-1){
                q.push(nx);
                answer[nx] = answer[x] + 1;
            }
        }
    }
    
    
    return answer[y];
}