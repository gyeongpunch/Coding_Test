#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <cstring>

using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(nullptr);

int L, C;
vector<char> totalAlpha;
int visited[15];
vector<char> path;
vector<string> totalResult;
unordered_set<char> moTotal = {'a', 'e', 'i', 'o', 'u'};

void get_result(int ja, int mo, int depth, int prev){
    if(depth==L && ja >= 2 && mo >= 1){
        string str = "";
        for(char c : path){
            str = str + c;
        }
        totalResult.push_back(str);
        return;
    }

    for(int i=prev+1; i<C; i++){
        if(visited[i] == 1) continue;

        path.push_back(totalAlpha[i]);
        visited[i] = 1;
        
        if(moTotal.find(totalAlpha[i]) == moTotal.end()){
            get_result(ja+1, mo, depth+1, i);
        }
        else{
            get_result(ja, mo+1, depth+1, i);
        }

        path.pop_back();
        visited[i] = 0;
    }
}

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    cin >> L >> C;
    char c;
    

    for(int i=0; i<C; i++){
        cin >> c;
        totalAlpha.push_back(c);
    }

    sort(totalAlpha.begin(), totalAlpha.end());

    get_result(0, 0, 0, -1);

    for(string s : totalResult){
        cout << s << '\n';
    }

    return 0;
}