#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int p_cnt = 0;
    int y_cnt = 0;
    
    for (int i=0; i<s.size(); i++){
        if (s[i]=='y' or s[i]=='Y'){
            y_cnt++;
        }
        else if (s[i]=='p' or s[i]=='P'){
            p_cnt++;
        }
    }
    

    return p_cnt==y_cnt;
}