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
        vector<int> data(N, 0);

        for(int i=0; i<N; i++){
            cin >> data[i];
        }

        sort(data.begin(), data.end());

        cout << data[N/2] << endl;

    }

    return 0;
}