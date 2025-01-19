#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int toDate(int m, int d){
    return m*100+d;
}

bool custom_compare(pair<int, int> a, pair<int, int> b){
    if(a.first == b.first){
        return a.second > b.second;
    }
    return a.first < b.first;
}

int main(void){
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    vector<pair<int, int>> flowers;
    for(int i=0; i<n; i++){
        int sm, sd, em, ed;
        cin >> sm >> sd >> em >> ed;
        flowers.push_back({toDate(sm, sd), toDate(em, ed)});
    }

    sort(flowers.begin(), flowers.end(), custom_compare);

    int start = toDate(3, 1);
    int end = toDate(11, 30);
    int current = start;
    int cnt = 0;
    int index = 0;

    while(current <= end){
        int max_End = current;

        while(index<flowers.size() && flowers[index].first <= current){
            max_End = max(max_End, flowers[index++].second);
        }
        if(max_End==current){
            cout << 0 << '\n';
            return 0;
        }
        current = max_End;
        cnt++;
    }

    cout << cnt << '\n';

    return 0;
}