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

const int MX=50;

int N, M;
int A[MX][MX], B[MX][MX];

void flip(int x, int y){
    for(int i=x; i<x+3; i++){
        for(int j=y; j<y+3; j++){
            A[i][j] = 1-A[i][j];
        }
    }
}

int get_result(){
    int cnt = 0;

    for(int i=0; i<N-2; i++){
        for(int j=0; j<M-2; j++){
            if(A[i][j] != B[i][j]){
                flip(i, j);
                cnt++;
            }
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(A[i][j] != B[i][j]) return -1;
        }
    }
    return cnt;
}

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    cin >> N >> M;
    string s;
    for(int i=0; i<N; i++){
        cin >> s;
        for(int j=0; j<M; j++){
            A[i][j] = s[j] - '0';
        }
    }
    for(int i=0; i<N; i++){
        cin >> s;
        for(int j=0; j<M; j++){
            B[i][j] = s[j] - '0';
        }
    }

    int result = get_result();

    cout << result << '\n';

    return 0;
}