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

struct Event{
    int x, h;
};

bool cmp(Event a, Event b){
    if(a.x==b.x) return a.h > b.h;
    return a.x < b.x;
}

const int MX = 100001;

int N;
vector<Event> v;
unordered_map<int, int> dontCare;

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
    pq.push(0);

    int prev = -1;
    for(const Event e : v){
        if(e.h > 0) pq.push(e.h);
        else dontCare[-e.h]++;

        while(!pq.empty() && dontCare[pq.top()]){
            dontCare[pq.top()]--;
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