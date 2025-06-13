#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <cstring>

using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(nullptr);

const int MX = 1000;

int N;
int arr[MX];
int dp1[MX], dp2[MX];

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }

    fill(dp1, dp1+N, 1);
    fill(dp2, dp2+N, 1);


    int result = 0;
    for(int i=1; i<N; i++){
        for(int j=0; j<i; j++){
            if(arr[i] > arr[j]){
                dp1[i] = max(dp1[i], dp1[j]+1);
            }
        }
    }

    for(int i=N-2; i>-1; i--){
        for(int j=N-1; j>i; j--){
            if(arr[i] > arr[j]){
                dp2[i] = max(dp2[i], dp2[j]+1);
            }
        }
    }

    for(int i=0; i<N; i++){
        result = max(result, dp1[i]+dp2[i]-1);
    }

    cout << result << '\n';

    return 0;
}