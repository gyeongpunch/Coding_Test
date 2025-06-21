#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <cstring>

using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(nullptr);

struct Info{
    int from, to, cnt;
};

const int MXN=2001;
const int MXM=10000;

int N, C, M;
Info arr[MXM];
int visited[MXN];
int result;

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    cin >> N >> C >> M;
    int from, to, cnt;
    for(int i=0; i<M; i++){
        cin >> arr[i].from >> arr[i].to >> arr[i].cnt;
    }

    sort(arr, arr+M, [](const Info& a, const Info& b){
        return a.to < b.to;
    });

    for(int i=0; i<M; i++){
        int maxLoad = 0;
        Info now = arr[i];
        for(int j=now.from; j<now.to; j++){
            maxLoad = max(maxLoad, visited[j]);
        }

        int canLoad = min(C-maxLoad, now.cnt);

        for(int j=now.from; j<now.to; j++){
            visited[j] += canLoad;
        }
        result += canLoad;
    }

    cout << result << '\n';

    return 0;
}