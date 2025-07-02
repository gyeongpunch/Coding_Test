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
typedef long long ll;

int N, K;

int isInRange(ll start, ll num, int cnt, int target, ll now){
    ll nowTotal = (num - start) * cnt + now;
    ll left = nowTotal+1;
    ll right = nowTotal+cnt;

    if(target < left) return -1;
    else if(target > right) return 1;
    else return 0;
}

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    cin >> N >> K;
    ll flag = 10;
    int cnt = 1;

    ll now = 0;
    
    while(true){
        
        if(now + (flag-(flag/10)) * cnt < K){
            now += (flag-(flag/10)) * cnt; 
            flag *= 10;
            cnt++;
        }
        else{
            ll start = flag / 10;

            ll left = flag / 10;
            ll right = flag - 1;

            // cout << "!!!!!!!!!!!!!!!!!!!!\n";
            while(left <= right){
                // cout << left << ' ' << right << '\n';
                ll mid = (left + right) / 2;

                int check = isInRange(start, mid, cnt, K, now);
                if(check == 0){
                    if(mid > N){
                        cout << -1 << '\n';
                        break;
                    }
                    now += (mid - start) * cnt;
                    ll rest = cnt - (K - now);
                    for(int i=0; i<rest; i++){
                        mid /= 10;
                    }
                    cout << mid % 10 << '\n';
                    break;
                }
                else if(check == 1){
                    left = mid + 1;
                }
                else if(check == -1){
                    right = mid - 1;
                }
            }
            break;
        }
        // cout << now << '\n';
    }

    // cout << now << '\n';

    return 0;
}