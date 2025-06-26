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
#include <climits>

using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(nullptr);

struct Info{
    long long n;
    string c;
};

long long S, T;

void bfs(){
    if(S==T){
        cout << 0 << '\n';
        return;
    }

    queue<Info> q;
    unordered_set<long long> Set;
    q.push({S, ""});
    Set.insert(S);

    while(!q.empty()){
        Info now = q.front(); q.pop();

        if(now.n == T){
            cout << now.c << '\n';
            return;
        }

        if(now.n*now.n < LLONG_MAX){
            long long n = now.n*now.n;
            if(Set.find(n) == Set.end()){
                q.push({n, now.c+'*'});
                Set.insert(n);
            }
        }
        if(now.n * 2 < LLONG_MAX){
            long long n = now.n * 2;
            if(Set.find(n) == Set.end()){
                q.push({n, now.c+'+'});
                Set.insert(n);
            }
        }
        if(now.c.length() >= 1) continue;
        q.push({0, "-"});
        Set.insert(0);
        if(now.n==0) continue;
        q.push({1, "/"});
        Set.insert(1);
    }
    cout << -1 << '\n';
}

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    cin >> S >> T;

    bfs();

    return 0;
}