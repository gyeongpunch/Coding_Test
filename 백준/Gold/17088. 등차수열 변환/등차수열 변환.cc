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

const int MX = 100000;

int N;
int arr[MX];

int get_result(){
    if(N <= 2) return 0;
    vector<int> d;
    for(int i=-1; i<2; i++){
        for(int j=-1; j<2; j++){
            d.push_back(arr[1]+i-(arr[0]+j));
        }
    }


    int result = INT_MAX;

    for(int i=0; i<9; i++){
        for(int j=-1; j<2; j++){
            int now = arr[0] + j;
            int dist = d[i];


            int cnt = j!=0 ? 1 : 0;

            bool flag = true;
            for(int k=1; k<N; k++){
                if(now + dist - 1 <= arr[k] && arr[k] <= now + dist + 1){
                    if(arr[k] != now + dist){
                        cnt++;
                    }
                    now += dist;
                }
                else{
                    flag = false;
                    break;
                }
            }
            if(flag){
                result = min(result, cnt);
            }
        }
    }
    if(result == INT_MAX) result = -1;

    return result;
}

int main(void){
    fastio;
    
    cin >> N;
    for(int i=0; i<N; i++) cin >> arr[i];

    int result = get_result();

    cout << result << '\n';

    return 0;
}