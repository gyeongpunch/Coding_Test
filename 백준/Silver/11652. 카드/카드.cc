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
#include <climits>

using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(nullptr);
typedef long long ll;

const int MX = 100000;

int N;
unordered_map<ll, int> Map;
int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    cin >> N;
    int largest = -1;
    ll lNum = LLONG_MAX;
    ll n;
    for(int i=0; i<N; i++){
        cin >> n;
        Map[n]++;
    }

    for(auto p : Map){
        if(p.second > largest || (p.second==largest && p.first < lNum)){
            largest = p.second;
            lNum = p.first;
        }
    }

    cout << lNum << '\n';

    return 0;
}