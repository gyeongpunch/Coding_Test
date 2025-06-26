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

const int MX = 100000;

int N;

int solution(string a, string b, bool isFirstToggle){
    int cnt = 0;

    if(isFirstToggle){
        a[0] = (char)('1'-a[0]+'0');
        a[1] = (char)('1'-a[1]+'0');
        cnt++;
    }

    for(int i=1; i<N; i++){
        if(a[i-1] == b[i-1]) continue;

        for(int j=i-1; j<min(i+2, N); j++){
            a[j] = (char)('1'-a[j]+'0');
        }
        cnt++;
    }

    // cout << a[N-1] << ' ' << b[N-1] << '\n';

    return a[N-1]==b[N-1] ? cnt : -1;

}

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    cin >> N;
    string a, b;
    cin >> a >> b;
    int c1 = solution(a, b, true);
    int c2 = solution(a, b, false);

    // cout << c1 << ' ' << c2 << '\n';

    int result = c1==-1&&c2==-1 ? -1 : (c1==-1 ? c2 : (c2==-1 ? c1 : min(c1, c2)));

    cout << result << '\n';

    return 0;
}