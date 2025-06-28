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

const int MX = 3000;

int N;
int arr[MX][MX];
unordered_map<int, int> Map;

bool is_avail(int sx, int sy, int ex, int ey){
    int now = arr[sx][sy];
    for(int x=sx; x<ex; x++){
        for(int y=sy; y<ey; y++){
            if(now != arr[x][y]) return false;
        }
    }
    return true;
}

void devide_conquer(int sx, int sy, int ex, int ey){
    if(is_avail(sx, sy, ex, ey)) {
        Map[arr[sx][sy]]++;
    }
    else{
        int mx = (ex-sx)/3;
        int my = (ey-sy)/3;

        devide_conquer(sx, sy, sx+mx, sy+my);
        devide_conquer(sx, sy+my, sx+mx, sy+2*my);
        devide_conquer(sx, sy+2*my, sx+mx, ey);

        devide_conquer(sx+mx, sy, sx+2*mx, sy+my);
        devide_conquer(sx+mx, sy+my, sx+2*mx, sy+2*my);
        devide_conquer(sx+mx, sy+2*my, sx+2*mx, ey);
        
        devide_conquer(sx+2*mx, sy, ex, sy+my);
        devide_conquer(sx+2*mx, sy+my, ex, sy+2*my);
        devide_conquer(sx+2*mx, sy+2*my, ex, ey);
    }

}

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> arr[i][j];
        }
    }

    devide_conquer(0, 0, N, N);

    cout << Map[-1] << '\n';
    cout << Map[0] << '\n';
    cout << Map[1] << '\n';

    return 0;
}