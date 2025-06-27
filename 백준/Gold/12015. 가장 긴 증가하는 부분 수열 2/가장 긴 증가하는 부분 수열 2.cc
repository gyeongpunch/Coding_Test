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

const int MX = 1000000;

int N;
int arr[MX];

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }

    vector<int> v;

    for(int i=0; i<N; i++){
        auto it = lower_bound(v.begin(), v.end(), arr[i]);
        if(it==v.end()) v.push_back(arr[i]);
        else *it = arr[i];
    }

    cout << v.size() << '\n';

    return 0;
}