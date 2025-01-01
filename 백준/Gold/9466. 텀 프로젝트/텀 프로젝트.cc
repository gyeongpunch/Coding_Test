#include <iostream>
#include <vector>

using namespace std;

int T, N;
vector<int> arr;
vector<int> visited, finished;
int cnt;

void dfs(int now) {
    visited[now] = 1;
    int next = arr[now];

    if(!visited[next]) {
        dfs(next);
    }
    else if(!finished[next]) {
        for(int i=next; i!=now; i=arr[i]) {
            cnt++;
        }
        cnt++;
    }

    finished[now] = 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while (T--) {
        cin >> N;

        arr = vector<int>(N + 1);
        visited = vector<int>(N + 1, 0);
        finished = vector<int>(N + 1, 0);
        cnt = 0;

        for (int i=1; i<=N; i++) {
            cin >> arr[i];
        }

        for (int i= 1; i<=N; i++) {
            if (!visited[i]) {
                dfs(i);
            }
        }

        cout << N - cnt << '\n';
    }

    return 0;
}
