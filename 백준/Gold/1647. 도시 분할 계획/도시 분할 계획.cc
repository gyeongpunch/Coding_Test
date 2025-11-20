#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge{
	int x, y, c;
};

const int MX = 100001;

int N, M;
vector<Edge> v;
int parents[MX];
int result;
int cnt;

void input(){
	cin >> N >> M;
	for(int i=0; i<M; i++){
		int x, y, c;
		cin >> x >> y >> c;
		v.push_back({x, y, c});
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
	sort(v.begin(), v.end(), CMP);
	cnt = N;
	for(int i=0; i<=N; i++){
		parents[i] = i;
	}

	for(int i=0; i<M; i++){
		if(cnt == 2) return;
		Edge now = v[i];

		if(root(now.x) != root(now.y)){
			Union(now.x, now.y);
			cnt--;
			result += now.c;
		}
	}
}

void get_result(){
	cout << result << '\n';
}

int main() {
	input();

	solution();

	get_result();

	return 0;
}