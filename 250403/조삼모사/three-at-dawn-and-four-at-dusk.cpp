#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define MAX_N 20

int N;
int arr[MAX_N][MAX_N];
vector<vector<int>> totalComb;
vector<int> path;
int visited[MAX_N];
int result = 1e9;

void get_min_value(){
    for(const vector<int> oneComb : totalComb){
        memset(visited, 0, sizeof(visited));
        int sumA = 0, sumB = 0;

        for(int i=0; i<N/2; i++){   
            visited[oneComb[i]] = 1;
            for(int j=i+1; j<N/2; j++){
                sumA += arr[oneComb[i]][oneComb[j]] + arr[oneComb[j]][oneComb[i]];
            }
        }

        vector<int> rest;
        for(int i=0; i<N; i++){
            if(visited[i] == 0) rest.push_back(i);
        }

        for(int i=0; i<N/2; i++){
            for(int j=i+1; j<N/2; j++){
                sumB += arr[rest[i]][rest[j]] + arr[rest[j]][rest[i]];
            }
        }

        result = min(result, abs(sumA - sumB));
    }
}

void makeComb(int depth, int prev){
    if(depth == N/2){
        totalComb.push_back(path);
        return;
    }

    for(int i=prev+1; i<N; i++){
        path.push_back(i);

        makeComb(depth + 1, i);

        path.pop_back();
    }
}

int main() {
    
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> arr[i][j];
        }
    }

    makeComb(0, -1);

    get_min_value();

    cout << result << '\n';
    
    return 0;
}