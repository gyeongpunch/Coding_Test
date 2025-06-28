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

const int MX = 100001;

int N;
int inOrder[MX];
int postOrder[MX];
int preOrder[MX];
int preIdx;
unordered_map<int, int> inIdx;

void get_preOrder(int in_l, int in_r, int post_l, int post_r){
    if(in_l > in_r || post_l > post_r) return;

    int nowRoot = postOrder[post_r];
    preOrder[preIdx++] = nowRoot;

    int inOrderIdx = inIdx[nowRoot];
    int leftSize = inOrderIdx - in_l;

    get_preOrder(in_l, inOrderIdx-1, post_l, post_l + leftSize - 1);

    get_preOrder(inOrderIdx+1, in_r, post_l+leftSize, post_r-1);
}

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> inOrder[i];
        inIdx[inOrder[i]] = i;
    }
    for(int i=0; i<N; i++) cin >> postOrder[i];

    get_preOrder(0, N-1, 0, N-1);

    for(int i=0; i<N; i++) cout << preOrder[i] << ' ';
    cout << '\n';

    return 0;
}