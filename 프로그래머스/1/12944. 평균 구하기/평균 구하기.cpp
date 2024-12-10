#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
    double answer = 0;
    
    int sum = 0;
    int length = arr.size();
    
    for (int i=0; i<length; i++){
        sum += arr[i];
    }
    
    answer = double(sum)/length;
    
    return answer;
}