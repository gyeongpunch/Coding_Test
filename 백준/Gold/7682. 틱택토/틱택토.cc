#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <cstring>

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(nullptr);

using namespace std;

#define SZ 3

struct Bingo{
    int xB[8];
    int oB[8];
};

char arr[SZ][SZ];
Bingo bingo;

void get_bingo(){
    memset(bingo.xB, 0, sizeof(bingo.xB));
    memset(bingo.oB, 0, sizeof(bingo.oB));

    for(int i=0; i<SZ; i++){
        if('X' == arr[i][0] && arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2]) bingo.xB[i] = 1;
        if('X' == arr[0][i] && arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i]) bingo.xB[i + SZ] = 1;
        
        if('O' == arr[i][0] && arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2]) bingo.oB[i] = 1;
        if('O' == arr[0][i] && arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i]) bingo.oB[i + SZ] = 1;
    }

    if('X' == arr[0][0] && arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2]) bingo.xB[6] = 1;
    if('X' == arr[0][2] && arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0]) bingo.xB[7] = 1;
    
    if('O' == arr[0][0] && arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2]) bingo.oB[6] = 1;
    if('O' == arr[0][2] && arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0]) bingo.oB[7] = 1;
}

string get_result(const int &X, const int &O){
    get_bingo();

    int xbCnt = 0, obCnt = 0;

    for(int i=0; i<8; i++){
        xbCnt += bingo.xB[i];
        obCnt += bingo.oB[i];
    }
    
    if(xbCnt > 0){
        if(X != O + 1) return "invalid"; 
    }
    else if (obCnt > 0){
        if(X != O) return "invalid";
    }
    
    if(xbCnt > 0 && obCnt > 0) return "invalid";
    
    else if(xbCnt == 0 && obCnt == 0) {
        if(X+O == 9) return "valid";
        else return "invalid";
    }
    else {
        if(xbCnt > 0){
            if(bingo.xB[0] + bingo.xB[1] + bingo.xB[2] > 2) return "invalid";
            else if(bingo.xB[3] + bingo.xB[4] + bingo.xB[5] > 2) return "invalid";
            return "valid";
        }
        else if (obCnt > 0){
            if(X > O) return "invalid";

            if(bingo.oB[0] + bingo.oB[1] + bingo.oB[2] > 2) return "invalid";
            else if(bingo.oB[3] + bingo.oB[4] + bingo.oB[5] > 2) return "invalid";
            return "valid";
        }
    }
    return "valid";
}

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    string b, result;
    int xCnt, oCnt;
    while(true){
        cin >> b;

        if(b == "end"){
            break;
        }
        
        xCnt = 0;
        oCnt = 0;
        for(int i=0; i<SZ; i++){
            for(int j=0; j<SZ; j++){
                arr[i][j] = b[i*SZ + j];

                if(arr[i][j] == 'X') xCnt++;
                else if(arr[i][j] == 'O') oCnt++;
            }
        }

        // X는 O보다 항상 같거나 1만큼만 커야합니다.
        if(xCnt-oCnt < 0 || 1 < xCnt-oCnt){
            result = "invalid";
        }
        else{
            result = get_result(xCnt, oCnt);
        }
        cout << result << '\n';
    }

    return 0;
}