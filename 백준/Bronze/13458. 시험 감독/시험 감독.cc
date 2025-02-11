#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);

    int N;
    cin >> N;

    int A[N];
    for(int i=0; i<N; i++){
        cin >> A[i];
    }
    int B, C;
    cin >> B >> C;

    long long cnt = 0;
    for(int i=0; i<N; i++){
        if(A[i]-B > 0){
            cnt += (A[i]-B+C-1) / C + 1;
        }
        else{
            cnt++;
        }
    }

    cout << cnt << '\n';

    return 0;
}