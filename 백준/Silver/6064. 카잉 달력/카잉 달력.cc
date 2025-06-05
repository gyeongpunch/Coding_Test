#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <cstring>

using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(nullptr);

int M, N, x, y;

int gcd(int a, int b){
    if(b==0){
        return a;
    }
    return gcd(b, a%b);
}

int get_result(int M, int N, int x, int y){
    int lastNum = M * N / gcd(M, N);

    for(int year=x; year<=lastNum; year+=M){
        if((year-1) % N + 1 == y) return year;
    }
    return -1;
}

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    int T;
    cin >> T;
    for(int t=0; t<T; t++){
        cin >> M >> N >> x >> y;

        int result = get_result(M, N, x, y);

        cout << result << '\n';        
    }

    return 0;
}