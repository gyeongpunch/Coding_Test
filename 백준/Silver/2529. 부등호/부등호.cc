#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <cstring>

using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(nullptr);

const int MX=10;

int K;
char op[MX];
vector<int> path;
vector<string> all_numbers;
int visited[10];

void get_all_nums(int depth){
    if(depth == K+1){
        string str = "";
        for(int n : path){
            str = str + (char)('0' + n);
        }
        all_numbers.push_back(str);
        return;
    }

    for(int i=0; i<10; i++){
        if(depth == 0){
            path.push_back(i);
            visited[i] = 1;

            get_all_nums(depth+1);

            path.pop_back();
            visited[i] = 0;
        }
        else{
            if(visited[i] == 0){
                if((op[depth-1] == '<' && path[depth-1] < i) || (op[depth-1] == '>' && path[depth-1] > i)){
                    path.push_back(i);
                    visited[i] = 1;

                    get_all_nums(depth+1);

                    path.pop_back();
                    visited[i] = 0;
                }
            }
        }
    }
}

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    cin >> K;
    for(int i=0; i<K; i++){
        cin >> op[i];
    }

    get_all_nums(0);

    sort(all_numbers.begin(), all_numbers.end());

    cout << all_numbers[all_numbers.size()-1] << '\n' << all_numbers[0] << '\n';

    return 0;
}