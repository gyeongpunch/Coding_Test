#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <cstring>

using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(nullptr);

const int MX=1000001;

int N, M;
int bitMax = 2;
int result = 0;
int visited[MX];
queue<int> q;

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    cin >> N >> M;
    int n;
    for(int i=0; i<M; i++){
        cin >> n;
        visited[n] = 1;
        q.push(n);
    }

    while(bitMax <= N){
        bitMax = (bitMax << 1);
    }

    while(!q.empty()){
        result++;
        int sz = q.size();

        for(int i=0; i<sz; i++){
            int now = q.front(); q.pop();

            for(int b=1; b<bitMax; b = (b<<1)){
                int nx = now ^ b;

                if(nx > N) continue;
                if(visited[nx] == 1) continue;

                q.push(nx);
                visited[nx] = 1;
            }
        }
    }

    cout << result-1 << '\n';

    return 0;
}