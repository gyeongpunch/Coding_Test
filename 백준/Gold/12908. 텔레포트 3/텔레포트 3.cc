#include <iostream>
#include <unordered_map>
#include <vector>
#include <climits>
using namespace std;
typedef long long ll;

struct Point{
	int x, y;
};

Point Start, End;
Point tele[3][2];
vector<Point> path;
int visited[4];
ll result = LLONG_MAX;
ll nowTime;
Point now;


void calc(){
	nowTime = 0;
	now = Start;
	
	for(Point n : path){
		if(n.x == 3) continue;
		Point beforeTele = tele[n.x][n.y];
		Point afterTele = tele[n.x][1-n.y];

		nowTime += abs(now.x - beforeTele.x) + abs(now.y - beforeTele.y) + 10;
		now = afterTele;
	}
	nowTime += abs(now.x - End.x) + abs(now.y - End.y);

	result = min(result, nowTime);
}

void dfs(int depth, int N){
	if(depth == N){
		
		calc();
		return;
	}

	for(int i=0; i<4; i++){
		if(i!=3 && visited[i] == 1) continue;

		if(i==3){
			path.push_back({i, 0});
			dfs(depth + 1, N);
			path.pop_back();
		}
		else{
			path.push_back({i, 0});
			visited[i] = 1;
			dfs(depth + 1, N);
			path.pop_back();
			visited[i] = 0;

			path.push_back({i, 1});
			visited[i] = 1;
			dfs(depth + 1, N);
			path.pop_back();
			visited[i] = 0;
		}
	}
}

int main() {
	cin >> Start.x >> Start.y >> End.x >> End.y;
	for(int i=0; i<3; i++){
		cin >> tele[i][0].x >> tele[i][0].y >> tele[i][1].x >> tele[i][1].y;
	}

	dfs(0, 3);
	
	cout << result << '\n';

	return 0;
}

/*
0 - 1 - 2 - 3 - 12 - 13 - 21 - 23 - 31 - 32 - 123
*/