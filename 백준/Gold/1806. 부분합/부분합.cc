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

const int MX = 100000;

int N, S;
int arr[MX];

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    cin >> N >> S;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }

    int l = 0, r = 0;
    int now = 0;
    int minLength = N+1;
    while(l<=r && r<=N){
        if(now < S){
            if(r==N) break;
            now += arr[r++];
        }
        else{
            minLength = min(minLength, r-l);
            now -= arr[l++];
        }
        // cout << now << ' ' << l << ' ' << r << '\n';
    }

    if(minLength==N+1) minLength = 0;
    cout << minLength << '\n';

    return 0;
}