#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

int N, M;
unordered_map<string, int> s2i;
unordered_map<int, string> i2s;

int main(void){
    fastio;

    // freopen("input.txt", "r", stdin);

    cin >> N >> M;
    string tmp;
    for(int i=0; i<N; i++){
        cin >> tmp;
        s2i[tmp] = i + 1;
        i2s[i+1] = tmp;
    }

    for(int i=0; i<M; i++){
        cin >> tmp;

        if(isdigit(tmp[0])){
            cout << i2s[stoi(tmp)] << '\n';
        }
        else{
            cout << s2i[tmp] << '\n';
        }
    
    }

    return 0;
}