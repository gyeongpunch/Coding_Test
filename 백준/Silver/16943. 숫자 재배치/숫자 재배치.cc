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

int A, B;
int N;
unordered_map<int, int> Map;
int result = -1;

void dfs(int now, int depth){
    if(depth == N){
        if(now < B){
            result = max(result, now);
        }
        return;
    }
    
    for(int i=0; i<10; i++){
        if(depth==0 && i==0) continue;

        if(Map[i] > 0){
            int nxt = now * 10 + i;
            Map[i]--;

            dfs(nxt, depth+1);

            Map[i]++;
        }
    }

}

int main(void){
    fastio;
    
    cin >> A >> B;
    
    int num = A;
    while(num > 0){
        Map[num%10]++;
        num /= 10;
        N++;
    }

    dfs(0, 0);

    cout << result << '\n';

    return 0;
}