#include <iostream>
#include <vector>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define N 4

struct Point {
	int x, y;
};

void input();
void calc_result();
void copy_monster();
bool bound_check(int x, int y);
void move_monster();
void make_packman_moveList(int depth);
void move_packman(int nowTime);

int M, T;
vector<int> arrMonster[N][N];
vector<int> arrMonsterTmp[N][N];
int visited[N][N];
int deathTimer[N][N];
vector<int> arrEgg[N][N];
Point PackMan;
int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };
int result = 0;
int ddx[4] = { -1, 0, 1, 0 };
int ddy[4] = { 0, -1, 0, 1 };
vector<vector<int>> total_moveList;
vector<int> path;

void remove_death_monster(int nowTime) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (deathTimer[i][j] == 0) continue;

			if (nowTime - deathTimer[i][j] > 2) {
				deathTimer[i][j] = 0;
			}
		}
	}
}

void merge_monster() {
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			if (!arrMonsterTmp[x][y].empty()) {
				for (const int &d : arrMonsterTmp[x][y]) {
					arrMonster[x][y].push_back(d);
				}
				arrMonsterTmp[x][y].clear();
			}
			if (!arrEgg[x][y].empty()) {
				for (const int &d : arrEgg[x][y]) {
					arrMonster[x][y].push_back(d);
				}
				arrEgg[x][y].clear();
			}
		}
	}
}

void simulation(int nowTime) {
	copy_monster();

	move_monster();

	move_packman(nowTime);

	remove_death_monster(nowTime);

	merge_monster();
}

int main(void) {
	fastio;

	input();

	make_packman_moveList(0);

	for (int i = 1; i <= T; i++) {
		simulation(i);
	}

	calc_result();

	cout << result << '\n';

	return 0;
}

void move_packman(int nowTime) {
	int maxCnt = -1;
	int maxIdx = -1;

	int nx, ny;
	for (int i = 0; i < total_moveList.size(); i++) {
		int x = PackMan.x;
		int y = PackMan.y;
		int nowCnt = 0;
		memset(visited, 0, sizeof(visited));

		for (const int &dir : total_moveList[i]) {
			nx = x + ddx[dir];
			ny = y + ddy[dir];

			if (!bound_check(nx, ny)) continue;
			if (visited[nx][ny] != 0) continue;
			x = nx;
			y = ny;
			visited[x][y] = 1;
			if (!arrMonsterTmp[x][y].empty()) nowCnt += arrMonsterTmp[x][y].size();
		}

		if (nowCnt > maxCnt) {
			maxCnt = nowCnt;
			maxIdx = i;
		}
	}

	for (const int &dir : total_moveList[maxIdx]) {
		nx = PackMan.x + ddx[dir];
		ny = PackMan.y + ddy[dir];

		if (!bound_check(nx, ny)) continue;

		PackMan.x = nx;
		PackMan.y = ny;

		if (arrMonsterTmp[PackMan.x][PackMan.y].empty()) continue;

		arrMonsterTmp[PackMan.x][PackMan.y].clear();
		deathTimer[PackMan.x][PackMan.y] = nowTime;
	}
}

void make_packman_moveList(int depth) {
	if (depth == 3) {
		total_moveList.push_back(path);
		return;
	}

	for (int i = 0; i < 4; i++) {
		path.push_back(i);

		make_packman_moveList(depth + 1);

		path.pop_back();
	}
}

void move_monster() {
	int nx, ny;

	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			if (arrMonster[x][y].empty()) continue;

			for (int dir : arrMonster[x][y]) {
				bool flag = true;

				for (int i = 0; i < 8; i++) {
					nx = x + dx[(dir + i) % 8];
					ny = y + dy[(dir + i) % 8];

					if (!bound_check(nx, ny)) continue;
					if (deathTimer[nx][ny] != 0) continue;
					if (nx == PackMan.x && ny == PackMan.y) continue;

					arrMonsterTmp[nx][ny].push_back((dir + i) % 8);
					flag = false;
					break;
				}

				if (flag) {
					arrMonsterTmp[x][y].push_back(dir);
				}
			}
			arrMonster[x][y].clear();
		}
	}
}

void copy_monster() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arrMonster[i][j].empty()) continue;

			for (const int &dir : arrMonster[i][j]) {
				arrEgg[i][j].push_back(dir);
			}
		}
	}
}

void input() {
	cin >> M >> T;
	int x, y, dir;
	cin >> x >> y;
	PackMan = { x - 1, y - 1 };
	for (int i = 0; i < M; i++) {
		cin >> x >> y >> dir;

		arrMonster[x - 1][y - 1].push_back(dir - 1);
	}
}

void calc_result() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arrMonster[i][j].empty()) continue;

			result += arrMonster[i][j].size();
		}
	}
}

bool bound_check(int x, int y) {
	return 0 <= x && x < N && 0 <= y && y < N;
}