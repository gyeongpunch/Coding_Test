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
vector<int> total;
vector<int> path;
int visited[10001];

void get_perm(int depth, int prev){
    if(depth == M){
        for(int n : path){
            cout << n << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i=0; i<N; i++){
        if(visited[total[i]] == 0){
            path.push_back(total[i]);
            visited[total[i]] = 1;

            get_perm(depth + 1, i);

            path.pop_back();
            visited[total[i]] = 0;
        }
    }
}

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    cin >> N >> M;
    int n;
    for(int i=0; i<N; i++){
        cin >> n;
        total.push_back(n);
    }

    sort(total.begin(), total.end());

    get_perm(0, -1);

    return 0;
}