#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int bfs(int now, int N, const vector<int>& arr, vector<int>& visited){
    vector<int> check;
    queue<int> q;
    q.push(now);

    while(!q.empty()){
        int x = q.front();
        q.pop();

        if(visited[x]==1){
            for(int i=0; i<check.size(); i++){
                if(check[i] == x){
                    return check.size() - i;
                }
            }
            return 0;
        }
        visited[x] = 1;
        q.push(arr[x]-1);
        check.push_back(x);
    }
    return 0;
}

int main(void){
    // freopen("input.txt", "r", stdin);

    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        vector<int> arr(N, 0);
        vector<int> visited(N, 0);
        for(int i=0; i<N; i++){
            cin >> arr[i];
        }
        
        int result = N;

        for(int i=0; i<N; i++){
            if(visited[i]==0){
                result -= bfs(i, N, arr, visited);
            }
        }

        cout << result << endl;

    }


    return 0;
}