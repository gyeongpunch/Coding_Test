#include <string>
#include <vector>
#include <numeric>

using namespace std;

double solution(vector<int> arr) {
    double answer = accumulate(arr.begin(), arr.end(), 0);
    
    answer = answer/arr.size();
    
    return answer;
}