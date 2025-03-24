#include <iostream>
#include <vector>

using namespace std;

int n, m;
int grid[200][200];

struct Point{
    int x, y;
};

vector<vector<vector<Point>>> Block = {
    {{{0, 0}, {1, 0}, {1, 1}},
    {{0, 1}, {1, 0}, {1, 1}},
    {{0, 0}, {0, 1}, {1, 1}},
    {{0, 0}, {1, 0}, {0, 1}}},

    {{{0, 0}, {0, 1}, {0, 2}}},

    {{{0, 0}, {1, 0}, {2, 0}}}
};

int get_max_block(int x, int y, int idx){
    int mx = 0;
    for(const vector<Point> &blocks : Block[idx]){
        int sm = 0;
        for(const Point &p : blocks){
            sm += grid[x + p.x][y + p.y];
        }
        mx = mx < sm ? sm : mx;
    }
    return mx;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int result = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(i+1 < n && j+1 < m){
                int a = get_max_block(i, j, 0);
                result = result < a ? a : result;
            }
            if(j+2 < m){
                int a = get_max_block(i, j, 1);
                result = result < a ? a : result;
            }
            if(i+2 < n){
                int a = get_max_block(i, j, 2);
                result = result < a ? a : result;
            }
        }
    }
    
    cout << result << '\n';

    return 0;
}
