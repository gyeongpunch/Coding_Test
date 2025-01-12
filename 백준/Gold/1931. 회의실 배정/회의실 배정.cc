#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 회의 정보를 저장할 구조체 또는 pair 사용
int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> meetings(N);

    for (int i = 0; i < N; i++) {
        cin >> meetings[i].first >> meetings[i].second;
    }

    // 종료 시간 기준으로 정렬, 종료 시간이 같다면 시작 시간 기준으로 정렬
    sort(meetings.begin(), meetings.end(), [](pair<int, int> a, pair<int, int> b) {
        if (a.second == b.second)
            return a.first < b.first;
        return a.second < b.second;
    });

    int count = 0; // 최대 회의 개수
    int last_end_time = 0; // 이전 회의의 종료 시간

    for (const auto& meeting : meetings) {
        if (meeting.first >= last_end_time) {
            // 현재 회의의 시작 시간이 이전 회의 종료 시간 이후라면 선택
            count++;
            last_end_time = meeting.second; // 종료 시간 업데이트
        }
    }

    cout << count << '\n';
    return 0;
}
