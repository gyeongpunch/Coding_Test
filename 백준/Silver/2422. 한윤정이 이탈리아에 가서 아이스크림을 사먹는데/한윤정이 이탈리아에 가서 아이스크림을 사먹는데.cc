#include <iostream>
#include <unordered_set>
using namespace std;

const int MX = 10000;

int N, M;
unordered_set<int> adj[MX];

int main() {
	cin >> N >> M;

	int a, b;
	for(int i=0; i<M; i++){
		cin >> a >> b;
		a--;
		b--;
		adj[a].insert(b);
		adj[b].insert(a);
	}

	int result = 0;
	for(int i=0; i<N-2; i++){
		for(int j=i+1; j<N-1; j++){
			if(adj[i].find(j) != adj[i].end()) continue;
			for(int k=j+1; k<N; k++){
				if(adj[i].find(k) != adj[i].end()) continue;
				if(adj[j].find(k) != adj[j].end()) continue;

				result++;
			}
		}
	}

	cout << result << '\n';

	return 0;
}

/*
N개 아이스크림
어떤 종류의 아이스크림을 함께먹으면 맛이 없다.
아이스크림 3가지를 선택하자
M은 섞어먹으면 안 되는 조합의 개수

1 [2, 3]
2 [1]
3 [1, 4]
4 [3]
5

1 4 5
2 3 5
2 4 5
*/