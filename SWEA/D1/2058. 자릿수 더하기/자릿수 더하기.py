#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
	int T;
    // freopen("input.txt", "r", stdin);
    // cin >> T;
    T = 1;
    for(int test_case=1; test_case <= T; test_case++){
        int N;
        cin >> N;
        int result = 0;
        while(N > 0){
            result += N%10;
            N /= 10;
        }
        cout << result << endl;
    }

    return 0;
}