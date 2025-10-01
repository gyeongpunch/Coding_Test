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

const int MX = 1001;

int N, M, X;
vector<Edge> adj[MX];
int dist[MX][MX];

void input(){
	cin >> N >> M >> X;
	
	int a, b, c;
	for(int i=0; i<M; i++){
		cin >> a >> b >> c;
		adj[a].push_back({b, c});
	}
}

void dijkstra(int start){
	priority_queue<Edge, vector<Edge>, CMP> pq;
	pq.push({start, 0});
	dist[start][start] = 0;

	while(!pq.empty()){
		Edge now = pq.top(); pq.pop();

		if(dist[start][now.x] > now.c) continue;

		for(const Edge &n : adj[now.x]){
			Edge nxt = {n.x, now.c + n.c};

			if(dist[start][nxt.x] <= nxt.c) continue;

			pq.push(nxt);
			dist[start][nxt.x] = nxt.c;
		}
	}
}

void solution(){
	for(int i=1; i<=N; i++){
		fill(dist[i]+1, dist[i]+N+1, INT_MAX);
	}

	for(int start=1; start<=N; start++){
		dijkstra(start);
	}
}

void get_result(){
	// for(int i=1; i<=N; i++){
	// 	for(int j=1; j<=N; j++){
	// 		cout << dist[i][j] << ' ';
	// 	}
	// 	cout << '\n';
	// }

	int result = INT_MIN;

	for(int i=1; i<=N; i++){
		int now = dist[i][X] + dist[X][i];

		result = max(result, now);
	}

	cout << result << '\n';
}

int main() {
	input();
	
	solution();

	get_result();

	return 0;
}