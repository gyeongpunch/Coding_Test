#include <iostream>
#include <stack>
#include <numeric>
using namespace std;
typedef long long ll;

const int MX = 80000;

struct Loc{
	int n, idx;
};

int N;
stack<Loc> stk;
int mark[MX];

int main() {
	cin >> N;
	int n;
	for(int i=0; i<N; i++){
		cin >> n;
		while(!stk.empty() && stk.top().n <= n){
			Loc now = stk.top(); stk.pop();
			mark[now.idx] = i - now.idx - 1;
		}
		stk.push({n, i});
	}

	while(!stk.empty()){
		Loc now = stk.top(); stk.pop();
		mark[now.idx] = N - now.idx - 1;
	}

	ll result = accumulate(mark, mark+N, 0LL);
	
	cout << result << '\n';
	return 0;
}