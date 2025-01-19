#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int main(void){
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;

    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for (int i = 0; i < n; i++) {
        long long card;
        cin >> card;
        pq.push(card);
    }

    for (int i = 0; i < m; i++) {
        long long first = pq.top(); pq.pop();
        long long second = pq.top(); pq.pop();

        long long newCard = first + second;

        pq.push(newCard);
        pq.push(newCard);
    }

    long long result = 0;
    while (!pq.empty()) {
        result += pq.top();
        pq.pop();
    }

    cout << result << endl;
    return 0;
}