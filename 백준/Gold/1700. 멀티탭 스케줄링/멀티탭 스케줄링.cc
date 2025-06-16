#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <cstring>

using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(nullptr);

const int MX = 100;

int N, K;
int arr[MX];
int result = 0;
unordered_set<int> Set;

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    cin >> N >> K;
    for(int i=0; i<K; i++){
        cin >> arr[i];
    }

    for(int i=0; i<K; i++){
        if(Set.count(arr[i]) != 0) continue;

        if(Set.size() < N){
            Set.insert(arr[i]);
            continue;
        }

        int outIdx=-1, out=-1;
        for(int n : Set){
            bool flag = false;
            int nowIdx;
            for(int j=i+1; j<K; j++){
                if(arr[j]==n){
                    nowIdx = j;
                    flag = true;
                    break;
                }
            }

            if(!flag){
                out = n;
                break;
            }
            if(outIdx < nowIdx){
                out = n;
                outIdx = nowIdx;
            }
        }

        Set.erase(out);
        Set.insert(arr[i]);
        result++;
    }

    cout << result << '\n';

    return 0;
}