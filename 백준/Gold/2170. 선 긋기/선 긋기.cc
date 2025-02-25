#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <cstring>

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(nullptr);

using namespace std;

struct Line{
    long long start, end;
};

const int MAX_N = 1000000;

int N;
Line arr[MAX_N];

bool custom_compare(Line a, Line b){
    if(a.start == b.start){
        return a.end > b.end;
    }
    return a.start < b.start;
}

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    cin >> N;

    long long s, e;
    for(int i=0; i<N; i++){
        cin >> s >> e;
        arr[i] = {s, e};
    }

    sort(arr, arr + N, custom_compare);

    long long total_length = arr[0].end - arr[0].start;
    long long now = arr[0].end;

    for(int i=1; i<N; i++){
        if(now >= arr[i].end) continue;

        if(now < arr[i].start){
            total_length += arr[i].end - arr[i].start;
            now = arr[i].end;
        }
        else{
            total_length += arr[i].end - now;
            now = arr[i].end;
        }
    }

    cout << total_length << '\n';

    return 0;
}