#include <iostream>

using namespace std;

int N;
int grid[20][20];

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    int result = 0;
    for(int i=0; i<N-3+1; i++){
        for(int j=0; j<N-3+1; j++){
            int sm = 0;
            for(int x=i; x<i+3; x++){
                for(int y=j; y<j+3; y++){
                    sm += grid[x][y];
                }
            }
            result = result < sm ? sm : result;
        }
    }

    cout << result << '\n';

    return 0;
}
