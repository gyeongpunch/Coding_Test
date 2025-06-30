#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(nullptr);
typedef long long ll;

struct Point{
    int x, y;
};

const int MX = 100000;

int N;
Point arr[MX];
ll minDist = LLONG_MAX;

bool cmp1(Point a, Point b){
    return a.x < b.x;
}

ll get_point_distance(const Point &a, const Point &b){
    return (ll)(a.x-b.x)*(a.x-b.x) + (ll)(a.y-b.y)*(a.y-b.y);
}

ll x_distance(int a, int b){
    return (ll)(arr[a].x-arr[b].x)*(arr[a].x-arr[b].x);
}

bool cmp2(Point a, Point b){
    return a.y < b.y;
}

ll y_distance(const vector<Point>& tmp, int a, int b){
    return (ll)(tmp[a].y-tmp[b].y)*(tmp[a].y-tmp[b].y);
}

ll devide_and_conquer(int left, int right){
    if(right - left <= 3){
        ll dist = LLONG_MAX;
        for(int i=left; i<right; i++){
            for(int j=i+1; j<right; j++){
                dist = min(dist, get_point_distance(arr[i], arr[j]));
            }
        }
        return dist;
    }

    int mid = (right + left) / 2;
    ll nowDist = min(devide_and_conquer(left, mid), devide_and_conquer(mid, right));
    vector<Point> tmp;

    for(int i=left; i<right; i++){
        if(x_distance(i, mid) < nowDist){
            tmp.push_back(arr[i]);
        }
    }
    sort(tmp.begin(), tmp.end(), cmp2);

    for(int i=0; i<tmp.size(); i++){
        for(int j=i+1; j<tmp.size() && y_distance(tmp, i, j)<nowDist; j++){
            nowDist = min(nowDist, get_point_distance(tmp[i], tmp[j]));
        }
    }
    return nowDist;
}

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> arr[i].x >> arr[i].y;
    }

    sort(arr, arr+N, cmp1);

    ll result = devide_and_conquer(0, N);

    cout << result << '\n';

    return 0;
}