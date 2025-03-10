#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <cstring>

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(nullptr);

using namespace std;

struct BaseBall{
    int nowPlayer;
    int out;
    int inning;
    int state[3];
    int score;
};

const int MAX_N = 50;
const int PYR = 9;

int N;
int arr[MAX_N][PYR];
vector<vector<int>> totalPermu;
vector<int> player;
int visited[PYR];

BaseBall baseball;

void inningInit(){
    baseball.out = 0;
    memset(baseball.state, 0, sizeof(baseball.state));
}

void totalInit(){
    baseball.out = 0;
    memset(baseball.state, 0, sizeof(baseball.state));
    baseball.inning = 0;
    baseball.nowPlayer = 0;
    baseball.score = 0;
}

void makePermu(int depth, vector<int> &player){
    if(depth == PYR){
        totalPermu.push_back(player);
        return;
    }

    if(depth == 3){
        visited[0] = 1;
        player.push_back(0);
        
        makePermu(depth + 1, player);

        visited[0] = 0;
        player.pop_back();
    }

    else{
        for(int i=1; i<PYR; i++){
            if(visited[i] == 0){
                visited[i] = 1;
                player.push_back(i);
                
                makePermu(depth + 1, player);

                visited[i] = 0;
                player.pop_back();
            }
        }
    }

    
}

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<PYR; j++){
            cin >> arr[i][j];
        }
    }

    makePermu(0, player);

    int result = 0;
    for(const vector<int> &permu : totalPermu){
        totalInit();
        int idx = 0;
        baseball.nowPlayer = permu[idx];
        
        while(baseball.inning < N){
            while(baseball.out < 3){
                if(arr[baseball.inning][baseball.nowPlayer] == 1){
                    baseball.score += baseball.state[2];
                    baseball.state[2] = baseball.state[1];
                    baseball.state[1] = baseball.state[0];
                    baseball.state[0] = 1;
                }

                else if(arr[baseball.inning][baseball.nowPlayer] == 2){
                    baseball.score += baseball.state[2] + baseball.state[1];
                    baseball.state[2] = baseball.state[0];
                    baseball.state[1] = 1;
                    baseball.state[0] = 0;
                }

                else if(arr[baseball.inning][baseball.nowPlayer] == 3){
                    for(int i=0; i<3; i++){
                        baseball.score += baseball.state[i];
                        baseball.state[i] = 0;
                    }
                    baseball.state[2] = 1;
                }

                else if(arr[baseball.inning][baseball.nowPlayer] == 4){
                    for(int i=0; i<3; i++){
                        baseball.score += baseball.state[i];
                        baseball.state[i] = 0;
                    }
                    baseball.score++;
                }

                else if (arr[baseball.inning][baseball.nowPlayer] == 0){
                    baseball.out++;
                }
                baseball.nowPlayer = permu[(++idx) % PYR];
            }

            
            baseball.inning++;
            inningInit();
        }
        result = max(result, baseball.score);
    }
    
    cout << result << '\n';

    return 0;
}