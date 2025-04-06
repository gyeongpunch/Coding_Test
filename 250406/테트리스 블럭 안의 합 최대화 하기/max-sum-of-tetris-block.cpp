#include <iostream>
#include <vector>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define MAX_SZ 200

struct Point{
    int dx, dy;
};

vector<vector<Point>> total = {
    // 1자 작대기
    {{0, 0}, {0, 1}, {0, 2}, {0, 3}}, {{0, 0}, {1, 0}, {2, 0}, {3, 0}},
    
    // 네모
    {{0, 0}, {0, 1}, {1, 0}, {1, 1}},
    
    // 니은1
    {{0, 0}, {1, 0}, {1, 1}, {1, 2}}, {{0, 1}, {1, 1}, {2, 1}, {2, 0}}, {{0, 0}, {0, 1}, {0, 2}, {1, 2}}, {{0, 0}, {0, 1}, {1, 0}, {2, 0}},
    
    // 니은2
    {{0, 2}, {1, 0}, {1, 1}, {1, 2}}, {{0, 0}, {0, 1}, {1, 1}, {2, 1}}, {{0, 0}, {0, 1}, {0, 2}, {1, 0}}, {{0, 0}, {1, 0}, {2, 0}, {2, 1}},
    
    // 지그재그
    {{0, 0}, {1, 0}, {1, 1}, {2, 1}}, {{0, 1}, {0, 2}, {1, 0}, {1, 1}}, {{0, 1}, {1, 1}, {1, 0}, {2, 0}}, {{0, 0}, {0, 1}, {1, 1}, {1, 2}},
    
    // T자
    {{0, 1}, {1, 0}, {1, 1}, {1, 2}}, {{0, 0}, {1, 0}, {1, 1}, {2, 0}}, {{0, 0}, {0, 1}, {1, 1}, {0, 2}}, {{0, 1}, {1, 0}, {1, 1}, {2, 1}}
};

int N, M;
int arr[MAX_SZ][MAX_SZ];
int result = 0;

bool bound_check(int x, int y){
    return 0<=x && x<N && 0<=y && y<M;
}

int calc(const vector<Point> &v, int x, int y){
    int nx, ny;
    int sum = 0;
    for(const Point &p : v){
        nx = x + p.dx;
        ny = y + p.dy;

        if(!bound_check(nx, ny)) return 0;

        sum += arr[nx][ny];
    }

    return sum;
}

int main() {
    fastio;

    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> arr[i][j];
        }
    }

    for(const vector<Point> &v : total){
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                result = max(result,  calc(v, i, j));
            }
        }
    }

    cout << result << '\n';

    return 0;
}