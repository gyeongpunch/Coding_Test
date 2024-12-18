#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    string tmp = "";
    vector<int> v;
    
    for (int i=0; i<s.size(); i++){
        if (s[i] == ' '){
            v.push_back(stoi(tmp));
            tmp.clear();
            continue;
        }
        tmp += s[i];
    }
    if (!tmp.empty()){
        v.push_back(stoi(tmp));
    }
    // for (int num : v){
    //     cout << num << ' ';
    // }
    sort(v.begin(), v.end());
    answer = to_string(v.front()) + " " + to_string(v.back());
    return answer;
}