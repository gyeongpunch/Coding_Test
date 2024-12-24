#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int N, M, K;
vector<vector<vector<int>>> arr;
vector<vector<vector<int>>> visited;

queue<tuple<int, int, int>> q;

int dk[6] = {1, -1, 0, 0, 0, 0};
int dn[6] = {0, 0, 1, -1, 0, 0};
int dm[6] = {0, 0, 0, 0, 1, -1};

int bfs(int& cnt){
    while(!q.empty()){
        auto[ck, cn, cm] = q.front();
        q.pop();

        for(int i=0; i<6; i++){
            int nk = ck + dk[i];
            int nn = cn + dn[i];
            int nm = cm + dm[i];
            if(0<=nk && nk<K && 0<=nn && nn<N && 0<=nm && nm<M && arr[nk][nn][nm]==0 && visited[nk][nn][nm]==-1){
                q.push({nk, nn, nm});
                visited[nk][nn][nm] = visited[ck][cn][cm] + 1;
                cnt--;
                if(cnt==0){
                    return visited[nk][nn][nm];
                }
            }
        }
    }
    if(cnt==0){
        return 0;
    }
    return -1;
}

int main(void){
    cin >> M >> N >> K;
    arr = vector<vector<vector<int>>>(K, vector<vector<int>> (N, vector<int>(M, 0)));
    visited = vector<vector<vector<int>>>(K, vector<vector<int>>(N, vector<int>(M, -1)));

    int cnt = 0;
    for(int i=0; i<K; i++){
        for(int j=0; j<N; j++){
            for(int k=0; k<M; k++){
                cin >> arr[i][j][k];
                if(arr[i][j][k] == 1){
                    q.push({i, j, k});
                    visited[i][j][k] = 0;
                }
                if(arr[i][j][k]==0) cnt++;
            }
        }
    }

    // for(int i=0; i<K; i++){
    //     for(int j=0; j<N; j++){
    //         for(int k=0; k<M; k++){
    //             cout << arr[i][j][k] << ' ';
    //         }
    //         cout << endl;
    //     }
    //     cout << endl;
    // }

    int result = bfs(cnt);

    cout << result << endl;

    return 0;
}