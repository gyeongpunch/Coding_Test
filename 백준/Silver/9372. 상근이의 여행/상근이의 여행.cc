#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

const int MX = 1005;

int N, M;
vector<int> adj[MX];
int visited[MX];
int result;

void init(){
	for(int i=0; i<MX; i++){
		adj[i].clear();
	}
	memset(visited, 0, sizeof(visited));
	result = 0;
}

void input(){
	cin >> N >> M;
	int a, b;
	for(int i=0; i<M; i++){
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
}

void gogo(int s){

}

void solution(){
	queue<int> q;
	q.push(1);
	visited[1] = 1;

	while(!q.empty()){
		int now = q.front(); q.pop();

		for(const int &nxt : adj[now]){
			if(visited[nxt] == 1) continue;

			q.push(nxt);
			visited[nxt] = 1;
			result++;
		}
	}
	cout << result << '\n';
}

int main() {
	int T;
	cin >> T;
	for(int i=0; i<T; i++){
		init();

		input();

		solution();
	}

	return 0;
}