#include <iostream>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define MAX_N 100

int N, K;
int arr[2][MAX_N];
int visited[MAX_N];
int result = 0;
int kCnt = 0;

void rotate(){
    int tmp = arr[1][0];
    for(int i=0; i<N-1; i++){
        arr[1][i] = arr[1][i+1];
    }
    arr[1][N-1] = arr[0][N-1];

    for(int i=N-1; i>0; i--){
        arr[0][i] = arr[0][i-1];
    }
    arr[0][0] = tmp;

    for(int i=N-1; i>0; i--){
        visited[i] = visited[i-1];
    }
    visited[0] = 0;
    if(visited[N-1] == 1){
        visited[N-1] = 0;
    }


}

void people_move(){
    for(int i=N-2; i>-1; i--){
        if(visited[i] != 1) continue;

        if(visited[i+1] == 0 && arr[0][i+1] > 0){
            visited[i] = 0;
            arr[0][i+1]--;
            if(arr[0][i+1] == 0){
                kCnt++;
            }
            if(i+1 != N-1){
                visited[i+1] = 1;
            }
        }
    }
}

void pprint(){
    cout << "===============\n";
    for(int i=0; i<2; i++){
        for(int j=0; j<N; j++){
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << "===============\n";
}

int main() {
    fastio;

    cin >> N >> K;
    for(int i=0; i<2; i++){
        for(int j=0; j<N; j++){
            cin >> arr[i][j];
        }
    }

    while(true){
        result++;

        rotate();
        // pprint();

        people_move();
        // pprint();

        if(arr[0][0] > 0 && visited[0] != 1){
            visited[0] = 1;
            arr[0][0]--;
            if(arr[0][0] == 0){
                kCnt++;
            }
        }
        // pprint();
        if(kCnt >= K){
            break;
        }

    }

    cout << result << '\n';

    return 0;
}