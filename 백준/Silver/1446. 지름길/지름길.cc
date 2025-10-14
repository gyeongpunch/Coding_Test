#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

struct Info{
	int x, c;
};

struct CMP{
	bool operator()(const Info &a, const Info &b){
		return a.c < b.c;
	}
};

const int MX = 10001;

int N, D;
vector<Info> adj[MX];
int dist[MX];

void init(){
	fill(dist, dist+MX, INT_MAX);
	for(int i=0; i<MX-1; i++){
		adj[i].push_back({i+1, 1});
	}
}

void input(){
	cin >> N >> D;
	int a, b, c;
	for(int i=0; i<N; i++){
		cin >> a >> b >> c;
		adj[a].push_back({b, c});
	}
}

void solution(){
	priority_queue<Info, vector<Info>, CMP> pq;
	pq.push({0, 0});
	dist[0] = 0;

	while(!pq.empty()){
		Info now = pq.top(); pq.pop();

		if(dist[now.x] < now.c) continue;

		for(const Info &n : adj[now.x]){
			Info nxt = {n.x, n.c + now.c};
			if(dist[nxt.x] <= nxt.c) continue;

			pq.push(nxt);
			dist[nxt.x] = nxt.c;
		}
	}
	cout << dist[D] << '\n';
}

int main() {
	init();

	input();

	solution();

	return 0;
}