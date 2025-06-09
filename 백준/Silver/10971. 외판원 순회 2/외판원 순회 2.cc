#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <cstring>

using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(nullptr);

const int MX = 10;

int N;
int arr[MX][MX];
vector<int> path;
int visited[MX];
int result = 1e9;

void calc(){
    int score = 0;

    for(int i=0; i<N-1; i++){
        score += arr[path[i]][path[i+1]];
    }
    score += arr[path[N-1]][path[0]];

    result = min(result, score);
}

void get_result(int depth){
    if(depth == N){
        calc();
        return;
    }

    for(int i=0; i<N; i++){
        if(visited[i] == 1) continue;
        if(path.size() > 0 && arr[path[path.size()-1]][i] == 0) continue;
        if(path.size() == N-1 && arr[i][path[0]] == 0) continue;
        path.push_back(i);
        visited[i] = 1;

        get_result(depth + 1);

        path.pop_back();
        visited[i] = 0;
    }
}

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> arr[i][j];
        }
    }

    get_result(0);

    cout << result << '\n';

    return 0;
}