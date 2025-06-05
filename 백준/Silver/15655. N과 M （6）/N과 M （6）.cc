#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <cstring>

using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(nullptr);

int N, M;
vector<int> numbers;
vector<int> path;

void get_comb(int depth, int prev){
    if(depth == M){
        for(int n : path){
            cout << n << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i=prev+1; i<N; i++){
        path.push_back(numbers[i]);

        get_comb(depth+1, i);

        path.pop_back();
    }
}

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    cin >> N >> M;
    int n;
    for(int i=0; i<N; i++){
        cin >> n;
        numbers.push_back(n);
    }
    sort(numbers.begin(), numbers.end());

    get_comb(0, -1);

    return 0;
}