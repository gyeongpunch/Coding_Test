#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MX = 101;

int N;
int graph[MX];
int visited[MX];
vector<int> path;
vector<int> result;

void input(){
	cin >> N;
	for(int i=1; i<=N; i++){
		cin >> graph[i];
	}
}

void dfs(int now){
	visited[now] = 1;
	path.push_back(now);
	int nxt = graph[now];

	if(visited[nxt] == 0){
		dfs(nxt);
	}
	else if(visited[nxt] == 1){
		bool flag = false;
		for(const int &n : path){
			if(n == nxt) {
				flag = true;
			}
			if(flag){
				result.push_back(n);
			}
		}
	}

	visited[now] = 2;
	path.pop_back();
}

void solution(){
	for(int i=1; i<=N; i++){
		if(visited[i]==0){
			dfs(i);
		}
	}

	sort(result.begin(), result.end());
}

void get_result(){
	cout << result.size() << '\n';
	for(const int &n : result){
		cout << n << '\n';
	}
}

int main() {
	input();

	solution();

	get_result();

	return 0;
}