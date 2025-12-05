#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MX = 100001;

int N, M, R;
vector<int> adj[MX];
int visited[MX];
int depth;

void input(){
	cin >> N >> M >> R;
	for(int i=0; i<M; i++){
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
}

void dfs(int now){
	visited[now] = ++depth;

	for(const int &nxt : adj[now]){
		if(visited[nxt] != 0) continue;
		dfs(nxt);
	}
}

void get_result(){
	for(int i=1; i<=N; i++){
		cout << visited[i] << '\n';
	}
}

void sort_vertex(){
	for(int i=0; i<=N; i++){
		sort(adj[i].begin(), adj[i].end());
	}
}

void solution(){
	sort_vertex();
	
	dfs(R);
}

int main() {
	input();

	solution();

	get_result();

	return 0;
}