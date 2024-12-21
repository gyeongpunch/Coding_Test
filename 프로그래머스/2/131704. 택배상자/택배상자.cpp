#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    stack<int> stack;
    
    for(int i=1; i <= order.size(); i++){
        if(order[answer] != i){
            stack.push(i);
        }
        else{
            answer++;
            while(!stack.empty() && stack.top()==order[answer]){
                answer++;
                stack.pop();
            }
        }
    }
    
    return answer;
}