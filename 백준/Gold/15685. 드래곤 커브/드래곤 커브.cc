#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <cstring>

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(nullptr);

using namespace std;

#define SZ 110

int N;
int arr[SZ][SZ];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int x, y;
vector<int> dirs;

void simulation(int d, int g){
    arr[y][x] = 1;
    y += dy[d];
    x += dx[d];
    arr[y][x] = 1;
    dirs.push_back(d);
    for(int i=0; i<g; i++){
        int length = dirs.size();
        for(int i=length - 1; i>-1; i--){
            d = (dirs[i] + 1) % 4;
            y += dy[d];
            x += dx[d];
            arr[y][x] = 1;
            dirs.push_back(d);
        }
    }
}

void pprint(){
    cout << "===========================\n";
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << "===========================\n";
}

int calc(){
    int cnt = 0;
    for(int i=0; i<SZ-1; i++){
        for(int j=0; j<SZ-1; j++){
            if(arr[i][j]==1 && arr[i+1][j]==1 && arr[i][j+1]==1 && arr[i+1][j+1]==1) cnt++;
        }
    }
    return cnt;
}

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    cin >> N;

    int d, g;
    for(int i=0; i<N; i++){
        cin >> x >> y >> d >> g;
        dirs.clear();
        simulation(d, g);
        // pprint();
    }
    cout << calc() << '\n';

    return 0;
}