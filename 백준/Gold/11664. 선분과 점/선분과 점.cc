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

struct Point{
    double x, y, z;
};

Point A, B, C;

double get_distance(Point a, Point b){
    double d1 = pow(b.x-a.x, 2);
    double d2 = pow(b.y-a.y, 2);
    double d3 = pow(b.z-a.z, 2);

    return sqrt(d1+d2+d3);
}

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    cin >> A.x >> A.y >> A.z >> B.x >> B.y >> B.z >> C.x >> C.y >> C.z;

    double result;

    for(int i=0; i<100; i++){
        Point mid = {(A.x + B.x) / 2.0, (A.y + B.y) / 2.0, (A.z + B.z) / 2.0};

        double d1 = get_distance(A, C);
        double d2 = get_distance(B, C);

        if(d1 < d2){
            B = mid;
            result = d1;
        }
        else{
            A = mid;
            result = d2;
        }
    }

    cout << fixed;
    cout.precision(10);
    cout << result << '\n';



    return 0;
}