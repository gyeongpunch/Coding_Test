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

const int MX = 8;

int N, M;
int arr[MX];
vector<int> path;


void dfs(int depth, int prev){
    if(depth==M){
        for(int n : path){
            cout << n << ' ';
        }
        cout << '\n';
        return;
    }

    int last = -1;
    for(int i=prev; i<N; i++){
        if(arr[i]==last) continue;

        path.push_back(arr[i]);

        dfs(depth+1, i);

        path.pop_back();
        last=arr[i];
    }
}
int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    cin >> N >> M;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }

    sort(arr, arr+N);

    dfs(0, 0);

    return 0;
}