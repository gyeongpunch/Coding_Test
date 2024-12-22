#include <iostream>
#include <cmath>

using namespace std;

int main(void){
    int M, N;
    int min=-1, sum=0;
    cin >> M;
    cin >> N;

    for(int i=N; i>=M; i--){
        if((int)sqrt(i) * (int)sqrt(i) == i){
            min = i; 
            sum += i;
        }
    }
    if(min == -1){
        cout << min << endl;
    }
    else{
        cout << sum << endl << min << endl;
    }

    return 0;
}