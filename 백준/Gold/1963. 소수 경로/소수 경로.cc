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

const int MX = 10000;

int A, B;
int visited[MX];

bool isPrime(int a){
    for(int i=2; i*i<=a; i++){
        if(a % i == 0) return false;
    }
    return true;
}

int bfs(){
    memset(visited, -1, sizeof(visited));
    visited[A] = 0;
    queue<int> q;
    q.push(A);

    while(!q.empty()){
        int now = q.front(); q.pop();

        // cout << now << '\n';

        if(now == B) return visited[now];

        int tmp[4];
        int m = now;
        for(int i=0; i<4; i++){
            tmp[3-i] = m % 10;
            m /= 10;
        }

        for(int i=0; i<4; i++){
            for(int j=0; j<=9; j++){
                int b = 0;
                for(int k=0; k<4; k++){
                    if(i==k){
                        b = b*10 + j;
                    }
                    else{
                        b = b*10 + tmp[k];
                    }
                }

                // cout << b << '\n';

                if(b<1000 || 9999<b) continue;
                if(visited[b] != -1) continue;
                if(!isPrime(b)) continue;

                // cout << b << '\n';

                q.push(b);
                visited[b] = visited[now] + 1;
            }
        }
    }
    return -1;
}

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    int T;
    cin >> T;
    for(int t=0; t<T; t++){
        cin >> A >> B;
        int result = bfs();
        if(result == -1) cout << "Impossible" << '\n';
        else cout << result << '\n';
    }

    return 0;
}