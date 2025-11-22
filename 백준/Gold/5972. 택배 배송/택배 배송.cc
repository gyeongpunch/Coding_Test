#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

struct Edge{
	int x, c;
};

struct CMP{
	bool operator()(const Edge &a, const Edge &b){
		return a.c > b.c;
	}
};

const int MX = 50001;

int N, M;
vector<Edge> adj[MX];
int dist[MX];

void input(){
	cin >> N >> M;
	for(int i=0; i<M; i++){
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}
}

void solution(){
	fill(dist, dist+MX, INT_MAX);
	priority_queue<Edge, vector<Edge>, CMP> pq;
	pq.push({1, 0});
	dist[1] = 0;

	while(!pq.empty()){
		Edge now = pq.top(); pq.pop();

		if(dist[now.x] < now.c) continue;

		for(const Edge &n : adj[now.x]){
			Edge nxt = {n.x, n.c + now.c};

			if(dist[nxt.x] <= nxt.c) continue;

			pq.push(nxt);
			dist[nxt.x] = nxt.c;
		}
	}
}

void get_result(){
	cout << dist[N] << '\n';
}

int main() {
	input();

	solution();

	get_result();

	return 0;
}