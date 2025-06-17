#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MX = 8;
int N, M;
int arr[MX];
vector<int> path;

void get_result(int depth, int start) {
    if (depth == M) {
        for (int n : path) cout << n << ' ';
        cout << '\n';
        return;
    }
    int prev = -1;
    for (int i = start; i < N; i++) {
        if (arr[i] == prev) continue;
        path.push_back(arr[i]);
        get_result(depth + 1, i+1);
        path.pop_back();
        prev = arr[i];
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    // freopen("input.txt", "r", stdin);   
    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> arr[i];
    sort(arr, arr + N);

    get_result(0, 0);
    return 0;
}
