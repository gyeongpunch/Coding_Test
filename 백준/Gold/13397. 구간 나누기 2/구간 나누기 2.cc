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
    int cnt, mn, mx;
    Info(int cnt, int mn, int mx) : cnt(cnt), mn(mn), mx(mx) {}
};

const int MX = 5000;

int N, M;
int arr[MX];

bool simulation(int mid){
    Info now(1, arr[0], arr[0]);

    for(int i=1; i<N; i++){
        if(arr[i]-now.mn > mid || now.mx-arr[i] > mid){
            now.cnt++;
            now.mn = now.mx = arr[i];
            continue;
        }
        now.mn = min(now.mn, arr[i]);
        now.mx = max(now.mx, arr[i]);
    }

    if(now.cnt > M) return false;
    return true;

}

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    cin >> N >> M;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }

    int l=0;
    int r = *max_element(arr, arr+N);
    int result = r+1;

    while(l<=r){
        int mid = (l + r) / 2;

        bool flag = simulation(mid);

        if(flag){
            r = mid - 1;
            result = min(result, mid);
        }
        else{
            l = mid + 1;
        }
    }

    cout << result << '\n';

    return 0;
}