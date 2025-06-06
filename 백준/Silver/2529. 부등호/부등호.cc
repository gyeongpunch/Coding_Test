#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <cstring>

using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(nullptr);

const int MX=10;

int K;
char op[MX];
vector<int> path;
int visited[10];
string mx = "0000000000", mn = "9999999999";

void get_all_nums(int depth){
    if(depth == K+1){
        string str = "";
        for(int n : path){
            str = str + (char)('0' + n);
        }
        mx = max(mx, str);
        mn = min(mn, str);
        return;
    }

    for(int i=0; i<10; i++){
        if(visited[i] == 1) continue;
        if(depth == 0 || 
        (op[depth-1] == '<' && path[depth-1] < i) || 
        (op[depth-1] == '>' && path[depth-1] > i)){
            path.push_back(i);
            visited[i] = 1;

            get_all_nums(depth+1);

            path.pop_back();
            visited[i] = 0;
        }
    }
}

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    cin >> K;
    for(int i=0; i<K; i++){
        cin >> op[i];
    }

    get_all_nums(0);

    cout << mx << '\n' << mn << '\n';

    return 0;
}