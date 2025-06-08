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
int result = 0;

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++){
            arr[i][j] = s[j] - '0';
        }
    }

    for (int bit = 0; bit < (1 << (N*M)); bit++) {
        int sum = 0;

        for (int i = 0; i < N; i++) {
            int num = 0;
            for (int j = 0; j < M; j++) {
                int idx = i * M + j;
                if ((bit & (1 << idx)) == 0) {
                    num = num * 10 + arr[i][j];
                } else {
                    sum += num;
                    num = 0;
                }
            }
            sum += num;
        }
        for (int j = 0; j < M; j++) {
            int num = 0;
            for (int i = 0; i < N; i++) {
                int idx = i * M + j;
                if ((bit & (1 << idx)) != 0) {
                    num = num * 10 + arr[i][j];
                } else {
                    sum += num;
                    num = 0;
                }
            }
            sum += num;
        }
        result = max(result, sum);
    }
    cout << result << '\n';
    return 0;
}