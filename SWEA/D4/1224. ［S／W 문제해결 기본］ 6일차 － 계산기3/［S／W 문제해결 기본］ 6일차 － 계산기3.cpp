#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <cstring>
#include <stack>

using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(nullptr);

int N;
int result;
string s;

unordered_set<char> opSet = {'+', '*'};

void init(){

}

void input(){
    cin >> N;
    cin >> s;
}

int priority(char op) {
    if(op == '*') return 2;
    if(op == '+') return 1;
    return 0;
}

string toPostfix(string s) {
    stack<char> op;
    string out = "";
    for(char c : s) {
        if(isdigit(c)) out += c;
        else if(c == '(') op.push(c);
        else if(c == ')') {
            while(!op.empty() && op.top() != '(') {
                out += op.top(); op.pop();
            }
            op.pop(); // '(' 버림
        }
        else { // 연산자
            while(!op.empty() && priority(op.top()) >= priority(c))
                out += op.top(), op.pop();
            op.push(c);
        }
    }
    while(!op.empty()) out += op.top(), op.pop();
    return out;
}

int calc(string postfix) {
    stack<int> st;
    for(char c : postfix) {
        if(isdigit(c)) st.push(c-'0');
        else {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            if(c == '+') st.push(a+b);
            else if(c == '*') st.push(a*b);
        }
    }
    return st.top();
}

void solution(){
    string pf = toPostfix(s);
    result = calc(pf);
}

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    int T=10;
    for(int t=1; t<=T; t++){    
        init();
        input();
        solution();

        cout << '#' << t << ' ' << result << '\n';
    }

    return 0;
}