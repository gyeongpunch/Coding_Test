#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define MAX_N 11

int N;
int arr[MAX_N];
int ops[3];
vector<int> path;
int minResult = 1e9, maxResult = -1e9;

void calc(){
    int now = arr[0];

    for(int i=0; i<N-1; i++){
        if(path[i] == 0){
            now += arr[i+1];
        }
        else if (path[i] == 1){
            now -= arr[i+1];
        }
        else if (path[i] == 2){
            now *= arr[i+1];
        }
    }
    minResult = min(minResult, now);
    maxResult = max(maxResult, now);
}

void makePermu(int depth){
    if(depth == N-1){
        calc();
        return;
    }

    for(int i=0; i<3; i++){
        if(ops[i] > 0){
            ops[i]--;
            path.push_back(i);

            makePermu(depth + 1);

            path.pop_back();
            ops[i]++;
        }
    }
}

int main() {
    fastio;

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    for(int i=0; i<3; i++){
        cin >> ops[i];
    }

    makePermu(0);

    cout << minResult << ' ' << maxResult << '\n';

    return 0;
}