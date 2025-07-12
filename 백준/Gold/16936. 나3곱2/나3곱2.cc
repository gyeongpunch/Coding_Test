#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <cstring>

using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(nullptr);

typedef unsigned long long ll;

const int MX = 100;

int N;
ll arr[MX];
unordered_map<ll, int> Map;
vector<ll> result;
bool resultFlag = false;

void dfs(int depth, ll now){
    if(resultFlag) return;
    if(depth == N){
        for(const ll& r : result){
            cout << r << ' ';
        }
        cout << '\n';
        resultFlag = true;
        return;
    }

    if(now % 3 == 0 && Map[now/3] > 0){
        result.push_back(now/3);
        Map[now/3]--;

        dfs(depth+1, now/3);

        result.pop_back();
        Map[now/3]++;
    }

    if(Map[now*2] > 0){
        result.push_back(now*2);
        Map[now*2]--;

        dfs(depth+1, now*2);

        result.pop_back();
        Map[now*2]++;
    }

}

void solution(){
    for(int i=0; i<N; i++){
        if(resultFlag) return;
        result.push_back(arr[i]);
        Map[arr[i]]--;
        dfs(1, arr[i]);
        result.pop_back();
        Map[arr[i]]++;
    }

}

int main(void){
    fastio;
    
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> arr[i];
        Map[arr[i]]++;
    }

    solution();

    return 0;
}