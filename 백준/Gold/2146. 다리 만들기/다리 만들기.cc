#include <cstdio>
#include <deque>
#include <iostream>

using namespace std;

#define MAX_N 100
#define INF 1000000001

struct arr_data {
	int x, y, dist;
};

int N, arr[MAX_N][MAX_N];
int V, visited[MAX_N][MAX_N];
int G, grps[MAX_N][MAX_N];
int ans = INF;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
deque<arr_data> dq;

bool check(int x, int y){
    return 0<=x && x<N && 0<=y && y<N;
}

void bfs(const int& X, const int& Y) {
	int nx, ny;

	dq.clear();
	grps[X][Y] = ++G;
	visited[X][Y] = ++V;
	dq.push_back({X, Y, 0});
	
    while(!dq.empty()){
		auto[x, y, dist] = dq.front();
        dq.pop_front();

		if(arr[x][y]){
			for(int i=0; i<4; i++){
				int nx = x + dx[i], ny = y + dy[i];
				if(check(nx, ny) and visited[nx][ny]!=V){
                    if (arr[nx][ny]){
                        grps[nx][ny] = G;
                        visited[nx][ny] = V;
                        dq.push_front({nx, ny, 0});
                    }
                    else {
                        visited[nx][ny] = V;
                        dq.push_back({nx, ny, 1});
                    }
                }
			}
		}
		else{
			for(int i=0; i<4; i++){
				int nx = x + dx[i], ny = y + dy[i];
                if(check(nx, ny) && visited[nx][ny]!=V){
                    if (arr[nx][ny]){
                        if (dist < ans){
                            ans = dist;
                        }
                        return;
                    }
                    else {
                        visited[nx][ny] = V;
                        dq.push_back({ nx, ny, dist + 1 });
                    }
                }
			}
		}
	}
}

int main() {
    cin >> N;
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++){
            cin >> arr[i][j];
        }
	}

	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			if (arr[i][j] && !grps[i][j]){
                bfs(i, j);
            }
		}
	}

	cout << ans << endl;

    return 0;
}
