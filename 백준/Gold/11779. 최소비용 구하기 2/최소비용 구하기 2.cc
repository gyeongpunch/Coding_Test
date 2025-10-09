#include <iostream>
#include <queue>
#include <vector>
#include <string>
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

int N, M;
vector<Edge> adj[MX];
vector<Edge> rev[MX];
int visited[MX];
int s, e;

void init(){
	fill(visited, visited+MX, INT_MAX);
}

void input(){
	cin >> N >> M;
	int a, b, c;
	for(int i=0; i<M; i++){
		cin >> a >> b >> c;
		adj[a].push_back({b, c});
		rev[b].push_back({a, c});
	}
	cin >> s >> e;
}

void solution(){
	priority_queue<Edge, vector<Edge>, CMP> pq;
	pq.push({s, 0});
	visited[s] = 0;

	while(!pq.empty()){
		Edge now = pq.top(); pq.pop();

		if(now.c > visited[now.x]) continue;

		for(const Edge &n : adj[now.x]){
			Edge nxt = {n.x, visited[now.x] + n.c};

			if(nxt.c >= visited[nxt.x]) continue;

			pq.push(nxt);
			visited[nxt.x] = nxt.c;
		}
	}
}

void get_result(){
	vector<int> path;

	int now = e;
	while(true){
		path.push_back(now);

		if(now == s) break;

		for(const Edge &nxt : rev[now]){
			if(visited[now] == visited[nxt.x] + nxt.c){
				now = nxt.x;
				break;
			}
		}
	}

	int sz = path.size();
	cout << visited[e] << '\n' << sz << '\n';
	
	for(int i=sz-1; i>-1; i--){
		cout << path[i] << ' ';
	}
	cout << '\n';

	// for(int i=1; i<=N; i++){
	// 	cout << visited[i].path << '\n';
	// }
}

int main() {
	init();

	input();

	solution();

	get_result();

	return 0;
}

/*
n개의 도시
m개의 버스
A도시에서 B도시로 가는 데 버스 비용 최소화

최소비용과 경로 출력

*/