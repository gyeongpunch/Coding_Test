#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <cstring>

using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(nullptr);

const int MX = 12;

int K;
int S[MX];
vector<int> path;

void get_result(int depth, int prev){
    if(depth == 6){
        for(int idx : path){
            cout << S[idx] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i=prev+1; i<K; i++){

        path.push_back(i);

        get_result(depth + 1, i);

        path.pop_back();
    }
}

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    while(true){
        cin >> K;
        if(K == 0) break;
        for(int i=0; i<K; i++){
            cin >> S[i];
        }

        get_result(0, -1);
        cout << '\n';
    }

    return 0;
}