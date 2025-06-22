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

const int MX = 50;

int N, K;
string arr[MX];
int arrResult[MX];
int result;
int path;

void calc(){
    int now = 0;

    for(int i=0; i<N; i++){
        if ((arrResult[i] & ~path) == 0) now++;
    }

    result = max(result, now);
}

void dfs(int depth, int prev){
    if(depth >= K){
        calc();
        return;
    }

    for(int i=prev+1; i<26; i++){
        if(path & (1 << i)) continue;

        path |= (1 << i);

        dfs(depth + 1, i);

        path ^= (1 << i);
    }
}

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    path |= (1 << ('a'-'a'));
    path |= (1 << ('n'-'a'));
    path |= (1 << ('t'-'a'));
    path |= (1 << ('i'-'a'));
    path |= (1 << ('c'-'a'));

    cin >> N >> K;
    for(int i=0; i<N; i++){
        cin >> arr[i];
        for(int j=0; j<arr[i].length(); j++){
            arrResult[i] |= (1 << (arr[i][j] - 'a'));
        }
    }

    if(K < 5){
        cout << 0 << '\n';
        return 0;
    }

    dfs(5, -1);

    cout << result << '\n';

    return 0;
}