#include <iostream>
#include <stack>

using namespace std;

typedef long long ll;

struct Info{
	int n, cnt;
};

const int MX = 500001;

int N;
int arr[MX];
stack<Info> s;
ll result;

int main() {
	cin >> N;
	for(int i=0; i<N; i++){
		cin >> arr[i];
	}

	for(int i=0; i<N; i++){
		int cnt = 1;

		while(!s.empty() && s.top().n <= arr[i]){
			// cout<< s.top().n  << ' ' << arr[i] << '\n';
			result += s.top().cnt;
			if(s.top().n == arr[i]){
				cnt += s.top().cnt;
			}
			s.pop();
		}
		if(!s.empty()){
			result++;
		}
		s.push({arr[i], cnt});
	}
	cout << result << '\n';
	
	return 0;
}