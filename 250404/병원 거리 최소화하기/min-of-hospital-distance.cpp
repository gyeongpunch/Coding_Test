#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define MAX_N 50

struct Point{
    int x, y;
};

int N, M;
int arr[MAX_N][MAX_N];
vector<Point> totalHos;
vector<Point> totalPeo;
vector<int> path;
int result = 1e9;

void simulation(){
    int sum = 0;

    for(const Point &pp : totalPeo){
        int sub = 1e9;
        for(const int &i : path){
            sub = min(sub, abs(pp.x - totalHos[i].x) + abs(pp.y - totalHos[i].y));
        }
        sum += sub;
    }
    result = min(result, sum);
}

void makeComb(int depth, int prev){
    if(depth == M){
        simulation();
        return;
    }

    for(int i=prev+1; i<totalHos.size(); i++){
        path.push_back(i);

        makeComb(depth + 1, i);

        path.pop_back();
    }
}

int main() {
    fastio;

    cin >> N >> M;

    int a;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> a;

            if(a == 1){
                totalPeo.push_back({i, j});
            }
            else if (a == 2){
                totalHos.push_back({i, j});
            }
        }
    }

    makeComb(0, -1);

    cout << result << '\n';

    return 0;
}