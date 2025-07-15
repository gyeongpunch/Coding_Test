#include <iostream>
#include <queue>
#include <cstring>
#include <climits>
#include <unordered_map>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

struct Point{
    int dx, dy;
};

const int MX = 105;

int C, P;
int height[MX];

vector<vector<vector<Point>>> blocks = {
    {},
    // ㅡ, ㅣ
    {{{0, 0}, {0, 1}, {0, 2}, {0, 3}}, {{0, 0}, {1, 0}, {2, 0}, {3, 0}}},

    // ㅁ
    {{{0, 0}, {0, 1}, {1, 0}, {1, 1}}},
    
    
    {{{0, 1}, {1, 0}, {0, 2}, {1, 1}}, {{0, 0}, {1, 0}, {1, 1}, {2, 1}}},
    
    {{{0, 0}, {0, 1}, {1, 1}, {1, 2}}, {{0, 1}, {1, 0}, {1, 1}, {2, 0}}},
    
    // ㅗ, ㅏ, ㅜ, ㅓ
    {{{1, 0}, {0, 1}, {1, 1}, {1, 2}}, {{0, 0}, {1, 0}, {1, 1}, {2, 0}}, {{0, 0}, {0, 1}, {1, 1}, {0, 2}}, {{0, 1}, {1, 0}, {1, 1}, {2, 1}}},
    
    {{{1, 0}, {1, 1}, {1, 2}, {0, 2}}, {{0, 0}, {0, 1}, {1, 1}, {2, 1}}, {{0, 0}, {0, 1}, {1, 0}, {0, 2}}, {{0, 0}, {1, 0}, {2, 0}, {2, 1}}},
    
    {{{0, 0}, {1, 0}, {1, 1}, {1, 2}}, {{0, 1}, {1, 1}, {2, 1}, {2, 0}}, {{0, 0}, {0, 1}, {0, 2}, {1, 2}}, {{0, 0}, {0, 1}, {1, 0}, {2, 0}}}
};

int main(void) {
    fastio;

    cin >> C >> P;
    for (int i = 0; i < C; i++) cin >> height[i];
    
    int res = 0;
    for (const auto &shape : blocks[P]) {
        int dxy[4];
        memset(dxy, -1, sizeof(dxy));

        int n=0;
        for(const Point &p : shape){
            if(dxy[p.dy] == -1) n++;
            dxy[p.dy] = max(dxy[p.dy], p.dx);
        }
        
        if(n == 1){
            res += C;
            continue;
        }
        // cout << n << '\n';
        for(int i=0; i<C-n+1; i++){
            bool flag = true;

            // cout << i << '\n';
            for(int j=0; j<n-1; j++){

                // cout << height[i+j+1] - height[i+j] << ' ';

                if(height[i+j+1] - height[i+j] != dxy[j] - dxy[j+1]){
                    flag = false;
                }
            }
            // cout << "\n\n";

            if(flag){
                // for(int i=0; i<n; i++){
                //     cout << dxy[i] << ' ';
                // }
                // cout << '\n';
                // cout << n << ' ' << i << "\n\n\n";

                res++;
            }
        }

    }

    cout << res << '\n';


    
    
    return 0; 
}
