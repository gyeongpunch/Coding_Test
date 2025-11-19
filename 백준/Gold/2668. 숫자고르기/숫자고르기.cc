#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MX = 101;

int N;
int graph[MX];
int visited[MX];
int is_cycle[MX];
vector<int> tmp;
vector<int> result;

void input() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> graph[i];
    }
}

void dfs(int now) {
    visited[now] = 1;
    tmp.push_back(now);

    int nxt = graph[now];

    if (visited[nxt] == 0) {
        dfs(nxt);
    }
	else if (visited[nxt] == 1) {
        bool on_cycle = false;
        for (int x : tmp) {
            if (x == nxt) on_cycle = true;
            if (on_cycle) {
                is_cycle[x] = 1;
            }
        }
    }

    visited[now] = 2;
    tmp.pop_back();
}

void solution() {
    for (int i = 1; i <= N; i++) {
        if (visited[i] == 0) {
            dfs(i);
        }
    }

    for (int i = 1; i <= N; i++) {
        if (is_cycle[i]) result.push_back(i);
    }

    sort(result.begin(), result.end());
}

void get_result() {
    cout << result.size() << '\n';
    for (int x : result) {
        cout << x << '\n';
    }
}

int main() {
    input();

    solution();
    
	get_result();
    
	return 0;
}
