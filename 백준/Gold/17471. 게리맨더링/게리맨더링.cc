#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

const int MX = 11;

int N;
int people[MX];
vector<int> adj[MX];

bool isConnected(int mask, bool isA) {
    int start = -1;
    for (int i = 0; i < N; i++) {
        bool inThis = isA ? (mask & (1 << i)) : !(mask & (1 << i));
        if (inThis) {
			start = i+1;
			break;
		}
    }
    if (start == -1) return false;

    queue<int> q;
    int visited[MX] = {0};
    q.push(start);
    visited[start] = 1;
    int cnt = 1;

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int nxt : adj[cur]) {
            if (visited[nxt]) continue;
            bool inThis = isA ? (mask & (1 << (nxt-1))) : !(mask & (1 << (nxt-1)));
            if (!inThis) continue;
            visited[nxt] = 1;
            q.push(nxt);
            cnt++;
        }
    }

    int totalCnt = 0;
    for (int i = 0; i < N; i++) {
        bool inThis = isA ? (mask & (1 << i)) : !(mask & (1 << i));
        if (inThis) totalCnt++;
    }
    return cnt == totalCnt;
}

int main() {
    cin >> N;
    int total = 0;
    for (int i = 1; i <= N; i++) {
        cin >> people[i];
        total += people[i];
    }
    for (int i = 1; i <= N; i++) {
        int cnt;
		cin >> cnt;
        for (int j = 0; j < cnt; j++) {
            int x;
			cin >> x;
            adj[i].push_back(x);
        }
    }

    int answer = INT_MAX;

    for (int mask = 1; mask < (1 << N) - 1; mask++) {
        if (!isConnected(mask, true)) continue;
        if (!isConnected(mask, false)) continue;

        int sumA = 0;
        for (int i = 0; i < N; i++) {
            if (mask & (1 << i)) sumA += people[i+1];
        }
        int sumB = total - sumA;
        answer = min(answer, abs(sumA - sumB));
    }

    if (answer == INT_MAX) cout << -1 << '\n';
    else cout << answer << '\n';

    return 0;
}