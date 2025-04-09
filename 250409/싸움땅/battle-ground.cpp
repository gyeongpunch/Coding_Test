#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

typedef struct Player {
	int x;
	int y;
	int dir;
	int status;
	int gun;
	int points;
} Player;

int n, m, k;
vector<int> board[21][21];  // save guns
int playerBoard[21][21];  // check where the players are at

Player players[31];  // keep track of players

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };


bool compare(int a, int b) {
	return a > b;
}

int getOppositeDirection(int d) {
	if (d == 0) return 2;
	else if (d == 1) return 3;
	else if (d == 2) return 0;
	else return 1;
}

int rotate90(int d) {
	if (d == 0) return 1;
	else if (d == 1) return 2;
	else if (d == 2) return 3;
	else return 0;
}

void pickupGun(int i, int x, int y) {
	if (!board[x][y].empty()) {
		sort(board[x][y].begin(), board[x][y].end(), compare);
		int strongestGun = board[x][y][0];
		// cout << "Strongest Gun in " << x << ", " << y << " : " << strongestGun << endl;

		if (players[i].gun == 0) {
			players[i].gun = strongestGun;
			board[x][y].erase(board[x][y].begin());
		}
		else {
			if (players[i].gun < strongestGun) {  // pick up stronger gun
				int playerGun = players[i].gun;  // the gun player was holding
				players[i].gun = strongestGun;
				board[x][y].erase(board[x][y].begin());
				board[x][y].push_back(playerGun);
			}
		}
	}
}


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int gun;
			cin >> gun;
			if (gun > 0) board[i][j].push_back(gun);  // there can be more than one gun in a single space
		}
	}
	memset(playerBoard, 0, sizeof(playerBoard));

	for (int i = 1; i <= m; i++) {
		int x, y, d, s;
		cin >> x >> y >> d >> s;
		Player player;
		player.x = x;
		player.y = y;
		player.dir = d;
		player.status = s;
		player.gun = 0;
		player.points = 0;
		players[i] = player;
		playerBoard[x][y] = i;
	}

	for (int round = 1; round <= k; round++) {
		// move player sequentially
		for (int i = 1; i <= m; i++) {
			Player player = players[i];
			int x = player.x;
			int y = player.y;
			int d = player.dir;

			int nx = x + dx[d];
			int ny = y + dy[d];

			if (nx <= 0 || nx > n || ny <= 0 || ny > n) {  // out of bounds
				d = getOppositeDirection(d);  // go one space in the opposite direction
				players[i].dir = d;  // update direction
				nx = x + dx[d];
				ny = y + dy[d];
			}

			if (playerBoard[nx][ny] > 0) {  // there is a player
				// battle
				int enemyNum = playerBoard[nx][ny];
				Player enemyPlayer = players[enemyNum];
				int enemyStatus = enemyPlayer.status;
				int enemyGun = enemyPlayer.gun;

				// cout << i << " vs " << enemyNum << endl;
				// cout << "player #" << i << " stat = " << players[i].status << " Gun: " << players[i].gun << endl;
				// cout << "player #" << enemyNum << " stat = " << players[enemyNum].status << " Gun: " << players[enemyNum].gun << endl;

				int winner = -1;
				if (enemyStatus + enemyGun > player.status + player.gun) winner = 1;  // enemy wins
				else if (enemyStatus + enemyGun < player.status + player.gun) winner = 0;  // player wins
				else {
					// cout << "tied" << endl;
					if (players[enemyNum].status > players[i].status) winner = 1;
					else winner = 0;
				}

				if (winner == 1) {  // enemy wins
					// cout << enemyNum << " wins!!" << endl;
					players[enemyNum].points += (enemyStatus + enemyGun - player.status - player.gun);
					// loser puts down the gun
					int loserGun = player.gun;
					players[i].gun = 0;
					// move to different empty space
					int loserNx;
					int loserNy;
					while (true) {
						loserNx = nx + dx[d];
						loserNy = ny + dy[d];
						if (loserNx <= 0 || loserNx > n || loserNy <= 0 || loserNy > n) {
							d = rotate90(d);
							continue;
						}  // out of bounds
						if (playerBoard[loserNx][loserNy]) {
							d = rotate90(d);
							continue;
						} // there is somebody there

						playerBoard[x][y] = 0;
						playerBoard[loserNx][loserNy] = i;
						players[i].x = loserNx;
						players[i].y = loserNy;
						players[i].dir = d;

						pickupGun(i, loserNx, loserNy);
						break;

					}
					// enemy chooses next gun to pick up
					if (loserGun > enemyGun) {  // the gun that loser dropped must be stronger to pick it up
						if (loserGun != 0) {
							board[nx][ny].push_back(loserGun);
							players[enemyNum].gun = loserGun;
						}
					}
					else {
						if (loserGun != 0) {
							board[nx][ny].push_back(loserGun);  // just put it down
						}
					}

				}
				else if (winner == 0) {  // player wins
				 // cout << i << " wins!!" << endl;
					playerBoard[x][y] = 0;  // move player to nx ny
					players[i].x = nx;
					players[i].y = ny;

					players[i].points += (player.status + player.gun - enemyStatus - enemyGun);  // gain points
					// enemy drops gun
					if (enemyGun != 0) {
						board[nx][ny].push_back(enemyGun);
						players[enemyNum].gun = 0;
					}

					// enemy moves
					int loserNx;
					int loserNy;
					int enemyDir = players[enemyNum].dir;
					while (true) {
						loserNx = nx + dx[enemyDir];
						loserNy = ny + dy[enemyDir];
						if (loserNx <= 0 || loserNx > n || loserNy <= 0 || loserNy > n) {  // out of bounds
							enemyDir = rotate90(enemyDir);
							continue;
						}
						if (playerBoard[loserNx][loserNy]) {  // there is somebody there
							enemyDir = rotate90(enemyDir);
							continue;
						}

						playerBoard[nx][ny] = i;  // player moves into this space
						playerBoard[loserNx][loserNy] = enemyNum;
						players[enemyNum].x = loserNx;
						players[enemyNum].y = loserNy;
						players[enemyNum].dir = enemyDir;

						pickupGun(enemyNum, loserNx, loserNy);
						break;
					}
					pickupGun(i, nx, ny);
				}
			}
			else {  // there is no player there
			 // update players
				players[i].x = nx;
				players[i].y = ny;
				// update board
				playerBoard[x][y] = 0;
				playerBoard[nx][ny] = i;

				pickupGun(i, nx, ny);
			}
			// player picks up the gun
			// pickupGun(i, nx, ny);
		}
	}

	for (int i = 1; i <= m; i++) {
		cout << players[i].points << " ";
	}
	cout << endl;
	return 0;
}
