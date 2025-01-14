#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> B(N);

    for(int i=0; i<N; i++){
        cin >> A[i];
    }
    for(int i=0; i<N; i++){
        cin >> B[i];
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<int>());

    int result = 0;

    for(int i=0; i<N; i++){
        result += A[i]*B[i];
    }

    cout << result << '\n';

    return 0;
}