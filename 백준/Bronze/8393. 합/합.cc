#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main(void){
    int N;
    cin >> N;
    vector<int> v(N);

    iota(v.begin(), v.end(), 1);

    cout << accumulate(v.begin(), v.end(), 0) << endl;
    
    return 0;
} 