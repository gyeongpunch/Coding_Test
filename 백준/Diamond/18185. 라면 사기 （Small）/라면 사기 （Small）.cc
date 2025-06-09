#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <cstring>

using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(nullptr);

const int MX = 10002;

int N;
int arr[MX];
int result = 0;

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }

    for(int i=0; i<N; i++){
        if(arr[i+1]>arr[i+2]){
            int two = min(arr[i], arr[i+1] - arr[i+2]);
            result += two * 5;
            arr[i] -= two;
            arr[i+1] -= two;
            
        }

        int three = min({arr[i], arr[i+1], arr[i+2]});
        result += three * 7;
        arr[i] -= three;
        arr[i+1] -= three;
        arr[i+2] -= three;
        

        if(arr[i] == 0) continue;
        
        result += arr[i+1] * 5;
        arr[i] -= arr[i+1];
        arr[i+1] = 0;


        if(arr[i] == 0) continue;

        result += arr[i] * 3;
        arr[i] = 0;
    }

    cout << result << '\n';

    return 0;
}