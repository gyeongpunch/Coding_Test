#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <cstring>

using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(nullptr);

string str;
string target;
vector<char> stk;

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    cin >> str >> target;

    for(int i=0; i<str.length(); i++){
        stk.push_back(str[i]);

        if(stk.size() < target.length()) continue;

        bool flag = true;
        for(int i=0; i<target.length(); i++){
            if(stk[stk.size() - target.length() + i] != target[i]){
                flag = false;
                break;
            }
        }

        if(flag){
            for(int i=0; i<target.length(); i++){
                stk.pop_back();
            }
        }
    }

    if(stk.empty()){
        cout << "FRULA\n";
    }
    else{
        for(char c : stk){
            cout << c;
        }
        cout << '\n';
    }

    return 0;
}