#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <cstring>

using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(nullptr);

const int MX = 10000;

int N;
int arr[MX];

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }

    int i = N-1;
    while(i-1>=0 && arr[i-1] < arr[i]) i--;

    if(i == 0){
        cout << -1 << '\n';
        return 0;
    }

    int j = N-1;
    while(arr[j] >= arr[i-1]) j--;

    swap(arr[i-1], arr[j]);

    reverse(arr+i, arr+N);

    for(int i=0; i<N; i++){
        cout << arr[i] << ' ';
    }
    cout << '\n';

    return 0;
}