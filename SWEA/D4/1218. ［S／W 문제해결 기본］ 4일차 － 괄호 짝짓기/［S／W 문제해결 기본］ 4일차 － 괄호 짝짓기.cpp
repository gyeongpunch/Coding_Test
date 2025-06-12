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

int N;
string str;

unordered_map<char, char> stackMap = {
    {'(', ')'},
    {')', '('},
    {'<', '>'},
    {'>', '<'},
    {'{', '}'},
    {'}', '{'},
    {'[', ']'},
    {']', '['},
};

int result;

void init(){

}

void input(){
    cin >> N >> str;
}

void solution(){
    stack<char> stk;
    for(int i=0; i<N; i++){
        if(!stk.empty() && str[i]==stackMap[stk.top()]){
            stk.pop();
        }
        else{
            stk.push(str[i]);
        }
    }

    if(stk.empty()){
        result = 1;
    }
    else{
        result = 0;
    }
}

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    int T=10;
    // cin >> T;
    for(int t=1; t<=T; t++){    
        init();
        input();
        solution();

        cout << '#' << t << ' ' << result << '\n';
    }

    return 0;
}