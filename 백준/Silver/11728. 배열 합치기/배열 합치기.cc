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

const int MX = 1000000;

int N, M;
int A[MX], B[MX];
int total[MX+MX];

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    cin >> N >> M;
    for(int i=0; i<N; i++){
        cin >> A[i];
    }
    for(int i=0; i<M; i++){
        cin >> B[i];
    }

    sort(A, A+N);
    sort(B, B+M);

    int ia=0, ib=0, idx=-1;
    while(ia!=N || ib!=M){
        if(ia==N){
            total[++idx] = B[ib++];
        }
        else if(ib==M){
            total[++idx] = A[ia++];
        }
        else{
            if(A[ia] < B[ib]){
                total[++idx] = A[ia++];
            }
            else{
                total[++idx] = B[ib++];
            }
        }
    }

    for(int i=0; i<N+M; i++){
        cout << total[i] << ' ';
    }
    cout << '\n';


    return 0;
}