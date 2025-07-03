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

const int MX = 200000;

int N, C;
int arr[MX];
int visited[MX];
int result;

void bs(int left, int right){
    int mid = (left + right) / 2;
}

void solution(int left, int right){
    if(N == 2) {
        result = arr[N-1] - arr[0];
        return;
    }

    while(left <= right){
        // cout << left << ' ' << right << '\n';

        int mid = (left + right) / 2;
        int prev = arr[0];
        int cnt = 1;

        for(int i=1; i<N; i++){
            if(arr[i] - prev >= mid){
                prev = arr[i];
                cnt++;
                // cout << prev << '\n';
            }
        }

        if(cnt >= C){
            result = max(result, mid);
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
}

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    cin >> N >> C;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }

    sort(arr, arr+N);

    solution(1, arr[N-1]);

    cout << result << '\n';

    return 0;
}