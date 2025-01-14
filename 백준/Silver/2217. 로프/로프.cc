#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> arr(N, 0);
    int mx = 0;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    for(int i=0; i<N; i++){
        mx = max(mx, (N-i)*arr[i]);
    }

    cout << mx << '\n';

    return 0;
}