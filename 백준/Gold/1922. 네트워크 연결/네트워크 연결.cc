#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge{
	int a, b, c;
};

const int MX = 1001;

int N, M;
vector<Edge> edges;
int parents[MX];
int result;

void init(){
	for(int i=0; i<MX; i++){
		parents[i] = i;
	}
}

void input(){
	cin >> N >> M;
	for(int i=0; i<M; i++){
		int a, b, c;
		cin >> a >> b >> c;
		edges.push_back({a, b, c});
	}
}

bool CMP(const Edge &a, const Edge &b){
	return a.c < b.c;
}

int root(int a){
	if(a == parents[a]) return a;
	return parents[a] = root(parents[a]);
}

void Union(int a, int b){
	int rootA = root(a);
	int rootB = root(b);

	if(rootA != rootB){
		parents[rootB] = rootA;
	}
}

void solution(){
	sort(edges.begin(), edges.end(), CMP);

	int cnt = 0;
	for(int i=0; i<M; i++){
		Edge now = edges[i];

		if(root(now.a) == root(now.b)) continue;

		Union(now.a, now.b);
		result += now.c;
	}

}

void get_result(){
	cout << result << '\n';
}

int main() {
	init();

	input();

	solution();

	get_result();

	return 0;
}