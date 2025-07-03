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
#include <cmath>

using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(nullptr);

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    double x, y, c;
    cin >> x >> y >> c;

    double l = 0, r = min(x, y);
    double result = 0;
    for(int i=0; i<100; i++){
        double w = (l + r) / 2.0;
        double h1 = sqrt(pow(x, 2) - pow(w, 2));
        double h2 = sqrt(pow(y, 2) - pow(w, 2));

        double cc = (h1 * h2) / (h1 + h2);

        if (cc >= c){
            result = w;
            l = w;
        }
        else{
            r = w;
        }
    }

    cout << fixed;
    cout.precision(3);
    cout << result << '\n';

    return 0;
}