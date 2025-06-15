#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <cstring>

using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(nullptr);
typedef long long ll;

struct Edge{
    int n;
    ll c;

    bool operator<(Edge other) const{
        return c > other.c;
    }
};

const int Ve = 10001;

int V, E;
vector<Edge> arr[Ve];
int visited[Ve];
ll result = 0;

void get_result(){
    priority_queue<Edge> pq;
    visited[1] = 1;
    for(Edge n : arr[1]){
        pq.push({n.n, n.c});
    }

    while(!pq.empty()){
        Edge now = pq.top(); pq.pop();
        if(visited[now.n] == 1) continue;
        visited[now.n] = 1;
        result += now.c;

        for(Edge nx : arr[now.n]){
            if(visited[nx.n] == 1) continue;

            pq.push({nx.n, nx.c});
        }
    }
}

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    cin >> V >> E;
    int a, b;
    ll c;

    for(int i=0; i<E; i++){
        cin >> a >> b >> c;
        arr[a].push_back({b, c});
        arr[b].push_back({a, c});
    }

    get_result();

    cout << result << '\n';

    return 0;
}