#include <iostream>
using namespace std;

const int MAX_N = 1000000;

int N;
int arr[MAX_N];
int result = 0;
int Leader, Follower;

int main() {
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    cin >> Leader >> Follower;

    for(int i=0; i<N; i++){
        result += 1 + (arr[i] - Leader + Follower - 1) / Follower;
    }

    cout << result << '\n';

    return 0;
}