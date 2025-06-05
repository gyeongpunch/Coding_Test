#include <iostream>

using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

int E, S, M;

int main(void){
    fastio;

    // freopen("input.txt", "r", stdin);

    cin >> E >> S >> M;

    int year = 1;

    while(true){
        int e = (year - 1) % 15 + 1;
        int s = (year - 1) % 28 + 1;
        int m = (year - 1) % 19 + 1;

        if(e==E && s==S && m==M){
            break;
        }
        year++;
    }

    cout << year << '\n';

    return 0;
}