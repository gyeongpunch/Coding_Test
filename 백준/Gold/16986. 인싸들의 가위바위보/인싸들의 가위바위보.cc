#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MX = 10;

int N, K;
int winMap[MX][MX];
int friends[3][20];
bool visited[MX];
int win[3];
int game_count[3];
bool resultFlag = false;

void dfs(int a, int b) {
    if (resultFlag) return;

    if (win[0] == K) {
        resultFlag = true;
        return;
    }
    if (win[1] == K || win[2] == K) {
        return;
    }
    if (game_count[0] >= N) {
        return;
    }

    int other_player = 3 - a - b;

    if (a == 0) {
        int jiwoo = 0;
        int friend_p = b;

        for (int jiwoo_move = 1; jiwoo_move <= N; ++jiwoo_move) {
            if (visited[jiwoo_move]) continue;

            int friend_move = friends[friend_p][game_count[friend_p]];

            visited[jiwoo_move] = true;
            game_count[jiwoo]++;
            game_count[friend_p]++;

            if (winMap[jiwoo_move][friend_move] == 2) {
                win[jiwoo]++;
                dfs(jiwoo, other_player);
                win[jiwoo]--;
            }
			else {
                win[friend_p]++;
                dfs(min(friend_p, other_player), max(friend_p, other_player));
                win[friend_p]--;
            }
            
            game_count[jiwoo]--;
            game_count[friend_p]--;
            visited[jiwoo_move] = false;
        }
    }
	else {
        int move1 = friends[a][game_count[a]];
        int move2 = friends[b][game_count[b]];

        game_count[a]++;
        game_count[b]++;
        
        int result = winMap[move1][move2];
        int winner = -1;

        if (result == 2) winner = a;
        else winner = b;

        win[winner]++;
        dfs(0, winner);
        win[winner]--;

        game_count[a]--;
        game_count[b]--;
    }
}

int main() {
    cin >> N >> K;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> winMap[i][j];
        }
    }
    for (int i = 0; i < 20; ++i) cin >> friends[1][i];
    for (int i = 0; i < 20; ++i) cin >> friends[2][i];
    
    dfs(0, 1);

    cout << (resultFlag ? 1 : 0) << '\n';

    return 0;
}