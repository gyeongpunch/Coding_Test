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
#include <climits>

using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(nullptr);
typedef long long ll;

const int MX = 10000;

ll N;
int M;
int arr[MX];

ll get_cnt(ll mid){
    if(mid < 0) return 0;
    ll cnt = 0;
    for(int i=0; i<M; i++){
        cnt += mid / arr[i];
    }
    return cnt + M;
}

ll get_end_time(){
    if(N <= M){
        cout << N << '\n';
        return -1;
    }

    ll l=0, r=30LL * N, endTime=0;

    while(l <= r){
        ll mid = (l + r) / 2;

        ll total = get_cnt(mid);

        if(total >= N){
            endTime = mid;
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    return endTime;
}

void solution(){
    ll endTime = get_end_time();

    if(endTime == -1) return;

    ll prevTime = get_cnt(endTime - 1);

    for(int i=0; i<M; i++){
        if(endTime % arr[i] == 0){
            prevTime++;
            if(prevTime == N){
                cout << i+1 << '\n';
                return;
            }
        }
    }
}

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    cin >> N >> M;
    for(int i=0; i<M; i++) cin >> arr[i];

    solution();

    return 0;
}