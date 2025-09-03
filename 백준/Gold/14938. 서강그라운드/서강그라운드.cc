#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

struct Edge{
	int x, c;
};

struct CMP{
	bool operator()(const Edge a, const Edge b) const{
		return a.c > b.c;
	}
};

const int MX = 101;

int N, M, R;
vector<Edge> adj[MX];
int items[MX];
int dist[MX];
int result;

void solution(int start){
	priority_queue<Edge, vector<Edge>, CMP> pq;
	fill(dist+1, dist+N+1, INT_MAX);
	pq.push({start, 0});
	dist[start] = 0;

	while(!pq.empty()){
		Edge now = pq.top(); pq.pop();

		if(now.c > dist[now.x]) continue;

		for(const Edge &e : adj[now.x]){
			if(dist[e.x] <= now.c + e.c) continue;
			if(now.c + e.c > M) continue;
			
			dist[e.x] = now.c + e.c;
			pq.push({e.x, dist[e.x]});
		}
	}
	int cnt = 0;
	for(int i=1; i<=N; i++){
		if(dist[i] <= M){
			cnt += items[i];
		}
	}
	result = max(result, cnt);
}

int main() {
	cin >> N >> M >> R;
	for(int i=1; i<=N; i++){
		cin >> items[i];
	}
	int a, b, l;
	for(int i=0; i<R; i++){
		cin >> a >> b >> l;
		adj[a].push_back({b, l});
		adj[b].push_back({a, l});
	}
	for(int i=1; i<=N; i++){
		solution(i);
	}
	
	cout << result << '\n';

	return 0;
}