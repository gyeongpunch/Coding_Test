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

struct Info{
    string name;
    int k, e, m;
};

const int MX = 100000;

int N;
Info arr[MX];

bool cmp(Info a, Info b){
    if(a.k == b.k && a.e == b.e && a.m == b.m) return a.name < b.name;
    if(a.k == b.k && a.e == b.e) return a.m > b.m;
    if(a.k == b.k) return a.e < b.e;
    return a.k > b.k;
}

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    cin >> N;
    string n;
    int k, e, m;
    for(int i=0; i<N; i++){
        cin >> n >> k >> e >> m;
        arr[i] = {n, k, e, m};
    }

    sort(arr, arr+N, cmp);

    for(int i=0; i<N; i++){
        cout << arr[i].name << '\n';
    }
    return 0;
}