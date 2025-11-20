#include <iostream>
#include <stack>
#include <string>
using namespace std;

string s;
stack<char> stk;
int result;

void solution(){
	int temp = 1;

	for(int i=0; i<s.length(); i++){
		char c = s[i];
		if(c == '('){
			temp *= 2;
			stk.push(c);
		}
		else if(c == ')'){
			if(stk.empty() || stk.top() != '('){
				result = 0;
				return;
			}
			else{
				if(s[i-1] == '(') result += temp;
				temp /= 2;
				stk.pop();
			}
		}
		else if(c == '['){
			temp *= 3;
			stk.push(c);
		}
		else if(c == ']'){
			if(stk.empty() || stk.top() != '['){
				result = 0;
				return;
			}
			else{
				if(s[i-1] == '[') result += temp;
				temp /= 3;
				stk.pop();
			}
		}
		// cout << c << '\n';
		// cout << "result: " << result << '\n';
		// cout << "temp: " << temp << '\n';
		// cout << "\n\n";
	}
	if(!stk.empty()) result = 0;
}


int main() {
	cin >> s;

	solution();

	cout << result << '\n';

	return 0;
}