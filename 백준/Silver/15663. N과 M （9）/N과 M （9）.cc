#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <queue>
#include <cstring>

using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(nullptr);

const int MX_N = 8;

int N, M;
int arr[MX_N];
int visited[MX_N];
vector<int> path;
set<vector<int>> Set;

void get_result(int depth){
    if(depth == M){
        Set.insert(path);
        return;
    }

    for(int i=0; i<N; i++){
        if(visited[i] == 1) continue;

        path.push_back(arr[i]);
        visited[i] = 1;

        get_result(depth + 1);

        path.pop_back();
        visited[i] = 0;
    }
}

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    cin >> N >> M;
    int a;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }

    sort(arr, arr+N);

    get_result(0);

    for(const auto& seq : Set){
        for(int n : seq){
            cout << n << ' ';
        }
        cout << '\n';
    }


    return 0;
}