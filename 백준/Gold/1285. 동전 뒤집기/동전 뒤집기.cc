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

const int MX = 20;

int N;
char arr[MX][MX], tmp[MX][MX];
int result = MX*MX;

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> arr[i][j];
        }
    }

    for(int bit=0; bit<(1<<N); bit++){
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                tmp[i][j] = arr[i][j];
            }
        }
        for(int i=0; i<N; i++){
            if(bit & (1 << i)){
                for(int j=0; j<N; j++){
                    tmp[i][j] = tmp[i][j]=='T' ? 'H' : 'T';
                }
            }
        }

        int cnt=0;
        for(int j=0; j<N; j++){
            int cntTmp = 0;
            for(int i=0; i<N; i++){
                if(tmp[i][j] == 'T') cntTmp++;
            }
            cnt += min(cntTmp, N-cntTmp);
        }
        result = min(result, cnt);
    }

    cout << result << '\n';

    return 0;
}