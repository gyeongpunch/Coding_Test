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

const int MX = 2001;
const int MXC = 100;

int N, M, T, S, G, H;
vector<Edge> adj[MX];
int dist[3][MX];
int cand[MXC];
vector<int> result;
int W;

void init(){
	for(int i=1; i<MX; i++){
		adj[i].clear();
	}
	for(int i=0; i<3; i++){
		fill(dist[i], dist[i]+MX, INT_MAX);
	}
	result.clear();
}

void input(){
	cin >> N >> M >> T;
	cin >> S >> G >> H;
	for(int i=0; i<M; i++){
		int a, b, d;
		cin >> a >> b >> d;
		if((a==G && b==H) || (a==H && b==G)) W = d;
		adj[a].push_back({b, d});
		adj[b].push_back({a, d});
	}
	for(int i=0; i<T; i++){
		cin >> cand[i];
	}
}

void dijkstra(int start, int idx){
	priority_queue<Edge, vector<Edge>, CMP> pq;
	pq.push({start, 0});
	dist[idx][start] = 0;

	while(!pq.empty()){
		Edge now = pq.top(); pq.pop();

		if(dist[idx][now.x] < now.c) continue;

		for(const Edge &n : adj[now.x]){
			Edge nxt = {n.x, now.c + n.c};

			if(dist[idx][n.x] <= nxt.c) continue;

			pq.push(nxt);
			dist[idx][nxt.x] = nxt.c;
		}
	}
}

void find_cand(){
	for(int i=0; i<T; i++){
		int path1 = dist[0][G] + W + dist[2][cand[i]];
		int path2 = dist[0][H] + W + dist[1][cand[i]];

		int shortest = dist[0][cand[i]];

		if(path1==shortest || path2==shortest){
			result.push_back(cand[i]);
		}
	}
}

void solution(){
	dijkstra(S, 0);
	dijkstra(G, 1);
	dijkstra(H, 2);

	find_cand();
}

void get_result(){
	sort(result.begin(), result.end());

	for(const int &n : result){
		cout << n << ' ';
	}
	cout << '\n';
}

int main() {
	int TC;
	cin >> TC;
	for(int i=0; i<TC; i++){
		init();

		input();

		solution();

		get_result();
	}

	return 0;
}