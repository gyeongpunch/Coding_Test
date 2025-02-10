#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

#define MAX_SIZE 1000000

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);

    int T, N;
    cin >> T;
    long long G[MAX_SIZE + 1] = {0};

    for(int i=1; i<MAX_SIZE + 1; i++){
        for(int j=i; j<MAX_SIZE + 1; j+=i){
            G[j] +=i;
        }
        G[i] += G[i - 1];
    }


    for(int i=0; i<T; i++){
        cin >> N;
        cout << G[N] << '\n';
    }

    return 0;
}