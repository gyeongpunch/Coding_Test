#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <numeric>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    int total = queue1.size() * 4;
    long long left = accumulate(queue1.begin(), queue1.end(), 0ll);
    long long right = accumulate(queue2.begin(), queue2.end(), 0ll);
    long long target = left + right;
    
    if(target % 2 != 0){
        return -1;
    }
    target /= 2;
    
    deque<int> q1(queue1.begin(), queue1.end());
    deque<int> q2(queue2.begin(), queue2.end());
    
    while (left != right && answer <= total) {
        if (left > right) {
            int val = q1.front();
            q1.pop_front();
            left -= val;
            right += val;
            q2.push_back(val);
        } else {
            int val = q2.front();
            q2.pop_front();
            right -= val;
            left += val;
            q1.push_back(val);
        }
        answer++;
    }
    
    return left==right ? answer : -1;
}