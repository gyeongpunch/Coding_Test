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

const int MX = 1000000;

int N;
ll M;
int arr[MX];

ll get_rest(int mid){
    ll ret = 0LL;

    for(int i=0; i<N; i++){
        ret += arr[i] > mid ? arr[i]-mid : 0;
    }
    return ret;
}

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    cin >> N >> M;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }

    int left = 1;
    int right = *max_element(arr, arr+N);
    int result = 0;
    while(left <= right){
        // cout << left << ' ' << right << '\n';
        int mid = (left + right) / 2;

        ll takeTree = get_rest(mid);

        if(takeTree >= M){
            left = mid + 1;
            result = max(result, mid);
        }
        else{
            right = mid - 1;
        }
        // cout << left << ' ' << right << '\n';
    }

    cout << result << '\n';

    return 0;
}