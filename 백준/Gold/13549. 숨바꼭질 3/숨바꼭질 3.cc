#include <iostream>
#include <deque>
#include <vector>

#define MAX 200000

using namespace std;

int N, K;
vector<int> arr;

int main(void){

    cin >> N >> K;
    arr.resize(MAX, -1);
    arr[N] = 0;
    deque<int> dq;
    dq.push_back(N);

    while(!dq.empty()){
        int now = dq.front();
        dq.pop_front();

        if(now==K){
            break;
        }

        for(int nx : {now-1, now+1, now*2}){
            if(0<=nx && nx<MAX && (arr[nx]==-1 || arr[nx] > arr[now]+1)){
                if(nx==now*2){
                    dq.push_front(nx);
                    arr[nx] = arr[now];
                }
                else{
                    dq.push_back(nx);
                    arr[nx] = arr[now] + 1;
                }
            }
        }
    }

    cout << arr[K] << '\n';

    return 0;
}