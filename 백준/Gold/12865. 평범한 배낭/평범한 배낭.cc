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

struct Info{
    int w, v;

    Info() : w(0), v(0) {}
    Info(int w, int v) : w(w), v(v) {}
};

const int MX = 100;
const int MXK = 100001;

int N, K;
Info arr[MX];
int dp[MXK];

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    cin >> N >> K;
    int w, v;
    for(int i=0; i<N; i++){
        cin >> w >> v;
        arr[i] = Info(w, v);
    }
    
    for(int i=0; i<N; i++){
        for(int j=K; j>=arr[i].w; j--){
            dp[j] = max(dp[j], dp[j - arr[i].w] + arr[i].v);
        }
    }

    cout << dp[K] << '\n';

    return 0;
}