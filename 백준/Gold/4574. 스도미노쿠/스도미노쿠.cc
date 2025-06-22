#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <cstring>

using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(nullptr);

struct Pair{
    int n1, n2;
};

struct Point{
    int x, y;
};

const int N = 9;

int M, n1, n2, test=1;
string p1, p2;
int arr[N][N];
int visited[36];
int mapIdx;
map<pair<int, int>, int> Map;
vector<Pair> pairVector;
Pair path;
bool resultFlag;
int vst1[N][N+1], vst2[N][N+1], vst3[N][N+1];

void dfs(int depth, int prev){
    if(depth==2){
        pairVector.push_back(path);
        Map[{path.n1, path.n2}] = mapIdx++;
        return;
    }

    for(int i=prev+1; i<=9; i++){
        if(depth==0) path.n1 = i;
        else path.n2 = i;
        dfs(depth + 1, i);
    }
}

Point get_first(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(arr[i][j] == 0) return {i, j};
        }
    }
    return {-1, -1};
}

bool bound_check(int x, int y){
    return 0<=x && x<N && 0<=y && y<N;
}

void init(){
    memset(arr, 0, sizeof(arr));
    memset(vst1, 0, sizeof(vst1));
    memset(vst2, 0, sizeof(vst2));
    memset(vst3, 0, sizeof(vst3));
    memset(visited, 0, sizeof(visited));
    resultFlag = false;
}

void arr_print(){
    cout << "Puzzle " << test++ << '\n';
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << arr[i][j];
        }
        cout << '\n';
    }
}

void get_result(int depth){
    if(resultFlag) return;

    // cout << depth << '\n';

    if(depth+M==36){
        arr_print();
        resultFlag = true;
        return;
    }

    Point start = get_first();
    if (start.x == -1) return;

    int x = start.x, y = start.y;
    int cube1 = x/3*3 + y/3;

    for(int i=0; i<36; i++){
        if(visited[i] == 1) continue;
        Pair now = pairVector[i];

        for(int j=0; j<4; j++){
            int nx = x, ny = y;
            int nn1 = now.n1, nn2 = now.n2;
            
            if (j == 0 || j == 2) ny++;
            else nx++;

            if(!bound_check(nx, ny)) continue;
            if(arr[nx][ny] != 0) continue;

            int cube2 = nx/3*3 + ny/3;
            if (j == 2 || j == 3) swap(nn1, nn2);

            if(vst1[x][nn1]==1 || vst2[y][nn1]==1 || vst3[cube1][nn1]==1) continue;
            if(vst1[nx][nn2]==1 || vst2[ny][nn2]==1 || vst3[cube2][nn2]==1) continue;
            
            vst1[x][nn1] = vst2[y][nn1] = vst3[cube1][nn1] = 1;
            vst1[nx][nn2] = vst2[ny][nn2] = vst3[cube2][nn2] = 1;
            arr[x][y] = nn1;
            arr[nx][ny] = nn2;
            int nnn1 = nn1;
            int nnn2 = nn2;
            if(nnn1 > nnn2) swap(nnn1, nnn2);
            visited[Map[{nnn1, nnn2}]] = 1;

            get_result(depth+1);

            vst1[x][nn1] = vst2[y][nn1] = vst3[cube1][nn1] = 0;
            vst1[nx][nn2] = vst2[ny][nn2] = vst3[cube2][nn2] = 0;
            arr[x][y] = 0;
            arr[nx][ny] = 0;
            visited[Map[{nnn1, nnn2}]] = 0;
        }
    }
}

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    dfs(0, 0);

    while(true){
        cin >> M;

        if(M==0) break;

        init();

        for(int i=0; i<M; i++){
            cin >> n1 >> p1 >> n2 >> p2;

            int x1 = (int)(p1[0]-'A');
            int y1 = (int)(p1[1]-'1');
            int cube1 = x1/3*3 + y1/3;
            vst1[x1][n1] = vst2[y1][n1] = vst3[cube1][n1] = 1;
            arr[x1][y1] = n1;

            int x2 = p2[0]-'A';
            int y2 = p2[1]-'1';
            int cube2 = x2/3*3 + y2/3;
            vst1[x2][n2] = vst2[y2][n2] = vst3[cube2][n2] = 1;
            arr[x2][y2] = n2;

            if(n1 > n2) swap(n1, n2);
            visited[Map[{n1, n2}]] = 1;
        }

        for(int i=1; i<=N; i++){
            cin >> p1;
            int x1 = p1[0]-'A';
            int y1 = p1[1]-'1';
            int cube1 = x1/3*3 + y1/3;
            vst1[x1][i] = vst2[y1][i] = vst3[cube1][i] = 1;
            arr[x1][y1] = i;
        }

        get_result(0);
    }

    return 0;
}