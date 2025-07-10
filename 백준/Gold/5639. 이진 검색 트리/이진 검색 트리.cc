#include <iostream>
#include <queue>
#include <string>
#include <climits>
#include <unordered_map>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

struct Node{
    int l, r;
    Node() : l(-1), r(-1) {}
};

const int MX = 10005;

int N;
int preOrder[MX];
Node tree[1000001];
int root;

void get_result(int s, int e){
    if(s >= N) return;
    if(e >= N) return;
    if(s == e) return;

    int r = preOrder[s];
    int le;
    int rs=-1;

    for(int i=s+1; i<=e; i++){
        if(preOrder[i] > r){
            rs = i;
            break;
        }
    }
    le = rs-1;
    if(rs == -1) le = e;


    // cout << r << ' ' << s << ' ' << e << ' ' << le << '\n';
    if(s+1 == rs){
        tree[r].r = preOrder[rs];
        get_result(rs, e);
    }
    else if(rs == -1){
        tree[r].l = preOrder[s+1];
        get_result(s+1, le);
    }
    else{
        tree[r].l = preOrder[s+1];
        tree[r].r = preOrder[rs];

        get_result(s+1, le);
        get_result(rs, e);
    }
}

void get_print(int r){
    if(tree[r].l != -1){
        get_print(tree[r].l);
    }
    if(tree[r].r != -1){
        get_print(tree[r].r);
    }
    cout << r << '\n';
}

int main(void) {
    fastio;

    for(int i=0; i<MX; i++){
        cin >> preOrder[i];

        if(i == 0){
            root = preOrder[i];
        }

        if(preOrder[i] == 0){
            N = i;
            break;
        }
    }
    
    get_result(0, N-1);

    get_print(root);

    
    
    return 0; 
}
