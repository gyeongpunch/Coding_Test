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

ll d, dx, dy;
string num;
ll x, y;
string result;

void get_point(const string& num, ll d, ll& x, ll& y){
    ll len = 1LL << (d-1);
    for(int i=0; i<d; i++){
        if(num[i]=='1') y+=len;
        else if(num[i]=='3') x+=len;
        else if(num[i]=='4') x+=len, y+=len;
        
        len >>= 1;
        // cout << x << ' ' << y << '\n';
    }
}

void move_point(){
    if(x-dx<0 || x-dx>=(1LL << d) || y+dy<0 || y+dy>=(1LL << d)) {
        result="X";
        return;
    }
    x-=dx;
    y+=dy;
}

void get_result(){
    if(result=="X") {
        cout << -1 << '\n';
        return;
    }

    for(int i=d-1; i>=0; i--){
        if((x>>i)&1 && (y>>i)&1) result += "4";
        else if((x>>i)&1) result += "3";
        else if((y>>i)&1) result += "1";
        else result += "2";
    }
    cout << result << '\n';
}

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    cin >> d >> num >> dy >> dx;

    get_point(num, d, x, y);
    
    move_point();

    get_result();

    return 0;
}