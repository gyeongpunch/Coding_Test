#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <cstring>

using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(nullptr);

const int MX = 9;

int N;
vector<int> path;
int visited[MX];

void make_perm(int depth){
    if(depth == N){
        for(int n : path){
            cout << n << ' ';
        }
        cout << '\n';
        return;
    }


    for(int i=1; i<=N; i++){
        if(visited[i] == 1) continue;

        path.push_back(i);
        visited[i] = 1;

        make_perm(depth + 1);

        path.pop_back();
        visited[i] = 0;
    }
}

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    cin >> N;

    make_perm(0);

    return 0;
}