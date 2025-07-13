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

int N;
int result;

void get_result(int s, int e){
    if(s >= e) return;

    int m = (s + e) / 2;
    result += (m-s+1) * (e-m);
    get_result(s, m);
    get_result(m+1, e);
}

int main(void){
    fastio;
    
    cin >> N;

    get_result(1, N);

    cout << result << '\n';


    return 0;
}