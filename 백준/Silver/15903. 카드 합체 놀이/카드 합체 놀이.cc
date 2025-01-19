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
    for(int i=0; i<n; i++){
        long long a;
        cin >> a;
        pq.push(a);
    }

    while(m--){
        long long a=pq.top();
        pq.pop();
        long long b=pq.top();
        pq.pop();

        long long c = a + b;

        pq.push(c);
        pq.push(c);
    }
    long long result = 0;
    while(!pq.empty()){
        result += pq.top();
        pq.pop();
    }

    cout << result << '\n';

    return 0;
}