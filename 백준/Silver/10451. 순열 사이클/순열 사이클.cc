#include <iostream>
#include <cstring>
using namespace std;

const int MX = 1001;

int N;
int arr[MX];
int visited[MX];
int result;

void init(){
	result = 0;
	memset(visited, 0, sizeof(visited));
}

void input(){
	cin >> N;
	for(int i=1; i<=N; i++){
		cin >> arr[i];
	}
}

void dfs(int now){
	// cout << now << "\n\n";

	if(visited[now] == 1) return;

	visited[now] = 1;

	if(visited[arr[now]] == 1){
		result++;
		return;
	}
	dfs(arr[now]);
}

void solution(){
	for(int i=1; i<=N; i++){
		dfs(i);
	}
}

void get_result(){
	cout << result << '\n';
}

int main() {
	int T;
	cin >> T;
	for(int t=0; t<T; t++){
		init();

		input();

		solution();

		get_result();
	}
	return 0;
}