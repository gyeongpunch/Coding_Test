#include <iostream>
#include <cstring>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

const int N = 4;
const int M = 8;

char table[N][M];
int visited[N];

void pprint(){
    cout << "============\n";
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cout << table[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << "============\n";
}

void rotate(int n, int dir){
    visited[n] = 1;

    if(n != 0 && visited[n-1] == 0 && table[n-1][2] != table[n][6]){
        rotate(n-1, dir*(-1));
    }
    if(n != M-1 && visited[n+1] == 0 && table[n][2] != table[n+1][6]){
        rotate(n+1, dir*(-1));
    }
    
    if(dir == 1){
        char tmp = table[n][M-1];
        for(int i=M-1; i>0; i--){
            table[n][i] = table[n][i-1];
        }
        table[n][0] = tmp;
    }
    else{
        char tmp = table[n][0];
        for(int i=0; i<M-1; i++){
            table[n][i] = table[n][i+1];
        }
        table[n][M-1] = tmp;
    }
}

int main() {
    fastio;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> table[i][j];
        }
    }

    int K;
    cin >> K;
    int n, d;
    for(int i=0; i<K; i++){
        cin >> n >> d;
        memset(visited, 0, sizeof(visited));
        rotate(n-1, d);
        // pprint();
    }

    int s = 1;
    int result = 0;
    for(int i=0; i<N; i++){
        if(table[i][0] == '1'){
            result += s;
        }
        s *= 2;
    }

    cout << result << '\n';

    return 0;
}