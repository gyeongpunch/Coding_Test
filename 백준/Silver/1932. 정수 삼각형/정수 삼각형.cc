#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    // freopen("input.txt", "r", stdin);

    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    int arr[N][N];
    for(int i=0; i<N; i++){
        for(int j=0; j<=i; j++){
            cin >> arr[i][j];
        }
    }

    for(int i=N-2; i>-1; i--){
        for(int j=0; j<=i; j++){
            arr[i][j] = arr[i][j] + max(arr[i+1][j], arr[i+1][j+1]);
        }
    }

    cout << arr[0][0] << '\n';

    return 0;
}