#include <iostream>
#include <vector>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define MAX_N 20
#define MAX_M 30

struct Player {
	int x, y, d, s, myGun;
};

void input();
bool bound_check(int x, int y);
void print_point();
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int N, M, K;
vector<int> arrGun[MAX_N][MAX_N];
Player players[MAX_M];
int playerPoint[MAX_M];

void move_player(int idx) {
	int nx, ny;
	nx = players[idx].x + dx[players[idx].d];
	ny = players[idx].y + dy[players[idx].d];

	if (!bound_check(nx, ny)) {
		players[idx].d = (players[idx].d + 2) % 4;

		players[idx].x += dx[players[idx].d];
		players[idx].y += dy[players[idx].d];
	}
	else {
		players[idx].x = nx;
		players[idx].y = ny;
	}
}

void new_picking(int idx, int x, int y) {
	int maxGun = 0;
	int maxGunIdx = -1;

	if (arrGun[x][y].empty()) return;

	for (int i = 0; i < arrGun[x][y].size(); i++) {
		if (maxGun < arrGun[x][y][i]) {
			maxGun = arrGun[x][y][i];
			maxGunIdx = i;
		}
	}

	if (players[idx].myGun < maxGun) {
		if (players[idx].myGun == 0) {
			players[idx].myGun = maxGun;
			vector<int> tmp;
			for (int i = 0; i < arrGun[x][y].size(); i++) {
				if (i == maxGunIdx) continue;
				tmp.push_back(arrGun[x][y][i]);
			}
			arrGun[x][y] = tmp;
		}
		else {
			int tmp = players[idx].myGun;
			players[idx].myGun = maxGun;
			arrGun[x][y][maxGunIdx] = tmp;
		}
	}

}

bool player_compare(int myPower, int me, int yourPower, int you) {
	if (myPower == yourPower) return players[me].s > players[you].s;
	return myPower > yourPower;
}

bool is_other_player(int x, int y) {
	for (int i = 0; i < M; i++) {
		if (x == players[i].x && y == players[i].y) return true;
	}
	return false;
}

void lose_player_move(int idx, int x, int y) {
	if (players[idx].myGun != 0) {
		arrGun[x][y].push_back(players[idx].myGun);
		players[idx].myGun = 0;
	}
	
	int nx, ny;

	for(int i=0; i<4; i++) {
		nx = players[idx].x + dx[(players[idx].d + i) % 4];
		ny = players[idx].y + dy[(players[idx].d + i) % 4];

		if (!bound_check(nx, ny)) continue;
		if (is_other_player(nx, ny)) continue;

		players[idx].x = nx;
		players[idx].y = ny;
		players[idx].d = (players[idx].d + i) % 4;
		break;
	}

	new_picking(idx, players[idx].x, players[idx].y);
}

void fight_player(int idx) {
	bool isFight = false;
	int curX = players[idx].x, curY = players[idx].y;
	int winnerIdx;

	for (int i = 0; i < M; i++) {
		if (i == idx) continue;

		if (players[i].x == players[idx].x && players[i].y == players[idx].y) {
			isFight = true;

			int myPower = players[idx].s + players[idx].myGun;
			int yourPower = players[i].s + players[i].myGun;

			// 내가 이김
			if (player_compare(myPower, idx, yourPower, i)) {
				playerPoint[idx] += myPower - yourPower;
				winnerIdx = idx;
				lose_player_move(i, curX, curY);
			}
			// 쟤가 이김
			else {
				playerPoint[i] += yourPower - myPower;
				winnerIdx = i;
				lose_player_move(idx, curX,  curY);
			}

			break;
		}
	}

	if (isFight) {
		new_picking(winnerIdx, curX, curY);
	}
	else {
		new_picking(idx, curX, curY);
	}
}

void simulation() {

	for (int i = 0; i < M; i++) {
		move_player(i);

		fight_player(i);

	}
}

int main(void) {
	fastio;

	input();

	for (int i = 0; i < K; i++) {
		simulation();
	}

	print_point();
	
	return 0;
}

void print_point() {
	for (int i = 0; i < M; i++) {
		cout << playerPoint[i] << ' ';
	}
	cout << '\n';
}

void input() {
	cin >> N >> M >> K;

	int g;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> g;
			if (g != 0) {
				arrGun[i][j].push_back(g);
			}
		}
	}

	int x, y, d, s;
	for (int i = 0; i < M; i++) {
		cin >> x >> y >> d >> s;
		players[i] = { x - 1, y - 1, d, s, 0 };
	}
}

bool bound_check(int x, int y) {
	return 0 <= x && x < N && 0 <= y && y < N;
}