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

const int MX = 500000;

int N, M;
int A[MX];
int B[MX];
vector<int> result;

bool binary_search(int target, int Start, int End){
    // cout << target << ' ' << Start << ' ' << End << '\n';
    int mid = (Start+End) / 2;

    if(B[mid] == target){
        return false;
    }

    if(Start == End){
        return true;
    }

    if(target < mid){
        return binary_search(target, Start, mid-1);
    }
    else if(mid < target){
        return binary_search(target, mid+1, End);
    }
}

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

    int aIdx = 0, bIdx = 0;
    
    while(aIdx < N && bIdx < M){
        if(A[aIdx] == B[bIdx]){
            aIdx++;
            bIdx++;
        }
        else if(A[aIdx] < B[bIdx]){
            result.push_back(A[aIdx]);
            aIdx++;
        }
        else{
            bIdx++;
        }
    }

    for(int i=aIdx; i<N; i++){
        result.push_back(A[i]);
    }

    cout << result.size() << '\n';
    for(int n : result){
        cout << n << ' ';
    }
    cout << '\n';

    return 0;
}