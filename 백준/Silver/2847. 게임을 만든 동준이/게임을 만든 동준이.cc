#include <iostream>
#include <vector>

using namespace std;

int main(void){
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    vector<int> arr(N);
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    int result = 0;
    int now = arr[N-1];
    for(int i=N-2; i>-1; i--){
        if(now <= arr[i]){
            now = now - 1;
            result += arr[i] - now;

        }
        else{
            now = arr[i];
        }
    }
    cout << result << '\n';

    return 0;
}