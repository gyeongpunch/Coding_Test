#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <cstring>

using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(nullptr);

int N, M;
unordered_map<string, string> passMap;

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    cin >> N >> M;
    string s, p;
    for(int i=0; i<N; i++){
        cin >> s >> p;
        passMap[s] = p;
    }
    for(int i=0; i<M; i++){
        cin >> s;
        cout << passMap[s] << '\n';
    }


    return 0;
}