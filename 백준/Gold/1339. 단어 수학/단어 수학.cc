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
    int weight;
    char chr;
};

const int MX = 10;

int N;
string arr[MX];
unordered_map<char, int> dict;
unordered_map<char, int> Map;
int result;

void calc(){
    int sum=0;
    for(int i=0; i<N; i++){
        int now = 0;
        for(int j=0; j<arr[i].size(); j++){
            now = now*10 + Map[arr[i][j]];
        }
        sum += now;
    }
    result = sum;
}

bool custom_compare(Info a, Info b){
    return a.weight > b.weight;
}

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    cin >> N;
    string s;
    for(int i=0; i<N; i++){
        cin >> arr[i];
        int pow = 1;
        for(int j=arr[i].size()-1; j>-1; j--){
            dict[arr[i][j]] += pow;
            pow *= 10;
        }
    }

    vector<Info> v;
    for(auto &d : dict){
        v.push_back({d.second, d.first});
    }

    sort(v.begin(), v.end(), custom_compare);

    for(int i=0; i<v.size(); i++){
        // cout << v[i].chr << ' ' << v[i].weight << '\n';
        Map[v[i].chr] = 9-i;
    }

    calc();

    cout << result << '\n';

    return 0;
}