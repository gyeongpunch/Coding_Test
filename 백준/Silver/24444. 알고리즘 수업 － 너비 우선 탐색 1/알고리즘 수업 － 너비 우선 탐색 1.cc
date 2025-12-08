#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

const int MX = 100001;

int N, M, R;
vector<int> adj[MX];
int visited[MX];

void input(){
	cin >> N >> M >> R;
	for(int i=0; i<M; i++){
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for(int i=0; i<=N; i++){
		sort(adj[i].begin(), adj[i].end());
	}
}

void solution(){
	queue<int> q;
	q.push(R);
	int cnt = 1;
	visited[R] = cnt++;

	while(!q.empty()){
		int now = q.front(); q.pop();

		for(const int &nxt : adj[now]){
			if(visited[nxt] != 0) continue;

			q.push(nxt);
			visited[nxt] = cnt++;
		}
	}
}

void get_result(){
	for(int i=1; i<=N; i++){
		cout << visited[i] << '\n';
	}
}

int main() {
	input();

	solution();

	get_result();

	return 0;
}