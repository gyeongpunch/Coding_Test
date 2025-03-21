#include <iostream>
using namespace std;

const int MAX_N = 1000000;

int N;
int arr[MAX_N];
long long result = 0;
int Leader, Follower;

int main() {
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    cin >> Leader >> Follower;

    for(int i=0; i<N; i++){
        result += 1;
        if(arr[i] - Leader > 0){
            result += (arr[i] - Leader + Follower - 1) / Follower;
        }
    }

    cout << result << '\n';

    return 0;
}