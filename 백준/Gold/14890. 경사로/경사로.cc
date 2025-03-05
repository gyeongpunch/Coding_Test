#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <cstring>

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(nullptr);

using namespace std;

const int MX_N = 100;

int N, L;
int arr[MX_N][MX_N];

bool garo(int idx){
    int cnt = 1, i = 0, diff, j;

    while(i < N-1){
        diff = arr[idx][i+1] - arr[idx][i];

        if(diff > 1 || diff < -1) return false;

        if(diff == 0) {
            cnt++;
        }
        else if(diff == 1){

            if(cnt >= L){
                cnt = 1;
            }
            else return false;
        }
        else if(diff == -1){
            j = 1;
            while(j <= L){
                if(arr[idx][i+j] != arr[idx][i]-1) return false;

                j++;
            }
            i += (j-1);
            cnt = 0;
            continue;
        }

        i++;
    }
    return true;
}

bool sero(int idx){
    int cnt = 1, i = 0, diff, j;

    while(i < N-1){
        diff = arr[i+1][idx] - arr[i][idx];

        if(diff > 1 || diff < -1) return false;

        if(diff == 0) {
            cnt++;
        }
        else if(diff == 1){

            if(cnt >= L){
                cnt = 1;
            }
            else return false;
        }
        else if(diff == -1){
            j = 1;
            while(j <= L){
                if(arr[i+j][idx] != arr[i][idx]-1) return false;

                j++;
            }
            i += (j-1);
            cnt = 0;
            continue;
        }

        i++;
    }
    return true;
}

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    cin >> N >> L;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> arr[i][j];
        }
    }

    int result = 0;
    for(int i=0; i<N; i++){
        if(garo(i)){
            result++;
            // cout << "garo: " << i << '\n';
        }
        if(sero(i)){
            result++;
            // cout << "sero: " << i << '\n';
        }
    }

    cout << result << '\n';

    return 0;
}