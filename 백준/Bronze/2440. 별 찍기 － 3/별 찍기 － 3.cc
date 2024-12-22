#include <iostream>

using namespace std;

int main(void){
    int N;
    cin >> N;
    for(int i=N; i>0; i--){
        cout << string(i, '*') << endl;
    }
    
    return 0;
}