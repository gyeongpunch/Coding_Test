#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    map<int, int> left;
    map<int, int> right;
    
    for(int i : topping){
        right[i]++;
    }
    
    for(int i=0; i<topping.size(); i++){
        left[topping[i]]++;
        right[topping[i]]--;
        if(right[topping[i]] == 0){
            right.erase(topping[i]);
        }
        if(left.size() == right.size()){
            answer++;
        }
    }
    
    return answer;
}