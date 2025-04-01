#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 15

struct Info{
    int start, end, price;
};

int N;
Info arr[MAX_N];
int dp[MAX_N+5];

bool custom_compare(Info a, Info b){
    return a.end < b.end;
}

int main() {
    
    cin >> N;
    int t, p;
    for(int i=0; i<N; i++){
        cin >> t >> p;

        arr[i] = {i, i+t, p};
    }

    sort(arr, arr+N, custom_compare);

    int nowIdx = 0;
    int result = 0;
    for(int i=1; i<MAX_N+5; i++){
        while(nowIdx < N && arr[nowIdx].end == i){
            dp[i] = max(max(dp[i], dp[i-1]), dp[arr[nowIdx].start] + arr[nowIdx].price);
            nowIdx++;
        }
        result = max(result, dp[i]);
    }

    cout << result << '\n';

    return 0;
}