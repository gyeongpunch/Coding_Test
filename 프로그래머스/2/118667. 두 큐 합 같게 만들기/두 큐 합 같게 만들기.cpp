#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    long long left = 0, right = 0;
    int total = queue1.size();
    
    queue<int> q1;
    queue<int> q2;
    for(int i=0; i<queue1.size(); i++){
        left += queue1[i];
        right += queue2[i];
        q1.push(queue1[i]);
        q2.push(queue2[i]);
    }
    
    
    while(left != right){
        if(left > right){
            left -= q1.front();
            right += q1.front();
            q2.push(q1.front());
            q1.pop();
        }
        else if(left < right){
            left += q2.front();
            right -= q2.front();
            q1.push(q2.front());
            q2.pop();
        }
        answer++;
        if(answer > total * 4){
            return -1;
        }
    }
    
    return answer;
}