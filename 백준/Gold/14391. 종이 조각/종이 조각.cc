#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <cstring>

using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(nullptr);

const int MX = 4;

int N, M;
int arr[MX][MX];

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    cin >> N >> M;
    string s;
    for(int i=0; i<N; i++){
        cin >> s;
        for(int j=0; j<M; j++){
            arr[i][j] = (int)(s[j] - '0');
        }
    }

    
    int result = 0;
    for(int flag=0; flag < (1<<(N*M)); flag++){
        int sum = 0, tmp = 0;

        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                int idx = M*i+j;
                if((flag & (1<<idx)) == 0){
                    tmp = tmp*10 + arr[i][j];
                }
                else{
                    sum += tmp;
                    tmp = 0;
                }
            }
            sum += tmp;
            tmp = 0;
        }

        for(int j=0; j<M; j++){
            for(int i=0; i<N; i++){
                int idx = M*i+j;
                if((flag & (1<<idx)) != 0){
                    tmp = tmp*10 + arr[i][j];
                }
                else{
                    sum += tmp;
                    tmp = 0;
                }
            }
            sum += tmp;
            tmp = 0;
        }
        result = max(result, sum);
    }

    cout << result << '\n';

    return 0;
}