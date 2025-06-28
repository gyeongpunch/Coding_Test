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

const int MX=8100;
int N;
char result[MX][MX];

void print_star(int sx, int sy, int ex, int ey){
    if(ex-sx==1 && ey-sy==1){
        result[sx][sy] = '*';
        return;
    }

    int mx = (ex-sx)/3;
    int my = (ey-sy)/3;

    print_star(sx, sy, sx+mx, sy+my);
    print_star(sx, sy+my, sx+mx, sy+my*2);
    print_star(sx, sy+my*2, sx+mx, ey);

    print_star(sx+mx, sy, sx+mx*2, sy+my);
    print_star(sx+mx, sy+my*2, sx+mx*2, ey);
    
    print_star(sx+mx*2, sy, ex, sy+my);
    print_star(sx+mx*2, sy+my, ex, sy+my*2);
    print_star(sx+mx*2, sy+my*2, ex, ey);
}


int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    cin >> N;

    print_star(0, 0, N, N);

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(result[i][j]) cout << result[i][j];
            else cout << ' ';
        }
        cout << '\n';
    }

    return 0;
}