#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

struct Point{
	int x, y;
};

const int MX = 101;

int N;
int visited[MX];
vector<Point> beer;
Point s, e;


void init(){
	beer.clear();
	memset(visited, 0, sizeof(visited));
}

void input(){
	cin >> N;
	cin >> s.x >> s.y;
	for(int i=0; i<N; i++){
		int x, y;
		cin >> x >> y;
		beer.push_back({x, y});
	}
	cin >> e.x >> e.y;
}

void solution(){
	queue<Point> q;
	q.push(s);

	while(!q.empty()){
		Point now = q.front(); q.pop();

		if(abs(e.x-now.x) + abs(e.y-now.y) <= 1000){
			cout << "happy\n";
			return;
		}

		for(int i=0; i<N; i++){
			if(visited[i] == 1) continue;

			if(abs(now.x - beer[i].x) + abs(now.y - beer[i].y) <= 1000){
				q.push(beer[i]);
				visited[i] = 1;
			}
		}
	}
	cout << "sad\n";
}

int main() {
	int T;
	cin >> T;
	for(int i=0; i<T; i++){
		init();

		input();

		solution();
	}
	return 0;
}