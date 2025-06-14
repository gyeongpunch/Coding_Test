#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <cstring>
#include <stack>

using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(nullptr);

const int MX = 20;

int N, B;
int arr[MX];
int result;

void init(){
    result = 1e9;
}

void input(){
    cin >> N >> B;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
}

void solution(){
    for(int bit=1; bit < (1<<N); bit++){
        int sum = 0;
        for(int i=0; i<N; i++){
            if(bit & (1<<i)) sum += arr[i];
        }
        if(sum >= B && sum < result) result = sum;
    }
    result -= B;
}

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    int T;
    cin >> T;
    for(int t=1; t<=T; t++){    
        init();
        input();
        solution();

        cout << '#' << t << ' ' << result << '\n';
    }

    return 0;
}