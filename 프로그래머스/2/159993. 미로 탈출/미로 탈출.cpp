#include <string>
#include <vector>
#include <queue>

using namespace std;

int N, M;

pair<int, int> find_index(vector<string> maps, char target){
    for(int i=0; i < N; i++){
        int y = maps[i].find(target);
        if(y!=string::npos){
            return make_pair(i, y);
        }
    }
}

int bfs(vector<string> maps, char start, char end){
    vector<vector<int>> visited(N, vector<int>(M, -1));
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    
    pair<int, int> pos = find_index(maps, start);
    queue<pair<int, int>> q;
    q.push(pos);
    visited[pos.first][pos.second] = 0;
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        if(maps[x][y] == end){
            return visited[x][y];
        }
        for(int i=0; i<4; i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if (0<=nx && nx<N && 0<=ny && ny<M && maps[nx][ny]!='X' && visited[nx][ny]==-1){
                q.push(make_pair(nx, ny));
                visited[nx][ny] = visited[x][y] + 1;
            }
        }
    }
    return -1;
}

int solution(vector<string> maps) {
    N = maps.size();
    M = maps[0].size();
    
    int time1 = bfs(maps, 'S', 'L');
    int time2 = bfs(maps, 'L', 'E');
    if(time1==-1 || time2==-1){
        return -1;
    }
    return time1 + time2;
}