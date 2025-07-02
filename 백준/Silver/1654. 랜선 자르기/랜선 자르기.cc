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
typedef long long ll;

const int MX = 10000;

ll K, N;
ll arr[MX];

ll get_line(ll length){
    ll ret = 0;
    for(int i=0; i<K; i++){
        ret += arr[i] / length;
    }
    return ret;
}

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    cin >> K >> N;
    for(int i=0; i<K; i++){
        cin >> arr[i];
    }

    ll left = 1;
    ll right = *max_element(arr, arr+K);
    ll result = 1;

    while(left <= right){
        ll mid = (left + right) / 2;

        ll cnt = get_line(mid);

        if(cnt >= N){
            left = mid + 1;
            result = max(result, mid);
        }
        else{
            right = mid - 1;
        }
    }

    cout << result << '\n';

    return 0;
}