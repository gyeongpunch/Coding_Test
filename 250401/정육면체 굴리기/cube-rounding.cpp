#include <iostream>
using namespace std;

#define MAX_N 20

struct Dice{
    int x, y;
    int state[6];
};

int N, M, K;
Dice dice;
int arr[MAX_N][MAX_N];

void gogo(int dir){
    if(dir == 1){
        if(dice.y == M-1) return;
        dice.y++;
        
        int tmp = dice.state[0];
        dice.state[0] = dice.state[4];
        dice.state[4] = dice.state[5];
        dice.state[5] = dice.state[2];
        dice.state[2] = tmp;

    }
    else if (dir == 2){
        if(dice.y == 0) return;
        dice.y--;

        int tmp = dice.state[0];
        dice.state[0] = dice.state[2];
        dice.state[2] = dice.state[5];
        dice.state[5] = dice.state[4];
        dice.state[4] = tmp;
    }
    else if (dir == 3){
        if(dice.x == 0) return;
        dice.x--;

        int tmp = dice.state[0];
        dice.state[0] = dice.state[1];
        dice.state[1] = dice.state[5];
        dice.state[5] = dice.state[3];
        dice.state[3] = tmp;
    }
    else if (dir == 4){
        if(dice.x == N-1) return;
        dice.x++;

        int tmp = dice.state[0];
        dice.state[0] = dice.state[3];
        dice.state[3] = dice.state[5];
        dice.state[5] = dice.state[1];
        dice.state[1] = tmp;
    }

    if(arr[dice.x][dice.y] == 0){
        arr[dice.x][dice.y] = dice.state[5];
    }
    else{
        dice.state[5] = arr[dice.x][dice.y];
        arr[dice.x][dice.y] = 0;
    }

    cout << dice.state[0] << '\n';
}

int main() {
    cin >> N >> M >> dice.x >> dice.y >> K;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> arr[i][j];
        }
    }

    int k;
    for(int i=0; i<K; i++){
        cin >> k;
        gogo(k);
    }

    return 0;
}