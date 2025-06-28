#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <cstring>

using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(nullptr);

const int MX = 8000;

int N;
int result[MX][MX];

void draw(int x, int y, int n){
    if (n == 3) {
        result[x][y+2] = 1;
        result[x+1][y+1] = result[x+1][y+3] = 1;
        for (int i=0; i<5; ++i) result[x+2][y+i] = 1;
        return;
    }

    int m = n/2;
    draw(x, y+m, m);
    draw(x+m, y, m);
    draw(x+m, y+m*2, m);

}

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    cin >> N;

    draw(0, 0, N);

    for(int i=0; i<N; i++){
        for(int j=0; j<N*2-1; j++){
            if(result[i][j]) cout << '*';
            else cout << ' ';
        }
        cout << '\n';
    }

    return 0;
}