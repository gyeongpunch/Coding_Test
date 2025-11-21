#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <climits>
#include <algorithm>
using namespace std;

struct Point{
	int x, y;
};

struct Info{
	int d, x, y;
};

struct Edge{
	int a, b, d;
};

const int MX = 10;
const int MXI = 7;

int N, M;
int arr[MX][MX];
int visited[MX][MX];
int parents[MXI];
vector<Info> beaches;
vector<Edge> edges;
int result;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int island_num = 0;

bool bound_check(int x, int y){
	return 0<=x && x<N && 0<=y && y<M;
}

void input(){
	cin >> N >> M;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cin >> arr[i][j];
		}
	}
}

void uf_init(){
	for(int i=1; i<=MXI; i++){
		parents[i] = i;
	}
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

void bfs(int n, int x, int y){
	queue<Point> q;
	q.push({x, y});
	visited[x][y] = 1;

	while(!q.empty()){
		Point now = q.front(); q.pop();

		arr[now.x][now.y] = n;

		for(int i=0; i<4; i++){
			int nx = now.x + dx[i];
			int ny = now.y + dy[i];

			if(!bound_check(nx, ny)) continue;
			if(arr[nx][ny]==0){
				beaches.push_back({i, now.x, now.y});
				continue;
			}			
			if(visited[nx][ny] == 1) continue;

			q.push({nx, ny});
			visited[nx][ny] = 1;
		}
	}

}

void find_beach(){
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(arr[i][j] == 0) continue;
			if(visited[i][j] != 0) continue;

			bfs(++island_num, i, j);
		}
	}
}

void gogo_bridge(){
	for(const Info &now : beaches){
		int l = 1;
		while(true){
			int nx = now.x + dx[now.d] * l;
			int ny = now.y + dy[now.d] * l;

			if(!bound_check(nx, ny)) break;
			if(arr[nx][ny] == arr[now.x][now.y]) break;
			if(arr[nx][ny] != 0){
				if(l > 2){
					edges.push_back({arr[now.x][now.y], arr[nx][ny], l-1});
				}
				break;
			}
			l++;
		}
	}
}

bool CMP(const Edge &a, const Edge &b){
	return a.d < b.d;
}

void get_mst(){
	sort(edges.begin(), edges.end(), CMP);

	for(const Edge &now : edges){
		if(root(now.a) != root(now.b)){
			Union(now.a, now.b);
			result += now.d;
		}
	}

	int now = root(parents[1]);
	for(int i=1; i<=island_num; i++){
		if(root(parents[i]) != now){
			result = -1;
			return;
		}
	}
}

void solution(){
	uf_init();

	find_beach();

	gogo_bridge();

	get_mst();
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