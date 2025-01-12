#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<pair<int, int>> meetings(N);
    for(int i=0; i<N; i++){
        cin >> meetings[i].first >> meetings[i].second;
    }
    sort(meetings.begin(), meetings.end(), [](pair<int, int> a, pair<int, int> b) {
        if (a.second == b.second)
            return a.first < b.first;
        return a.second < b.second;
    });

    int cnt = 0;
    int last_end_time = 0;

    for(auto& meeting : meetings){
        if(meeting.first >= last_end_time){
            cnt++;
            last_end_time = meeting.second;
        }
    }

    cout << cnt << '\n';

    return 0;
}