#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <cstring>

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(nullptr);
using namespace std;
#define MAX_N 19

int N;
char cmds[MAX_N];
long long nums[MAX_N];
char ops[MAX_N];
long long numsOrigin[MAX_N];

long long result = -100000000000;
vector<vector<int>> totalComb;
vector<int> path;

void calc(){
    long long subResult = nums[0];

    for(int i=0; i<N/2; i++){
        if(ops[i] == '+'){
            subResult = subResult + nums[i+1];
        }
        else if (ops[i] == '-'){
            subResult = subResult - nums[i+1];
        }
        else if (ops[i] == '*'){
            subResult = subResult * nums[i+1];
        }
    }
    result = max(result, subResult);
    // cout << subResult << '\n';
}

void makeComb(int prev){
    if(prev+2 >= N/2){
        return;
    }

    for(int i=prev+2; i<N/2; i++){
        path.push_back(i);

        totalComb.push_back(path);

        makeComb(i);
        path.pop_back();
    }
}

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> cmds[i];
        if(i%2 == 0){
            numsOrigin[i/2] = (int)(cmds[i] - '0');
            nums[i/2] = numsOrigin[i/2];
        }
        else{
            ops[i/2] = cmds[i];
        }
    }

    if(N==1) result = nums[0];

    makeComb(-2);


    for(const vector<int> oneComb : totalComb){
        // for(int i : oneComb){
        //     cout << i << ' ';
        // }
        // cout << '\n';

        for(int i : oneComb){
            long long n1 = nums[i], n2 = nums[i+1];
            char op = ops[i];

            if(op == '+'){
                nums[i] = n1 + n2;
                nums[i + 1] = 0;
            }
            else if (op == '-'){
                nums[i] = n1 - n2;
                nums[i + 1] = 0;
            }
            else if (op == '*'){
                nums[i] = n1 * n2;
                nums[i + 1] = 1;
            }
        }
        // cout << '\n';
        // for(int i=0; i<N/2+1; i++){
        //     cout << nums[i] << ' ';
        // }
        // cout << '\n';
        calc();

        for(int i : oneComb){
            nums[i] = numsOrigin[i];
            nums[i+1] = numsOrigin[i+1];
        }
    }

    cout << result << '\n';

    return 0;
}