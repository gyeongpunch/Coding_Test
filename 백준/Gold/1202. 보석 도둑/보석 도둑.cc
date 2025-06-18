#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <queue>
#include <cstring>

using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(nullptr);

typedef long long ll;

struct Info{
    int w, p;
};

const int MX = 300000;

int N, K;
Info arr[MX];
int bag[MX]; 
ll result = 0;

bool custom_compare(Info a, Info b){
    return a.w < b.w;
}

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    cin >> N >> K;
    for(int i=0; i<N; i++){
        cin >> arr[i].w >> arr[i].p;
    }
    for(int i=0; i<K; i++){
        cin >> bag[i];
    }

    sort(arr, arr+N, custom_compare);
    sort(bag, bag+K);

    priority_queue<int> pq;
    int j=0;

    for(int i=0; i<K; i++){
        while(j<N && arr[j].w <= bag[i]){
            pq.push(arr[j].p);
            j++;
        }

        if(!pq.empty()){
            result += pq.top(); pq.pop();
        }
    }

    cout << result << '\n';

    return 0;
}