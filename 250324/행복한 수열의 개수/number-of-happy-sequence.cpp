#include <iostream>

using namespace std;

int n, m;
int grid[100][100];

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int result = 0;
    for(int i=0; i<n; i++){
        int maxL1 = 1, maxL2 = 1;
        int l1 = 1, l2 = 1;
        for(int j=1; j<n; j++){
            if(grid[i][j-1] == grid[i][j]){
                l1++;
            }
            else{
                l1 = 1;
            }

            if(grid[j-1][i] == grid[j][i]){
                l2++;
            }
            else{
                l2=1;
            }

            maxL1 = maxL1 < l1 ? l1 : maxL1;
            maxL2 = maxL2 < l2 ? l2 : maxL2;
        }

        if(maxL1 >= m) result++;
        if(maxL2 >= m) result++;
    }

    cout << result << '\n';

    return 0;
}
