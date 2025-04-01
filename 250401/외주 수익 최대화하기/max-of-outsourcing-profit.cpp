#include <iostream>
using namespace std;

int N;
int t[15];
int p[15];
int result = 0;

void back(int now, int sum){
    // cout << now << ' ' << sum << '\n';

    if(now >= N){
        result = max(result, sum);
        return;
    }

    back(now+1, sum);

    if(now + t[now] <= N){
        back(now + t[now], sum + p[now]);
    }
}

int main() {
    
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> t[i] >> p[i];
    }

    back(0, 0);

    cout << result << '\n';

    return 0;
}