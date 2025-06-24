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
    int cnt;
    string nowCommand;
};

const int MOD = 10000;

int T, A, B;
Info visited[MOD];
string result;

void init(){
    result = "";
    for(int i=0; i<MOD; i++){
        visited[i].cnt = -1;
    }
}

void D_command(int now, int& nxt){
    nxt = (now * 2) % MOD;
}

void S_command(int now, int& nxt){
    nxt = (now + MOD - 1) % MOD;
}

void L_command(int now, int& nxt){
    int buffer[4];
    for(int i=0; i<4; i++){
        buffer[(6-i)%4] = now%10;
        now/=10;
    }

    // for(int i=0; i<4; i++){
    //     cout << buffer[i] << ' ';
    // }
    // cout << '\n';

    int tmp=0;
    for(int i=0; i<4; i++){
        tmp = tmp*10 + buffer[i];
    }
    nxt=tmp;
}


void R_command(int now, int& nxt){
    int buffer[4];
    for(int i=0; i<4; i++){
        buffer[(4-i)%4] = now%10;
        now/=10;
    }
    int tmp=0;
    for(int i=0; i<4; i++){
        tmp = tmp*10 + buffer[i];
    }
    nxt=tmp;
}

void bfs(){

    queue<int> q;
    q.push(A);
    visited[A].cnt = 0;
    visited[A].nowCommand = "";

    while(!q.empty()){
        int now = q.front(); q.pop();

        if(now == B){
            result = visited[now].nowCommand;
        }

        int nxt;
        for(int i=0; i<4; i++){
            if(i==0) D_command(now, nxt);
            else if(i==1) S_command(now, nxt);
            else if(i==2) L_command(now, nxt);
            else if(i==3) R_command(now, nxt);


            // if(i==2 && now == 1000 && A==1000){
            //     cout << nxt << '\n';
            //     return;
            // }
            
            if(visited[nxt].cnt != -1) continue;

            q.push(nxt);
            visited[nxt].cnt = visited[now].cnt + 1;
            if(i==0) visited[nxt].nowCommand = visited[now].nowCommand + 'D';
            else if(i==1) visited[nxt].nowCommand = visited[now].nowCommand + 'S';
            else if(i==2) visited[nxt].nowCommand = visited[now].nowCommand + 'L';
            else if(i==3) visited[nxt].nowCommand = visited[now].nowCommand + 'R';
        }
    }
}

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    cin >> T;
    for(int t=0; t<T; t++){
        init();

        cin >> A >> B;

        bfs();

        cout << result << '\n';
    }

    return 0;
}