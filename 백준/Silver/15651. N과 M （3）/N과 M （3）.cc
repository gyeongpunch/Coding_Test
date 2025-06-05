#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <cstring>

using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(nullptr);

int N, M;
vector<int> path;

void get_perm(int depth){
    if(depth == M){
        for(int n : path){
            cout << n << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i=1; i<=N; i++){
        path.push_back(i);

        get_perm(depth + 1);

        path.pop_back();
    }
}

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    cin >> N >> M;
    
    get_perm(0);

    return 0;
}