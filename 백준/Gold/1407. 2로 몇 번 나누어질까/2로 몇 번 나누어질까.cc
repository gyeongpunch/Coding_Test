#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long F(long long num){
    long long sum = num;
    for(long long i=2; i<=num; i=i*2){
        sum += (num/i) * (i/2);
    }
    return sum;
}

int main(void){

    ios::sync_with_stdio(0);
    cin.tie(0);

    long long A, B;
    cin >> A >> B;

    long long result = F(B) - F(A-1);

    cout << result << '\n';

    return 0;
}