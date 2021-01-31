#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>
#include <utility>

using namespace std;
int n;
vector<vector<int>> board;
bool visited[101][101];
int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, -1, 0, 1};
int result = INT_MAX;

bool safe(int y, int x) {
    return (0<=y && y<n) && (0<=x && x<n);
}

void dfs(int y, int x, int islandNum) {
    visited[y][x] = true;
    board[y][x] = islandNum;
    
    for(int i=0; i<4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(safe(ny, nx) && !visited[ny][nx] && board[ny][nx]) dfs(ny, nx, islandNum); 
    }

    return ;
}

int bfs(int sy, int sx, vector<vector<bool>>& visited2) {
    int islandNum = board[sy][sx];
    queue<pair<int, int>> q;
    q.push(make_pair(sy, sx));
    visited2[sy][sx] = true;
    
    int cnt = 0;
    while(!q.empty()) {
        int qs = q.size();
        for(int i=0; i<qs; i++) {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();
            
            if(board[y][x] && board[y][x]!=islandNum) {
                return --cnt;
            }
            
            for(int i=0; i<4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(safe(ny, nx) && board[ny][nx]!=islandNum && !visited2[ny][nx]) {
                    visited2[ny][nx] = true;
                    q.push(make_pair(ny, nx));
                }
            }
        }
        cnt++;
    }
    
    return cnt;
}

bool check(int y, int x) {
    if(!board[y][x]) return false;
    for(int i=0; i<4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(safe(ny, nx) && !board[ny][nx]) return true;
    }
    return false;
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n;
    board.resize(n);
    for(int i=0; i<n; i++) {
        board[i].resize(n);
        for(int j=0; j<n; j++) cin >> board[i][j];
    }
    int islandNum = 1;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(!visited[i][j] && board[i][j]) dfs(i, j, islandNum++);
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(check(i, j)) {
                vector<vector<bool>> visited2(n, vector<bool>(n, false));
                int ret = bfs(i, j, visited2);
                result = min(result, ret);
            }
        }
    }
    cout << result;
    return 0;
}
