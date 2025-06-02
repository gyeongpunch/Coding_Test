#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <cstring>

using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(nullptr);



int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    int T, N;
    cin >> T;

    string w, ww;
    for(int t=0; t<T; t++){
        cin >> N;
        unordered_map<string, int> wearMap;

        for(int i=0; i<N; i++){
            cin >> w >> ww;
            wearMap[ww]++; 
        }
        int result = 1;

        for(const pair<string, int>& wear : wearMap){
            result *= (wear.second + 1);
        }
        result--;

        cout << result << '\n';
    }

    return 0;
}