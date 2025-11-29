#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <climits>
using namespace std;

struct Result{
	int score, cnt;
	vector<int> cand;
};

const int MX = 51;

int N;
vector<int> adj[MX];
int visited[MX];
int score[MX];
Result result;

void input(){
	cin >> N;
	while(true){
		int a, b;
		cin >> a >> b;
		if(a==-1 && b==-1) break;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	result.score = INT_MAX;
}

void bfs(int num){
	memset(visited, -1, sizeof(visited));
	queue<int> q;
	q.push(num);
	visited[num] = 0;

	while(!q.empty()){
		int now = q.front(); q.pop();

		for(const int &nxt : adj[now]){
			if(visited[nxt] != -1) continue;

			q.push(nxt);
			visited[nxt] = visited[now] + 1;
			score[num] = max(score[num],visited[now] + 1);
		}
	}

	if(score[num] < result.score){
		result.score = score[num];
		result.cnt = 1;
		result.cand.clear();
		result.cand.push_back(num);
	}
	else if(score[num] == result.score){
		result.cnt++;
		result.cand.push_back(num);
	}
}

void solution(){
	for(int i=1; i<=N; i++){
		bfs(i);
	}
}

void get_result(){
	cout << result.score << ' ' << result.cnt << '\n';
	for(const int &n : result.cand){
		cout << n << ' ';
	}
	cout << '\n';
}

int main() {
	input();

	solution();

	get_result();

	return 0;
}