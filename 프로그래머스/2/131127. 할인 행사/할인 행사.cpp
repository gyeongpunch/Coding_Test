#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    map<string, int> m;
    
    for(int i=0; i<number.size(); i++){
        m[want[i]] = number[i];
    }
    
    // for(const auto& [key, value] : m){
    //     cout << key << ": " << value << endl;
    // }
    
    for(int i=0; i<discount.size()-9; i++){
        map<string, int> tmp(m);
        for(int j=i; j<i+10; j++){
            if(tmp.count(discount[j]) > 0 && tmp[discount[j]] > 0){
                tmp[discount[j]]--;
                if(tmp[discount[j]] == 0){
                    tmp.erase(discount[j]);
                }
            }
        }
        // bool once = true;
        // if(once){
        //     for(const auto& [key, value] : tmp){
        //         cout << key << ": " << value << endl;
        //     }
        //     once = false;
        // }
        
        
        if(tmp.size() == 0){
            answer++;
        }
    }
    
    return answer;
}