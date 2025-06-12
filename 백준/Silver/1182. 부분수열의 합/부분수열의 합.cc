#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <cstring>

using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(nullptr);

const int MX = 20;

int N, S;
int arr[MX];

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    cin >> N >> S;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }

    int result = 0;
    for(int idx=1; idx<(1<<N); idx++){
        int sum = 0;
        for(int i=0; i<N; i++){
            if((idx & (1<<i)) != 0){
                sum += arr[i];
            }
        }
        if(sum == S) {
            result++;
            // cout << idx << '\n';
        }
    }

    cout << result << '\n';

    return 0;
}