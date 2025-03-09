#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <cstring>

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(nullptr);

using namespace std;

const int MAX_N = 50;

long long M;
long long arr[MAX_N];
char dq_result;

string str1 = "Messi";
string str2 = "Messi Gimossi";

void dq(int nowIdx, long long target){
    if(target <= 13){
        dq_result = str2[target - 1];
        return;
    }

    if(nowIdx == 1) return;

    if(arr[nowIdx - 1] + 1 == target){
        dq_result = ' ';
        return;
    }

    else if(arr[nowIdx - 1] + 1 < target){
        if(nowIdx == 2) return;

        dq(nowIdx-2, target - arr[nowIdx-1] - 1);
    }

    else{
        dq(nowIdx-1, target);
    }

}

char get_result(){
    if(M <= 13){
        return str2[M-1];
    }

    int idx;
    for(idx=3; idx<MAX_N; idx++){
        arr[idx] = arr[idx-1] + 1 + arr[idx-2];
        // cout << arr[idx] << '\n';
        if(arr[idx] >= M) break;
    }

    dq(idx, M);

    return dq_result;
}

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    cin >> M;

    arr[1] = 5;
    arr[2] = 13;

    char result = get_result();

    if(result == ' '){
        cout << "Messi Messi Gimossi\n";
    }
    else{
        cout << result << '\n';
    }
    
    return 0;
}