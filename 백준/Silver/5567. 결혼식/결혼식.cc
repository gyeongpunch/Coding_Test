#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Info{
	int x, depth;
};

const int MX = 501;

int N, M;
vector<int> adj[MX];
int visited[MX];
int result;

void input(){
	cin >> N >> M;
	for(int i=0; i<M; i++){
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
}

void solution(){
	queue<Info> q;
	q.push({1, 0});
	visited[1] = 1;

	while(!q.empty()){
		Info now = q.front(); q.pop();

		if(now.depth == 2) continue;

		for(const int &nxt : adj[now.x]){
			if(visited[nxt] == 1) continue;
			
			q.push({nxt, now.depth + 1});
			visited[nxt] = 1;
			result++;
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

/*
친구
친구의 친구
N 명
학번: 1-N
상근이의 학번은 1

*/