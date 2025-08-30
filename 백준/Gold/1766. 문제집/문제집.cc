#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MX = 32001;

int N, M;
vector<int> adj[MX];
int in_degree[MX];
priority_queue<int, vector<int>, greater<int>> pq;

int main(void){
	cin >> N >> M;
	int a, b;
	for(int i=0; i<M; i++){
		cin >> a >> b;
		adj[a].push_back(b);
		in_degree[b]++;
	}

	for(int i=1; i<=N; i++){
		if(in_degree[i] != 0) continue;
		pq.push(i);
	}

	while(!pq.empty()){
		int now = pq.top(); pq.pop();

		cout << now << ' ';

		for(int nxt : adj[now]){
			in_degree[nxt]--;
			if(in_degree[nxt] != 0) continue;

			pq.push(nxt);
		}
	}

	cout << '\n';

	return 0;
}