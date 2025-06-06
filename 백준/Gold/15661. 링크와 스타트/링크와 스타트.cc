#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <cstring>

using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(nullptr);

const int MX = 20;

int N;
int arr[MX][MX];
int visited[MX];
int result = 1e9;

void calc(){
    int start = 0, link = 0;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(i == j) continue;
            if(visited[i] != visited[j]) continue;

            if(visited[i] == 0){
                start += arr[i][j];
            }
            else{
                link += arr[i][j];
            }
        }
    }

    result = min(result, abs(start - link));
}

void get_team(int depth, int prev){
    if(1 <= depth && depth < N){
        calc();
        if(depth == N - 1) return;
    }

    for(int i=prev+1; i<N; i++){
        visited[i] = 1;

        get_team(depth+1, i);

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
    get_team(0, -1);

    cout << result << '\n';

    return 0;
}