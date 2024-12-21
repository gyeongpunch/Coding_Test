#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    
    int start=0, end=0, sum=0;
    
    for(int i=0; i<sequence.size(); i++){
        end = i;
        sum+=sequence[end];
        
        while(sum>k){
            sum-=sequence[start++];
        }
        if(sum==k){
            if(answer.empty() || end-start < answer[1]-answer[0]){
                answer = {start, end};
            }
        }
    }
    
    return answer;
}