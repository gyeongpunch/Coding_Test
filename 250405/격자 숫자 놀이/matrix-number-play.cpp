#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define MAX_SZ 100

struct Info{
    int n, cnt;
};

int r, c, k;
int arr[MAX_SZ][MAX_SZ];
int arrTmp[MAX_SZ][MAX_SZ];
int result = -1;
int rows, cols;
Info tmp[MAX_SZ + 1];

bool custom_compare(Info a, Info b){
    if(a.cnt == b.cnt) return a.n < b.n;
    return a.cnt < b.cnt;
}

void rowSort(){
    int newcolCnt = 0;
    memset(arrTmp, 0, sizeof(arrTmp));
    for(int i=0; i<rows; i++){
        memset(tmp, 0, sizeof(tmp));

        int length = 0;
        for(int j=0; j<cols; j++){
            if(arr[i][j] == 0) continue;

            if(tmp[arr[i][j]].n == arr[i][j]){
                tmp[arr[i][j]].cnt++;
            }
            else{
                tmp[arr[i][j]] = {arr[i][j], 1};
                length++;
            }
        }

        vector<Info> ttmp;

        for(int j=0; j<MAX_SZ; j++){
            if(tmp[j].cnt > 0){
                ttmp.push_back(tmp[j]);
            }
        }

        // for(int i=0; i<30; i++){
        //     cout << tmp[i].n << ' ' << tmp[i].cnt << '\n';
        // }
        // cout << "!!!!!\n";

        sort(ttmp.begin(), ttmp.end(), custom_compare);
        for(int j=0; j<min(length, 50); j++){

            arrTmp[i][j*2] = ttmp[j].n;
            arrTmp[i][j*2+1] = ttmp[j].cnt;
        }
        newcolCnt = max(newcolCnt, length * 2);
    }
    cols = newcolCnt;
    for(int i=0; i<MAX_SZ; i++){
        for(int j=0; j<MAX_SZ; j++){
            arr[i][j] = arrTmp[i][j];
        }
    }
}

void colSort(){
    int newrowCnt = 0;
    memset(arrTmp, 0, sizeof(arrTmp));
    for(int i=0; i<cols; i++){
        memset(tmp, 0, sizeof(tmp));

        int length = 0;
        for(int j=0; j<rows; j++){
            if(arr[j][i] == 0) continue;

            if(tmp[arr[j][i]].n == arr[j][i]){
                tmp[arr[j][i]].cnt++;
            }
            else{
                tmp[arr[j][i]] = {arr[j][i], 1};
                length++;
            }
        }

        // for(int i=0; i<30; i++){
        //     cout << tmp[i].n << ' ' << tmp[i].cnt << '\n';
        // }
        // cout << "!!!!!\n";

        vector<Info> ttmp;

        for(int j=0; j<MAX_SZ; j++){
            if(tmp[j].cnt > 0){
                ttmp.push_back(tmp[j]);
            }
        }

        sort(ttmp.begin(), ttmp.end(), custom_compare);
        for(int j=0; j<min(length, 50); j++){
            arrTmp[j*2][i] = ttmp[j].n;
            arrTmp[j*2+1][i] = ttmp[j].cnt;
        }
        newrowCnt = max(newrowCnt, length * 2);
    }
    rows = newrowCnt;
    for(int i=0; i<MAX_SZ; i++){
        for(int j=0; j<MAX_SZ; j++){
            arr[i][j] = arrTmp[i][j];
        }
    }
}

void pprint(){
    cout << "======================\n";
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << "======================\n";
}

void simulation(){
    if(rows >= cols){
        rowSort();
        // pprint();
    }
    else{
        colSort();
    }
}

int main() {
    fastio;

    cin >> r >> c >> k;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cin >> arr[i][j];
        }
    }
    rows = 3;
    cols = 3;

    if(arr[r-1][c-1] == k){
        cout << "0\n";
        return 0;
    }


    for(int i=1; i<=100; i++){
        simulation();

        // pprint();
        if(arr[r-1][c-1] == k){
            result = i;
            break;
        }
    }

    cout << result << '\n';

    return 0;
}