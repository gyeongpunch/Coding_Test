#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Block{
    int num;
    bool isAvail;
};

const int MAX_N = 20;
const int MAX_CNT = 5;

int N;
int arrOrigin[MAX_N][MAX_N];
int arr[MAX_N][MAX_N];
Block arrTmp[MAX_N][MAX_N];
vector<vector<int>> totalPermu;
vector<int> onePermu;
int result = 0;

void makePermu(int depth){
    if(depth == MAX_CNT){
        totalPermu.push_back(onePermu);

        // for(int a : onePermu){
        //     cout << a << ' ';
        // }
        // cout << '\n';

        return;
    }

    for(int i=0; i<4; i++){
        onePermu.push_back(i);

        makePermu(depth + 1);

        onePermu.pop_back();
    }
}

void init(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            arr[i][j] = arrOrigin[i][j];
        }
    }
}

void rotate(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            arrTmp[N-j-1][i].num = arr[i][j];
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            arr[i][j] = arrTmp[i][j].num;
        }
    }
}

void drop(){
    for(int j=0; j<N; j++){
        int nowI = N-1;
        for(int i=N-1; i>-1; i--){
            if(arrTmp[i][j].num == 0) continue;
            
            if(i != nowI){
                arrTmp[nowI][j].num = arrTmp[i][j].num;
                arrTmp[i][j].num = 0;
            }

            if(nowI == N-1){
                nowI--;
            }
            else if(!arrTmp[nowI + 1][j].isAvail || arrTmp[nowI + 1][j].num != arrTmp[nowI][j].num){
                nowI--;
            }
            else {
                arrTmp[nowI + 1][j].num *= 2;
                arrTmp[nowI + 1][j].isAvail = false;
                arrTmp[nowI][j].num = 0;
            }
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            arr[i][j] = arrTmp[i][j].num;
            arrTmp[i][j].isAvail = true;
        }
    }
}

int calc(){
    int mx = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            mx = max(mx, arr[i][j]);
        }
    }
    return mx;
}

void simulation(const vector<int> &cmds){
    init();

    for(const int &cmd : cmds){
        if(cmd == 0){
            for(int i=0; i<N; i++){
                for(int j=0; j<N; j++){
                    arrTmp[i][j].num = arr[i][j];
                    arrTmp[i][j].isAvail = true;
                }
            }

            drop();
            continue;
        }

        for(int i=0; i<cmd; i++){
            rotate();
        }
        drop();
        for(int i=0; i<4-cmd; i++){
            rotate();
        }
    }
    result = max(result, calc());
}

int main() {
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> arrOrigin[i][j];
        }
    }
    
    makePermu(0);

    for(const vector<int> &cmds : totalPermu){
        simulation(cmds);
    }

    cout << result << '\n';

    return 0;
}