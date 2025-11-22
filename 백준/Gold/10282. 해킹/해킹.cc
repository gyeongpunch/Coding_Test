#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <climits>
#include <algorithm>
using namespace std;

struct Edge{
	int x, c;
};

struct CMP{
	bool operator()(const Edge &a, const Edge &b){
		return a.c > b.c;
	}
};

struct Result{
	int cnt, time;
};

const int MX = 10001;

int N, D, C;
vector<Edge> adj[MX];
int dist[MX];
Result result;

void init(){
	for(int i=0; i<MX; i++){
		adj[i].clear();
	}
	fill(dist, dist+MX, INT_MAX);
	result = {0, 0};
}

void input(){
	cin >> N >> D >> C;
	for(int i=0; i<D; i++){
		int a, b, s;
		cin >> a >> b >> s;
		adj[b].push_back({a, s});
	}
}

void solution(){
	priority_queue<Edge, vector<Edge>, CMP> pq;
	pq.push({C, 0});
	dist[C] = 0;

	while(!pq.empty()){
		Edge now = pq.top(); pq.pop();

		if(dist[now.x] < now.c) continue;

		result.cnt++;
        result.time = max(result.time, now.c);

		for(const Edge &n : adj[now.x]){
			Edge nxt = {n.x, now.c + n.c};
			if(dist[nxt.x] <= nxt.c) continue;

			pq.push(nxt);
			dist[nxt.x] = nxt.c;
		}
	}
}

void get_result(){
	// for(int i=1; i<=N; i++){
	// 	if(dist[i] == INT_MAX) continue;

	// 	result.cnt++;
	// 	result.time = max(result.time, dist[i]);
	// }
	cout << result.cnt << ' ' << result.time << '\n';
}

int main() {
	int T;
	cin >> T;
	for(int i=0; i<T; i++){
		init();

		input();

		solution();

		get_result();
	}
	return 0;
}