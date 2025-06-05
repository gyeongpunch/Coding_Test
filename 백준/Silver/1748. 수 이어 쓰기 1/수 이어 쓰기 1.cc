#include <iostream>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

int N;
long long result;

int main(void){
    fastio
    // freopen("input.txt", "r", stdin);

    cin >> N;

    int prev = 1;
    int now = 10;
    int st = 1;

    while(true){
        if(prev<=N && N<now){
            result += st * (N-prev+1);
            break;
        }
        result += st * (now - prev);
        prev*=10;
        now*=10;
        st++;
    }

    cout << result << '\n';

    return 0;
}