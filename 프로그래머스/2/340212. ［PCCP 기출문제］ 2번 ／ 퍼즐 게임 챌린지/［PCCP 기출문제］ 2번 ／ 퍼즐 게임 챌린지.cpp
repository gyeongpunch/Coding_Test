#include <string>
#include <vector>

using namespace std;

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int N = times.size();
    int low = 1;
    int high = 10000000;
    int mid;
    long long score;
    
    while (high >= low){
        mid = (high + low) / 2;
        score = 0;
        for(int i=0; i<N; i++){
            score += times[i];
            if(mid < diffs[i]){
                score += (times[i-1] + times[i]) * (diffs[i] - mid);
            }
            if(score > limit){
                break;
            }
        }
        if(score > limit){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
        
    }
    return low;
}