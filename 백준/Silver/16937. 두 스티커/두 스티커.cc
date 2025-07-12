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

struct Info{
    int h, w;
};

const int MX = 100;

int H, W, N;
Info arr[MX];
int result;

void solution(){
    for(int i=0; i<N-1; i++){
        for(int j=i+1; j<N; j++){
            int A[2] = {arr[i].h, arr[i].w};
            int B[2] = {arr[j].h, arr[j].w};

            int sm = arr[i].h*arr[i].w + arr[j].h*arr[j].w;

            for(int i=0; i<2; i++){
                for(int j=0; j<2; j++){
                    int a = A[i]+B[j];
                    int b = max(A[1-i], B[1-j]);

                    if(a > b) swap(a, b);

                    if(a <= H && b <= W && result < sm) result = sm;
                }
            }
        }
    }
}

int main(void){
    fastio;
    
    cin >> H >> W >> N;
    if(H > W) swap(H, W);
    for(int i=0; i<N; i++){
        cin >> arr[i].w >> arr[i].h;
    }

    solution();

    cout << result << '\n';

    return 0;
}