#include <iostream>
#include <algorithm>
#include <string>
#include <climits>
#include <vector>
using namespace std;

const int MX = 20;

int N, M;
string s;
int nums[MX];
char ops[MX];
int result = INT_MIN;
vector<int> path;

int cal_op(int a, char op, int b) {
    if(op == '+') return a + b;
    if(op == '-') return a - b;
    return a * b;
}

void calc(){
	// 1. 괄호 처리
    vector<int> nTmp;
    vector<char> oTmp;
    int nIdx = 0, oIdx = 0, pIdx = 0;

    while (nIdx < M + 1) {
        if (pIdx < path.size() && oIdx == path[pIdx] && nIdx < M) {
            int n = cal_op(nums[nIdx], ops[oIdx], nums[nIdx + 1]);
            nTmp.push_back(n);
			if (oIdx + 1 < M) oTmp.push_back(ops[oIdx+1]);
            nIdx += 2;
            oIdx += 2;
            pIdx++;
        }
		else {
            nTmp.push_back(nums[nIdx++]);
            if (oIdx < M) oTmp.push_back(ops[oIdx++]);
        }
    }
	// for(int p : path){
	// 	cout << p << ' ';
	// }
	// cout << '\n';
	// for(int n : nTmp){
	// 	cout << n << ' ';
	// }
	// cout << '\n';
	// for(char n : oTmp){
	// 	cout << n << ' ';
	// }
	// cout << "\n";


    // 2. 곱셈 우선 계산
    vector<int> nStack;
	nStack.clear();
    vector<char> oStack;
	oStack.clear();
    nStack.push_back(nTmp[0]);
    // cout << "\n\n\n";

	// cout << "!!!!!!!!!!!!!!!!\n";
	// cout << oTmp.size();

	for (int i = 0; i < oTmp.size(); i++) {
        if (oTmp[i] == '*') {
            int x = nStack.back(); nStack.pop_back();
            int y = nTmp[i+1];
			// cout << y << ' ';
            nStack.push_back(x * y);
        }
		else {
            nStack.push_back(nTmp[i+1]);
            oStack.push_back(oTmp[i]);
        }
    }
    // cout << "\n\n\n";

	// for(int n : nStack){
	// 	cout << n << ' ';
	// }
	// cout << '\n';
	// for(char n : oStack){
	// 	cout << n << ' ';
	// }
	// cout << "\n\n";

    // 3. 덧셈/뺄셈 계산
    int val = nStack[0];
    for (int i = 0; i < oStack.size(); ++i) {
        if (oStack[i] == '+') val += nStack[i+1];
        else val -= nStack[i+1];
    }
    result = max(result, val);
}

void dfs(int prev) {
	calc();

	for(int i=prev+2; i<M; i++){
		path.push_back(i);

		dfs(i);

		path.pop_back();
	}

}

void solution(){
	if(N == 1) {
		result = s[0] - '0';
		return;
	}

	dfs(-2);

}

int main() {
    cin >> N >> s;
	M = N/2;
	for(int i=0; i<N; i++){
		if(i%2 == 0){
			nums[i/2] = s[i] - '0';
		}
		else{
			ops[i/2] = s[i];
		}
	}

	solution();

	cout << result << '\n';

    return 0;
}
