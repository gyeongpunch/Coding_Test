#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(nullptr);

struct Event{
    int x, h;
};

int N;
vector<Event> v;
unordered_map<int, int> Map;

bool cmp(Event a, Event b){
    if(a.x == b.x) return a.h > b.h;
    return a.x < b.x;
}

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    cin >> N;
    int s, h, e;
    for(int i=0; i<N; i++){
        cin >> s >> h >> e;
        v.push_back({s, h});
        v.push_back({e, -h});
    }

    sort(v.begin(), v.end(), cmp);

    priority_queue<int> pq;
    int prev = -1;
    pq.push(0);

    for(const Event &e : v){
        if(e.h > 0) pq.push(e.h);
        else Map[-e.h]++;

        while(!pq.empty() && Map[pq.top()] > 0){
            Map[pq.top()]--;
            pq.pop();
        }
        int cur = pq.top();
        if(cur != prev){
            cout << e.x << ' ' << cur << ' ';
            prev = cur;
        }
    }

    return 0;
}