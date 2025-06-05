#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <cstring>

using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(nullptr);

int N;
int broken[10];

int can_make(int target){
    if(target == 0) return broken[0] == 1 ? 0 : 1;
    int len = 0;

    while(target > 0){
        int rest = target % 10;
        target /= 10;
        if(broken[rest] == 1) return 0;
        len++;
    }
    return len;
}

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    cin >> N;
    int b, bn;
    cin >> b;
    
    for(int i=0; i<b; i++){
        cin >> bn;
        broken[bn] = 1;
    }

    int result = abs(N - 100);

    for(int i=0; i<1000000; i++){
        int len = can_make(i);

        if(len > 0){
            int ans = len + abs(N - i);
            result = min(result, ans);
        }
    }
    
    cout << result << '\n';

    return 0;
}