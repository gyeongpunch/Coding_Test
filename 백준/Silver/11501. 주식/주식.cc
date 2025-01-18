#include <iostream>
#include <vector>

using namespace std;

int main(void){
    // freopen("input.txt", "r", stdin);
    int T;
    cin >> T;

    while(T--){
        int N;
        cin >> N;
        vector<int> arr(N);
        for(int i=0; i<N; i++){
            cin >> arr[i];
        }
        long long sm=0, mx = 0;
        for(int i=N-1; i>-1; i--){
            if(mx < arr[i]){
                mx = arr[i];
            }
            else{
                sm += (mx-arr[i]);
            }
        }
        cout << sm << '\n';
    }


    return 0;
}