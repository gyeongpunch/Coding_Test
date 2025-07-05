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

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);


    int N;
    cin >> N;
    priority_queue<int, vector<int>, greater<int>> pq;
    while(N--){
        int x;
        cin >> x;
        if(x == 0){
            if(!pq.empty()){
                cout << pq.top() << '\n'; pq.pop();
            }
            else{
                cout << 0 << '\n';
            }
        }
        else{
            pq.push(x);
        }
    }

    return 0;
}