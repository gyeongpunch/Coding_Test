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

const int MX = 1000001;
const int MOD = 1000000000;

int N;
long long arr[MX];
int flag = 1;

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    cin >> N;
    if(N==0) flag = 0;
    else if(N<0){
        N *= -1;
        if((N*(-1))%2==0){
            flag = -1;
        }
    }
    arr[0] = 0;
    arr[1] = 1;
    
    for(int i=2; i<=N; i++){
        arr[i] = (arr[i-1] + arr[i-2]) % MOD;
    }
    long long result = arr[N];
    cout << flag << '\n' << result << '\n';

    // for(int i=0; i<=N; i++) cout << arr[i] << ' ';

    return 0;
}