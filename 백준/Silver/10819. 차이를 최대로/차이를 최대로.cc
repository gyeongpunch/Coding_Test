#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <cstring>

using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(nullptr);

const int MX = 8;

int N;
int arr[MX];
int visited[MX];
vector<int> path;
int result = 0;

void calc(){
    int sum = 0;
    for(int i=0; i<N-1; i++){
        sum += abs(path[i] - path[i+1]);
    }

    result = max(result, sum);
}

void get_result(int depth){
    if(depth == N){
        calc();

        // for(int n : path){
        //     cout << n << ' ';
        // }
        // cout << '\n';

        return;
    }

    for(int i=0; i<N; i++){
        if(visited[i] == 1) continue;

        path.push_back(arr[i]);
        visited[i] = 1;

        get_result(depth + 1);
        // return;

        path.pop_back();
        visited[i] = 0;
    }
}

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }

    get_result(0);

    cout << result << '\n';

    return 0;
}