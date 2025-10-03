#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

struct Edge{
	int s, e, c;
};

const int MX = 501;

int N, M, W;
vector<Edge> edges;
int dist[MX];

void init(){
	edges.clear();
	memset(dist, 0, sizeof(dist));
}

void input(){
	cin >> N >> M >> W;
	int s, e, t;
	for(int i=0; i<M; i++){
		cin >> s >> e >> t;
		edges.push_back({s, e, t});
		edges.push_back({e, s, t});
	}
	for(int i=0; i<W; i++){
		cin >> s >> e >> t;
		edges.push_back({s, e, -t});
	}
}

void solution(){
	for(int i=1; i<N; i++){
		for(const Edge &e : edges){
			if (dist[e.e] > dist[e.s] + e.c) {
                dist[e.e] = dist[e.s] + e.c;
            }
		}
	}
	bool flag = false;
	for(const Edge &e : edges){
		if (dist[e.e] > dist[e.s] + e.c){
            flag = true;
            break;
        }
	}

	if(flag) cout << "YES\n";
	else cout << "NO\n";
}

int main() {
	int T;
	cin >> T;

	for(int t=0; t<T; t++){
		init();

		input();

		solution();
	}
	return 0;
}