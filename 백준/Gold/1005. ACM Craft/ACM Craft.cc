#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int MX = 1001;

int N, K;
vector<int> adj[MX];
int times[MX];
int dp[MX];
int End;

void init(){
	for(int i=0; i<MX; i++){
		adj[i].clear();
	}
	memset(times, 0, sizeof(times));
	memset(dp, -1, sizeof(dp));
}

void input(){
	cin >> N >> K;
	for(int i=1; i<=N; i++){
		cin >> times[i];
	}
	int x, y;
	for(int i=0; i<K; i++){
		cin >> x >> y;
		adj[y].push_back(x);
	}
	cin >> End;
}

int solution(int now){
	if(dp[now] != -1){
		return dp[now];
	}
	int mx = 0;
	for(const int &nxt : adj[now]){
		mx = max(mx, solution(nxt));
	}
	dp[now] = mx + times[now];

	return dp[now];
}

int main() {
	int T;
	cin >> T;

	for(int t=0; t<T; t++){
		init();

		input();

		cout << solution(End) << '\n';
	}

	return 0;
}