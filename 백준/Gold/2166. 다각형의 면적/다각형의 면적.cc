#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>

using namespace std;

typedef long long ll;

struct Point {
    ll x, y;
};

int N;
vector<Point> v;

int main() {
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        int a, b;
		cin >> a >> b;
		v.push_back({a, b});
    }

    ll sum = 0;

    for (int i = 0; i < N - 1; ++i) {
        sum += (v[i].x * v[i + 1].y);
        sum -= (v[i].y * v[i + 1].x);
    }
    
    sum += (v[N - 1].x * v[0].y);
    sum -= (v[N - 1].y * v[0].x);

    sum = abs(sum);
    double area = (double)sum / 2.0;

    printf("%.1f\n", area);

    return 0;
}