#include <iostream>
#include <vector>
#include <string>

using namespace std;
int n, m;
int goalY, goalX;
vector<string> board;
int dy[4] = {0, 0, -1, 1}, dx[4] = {-1, 1, 0, 0};

bool safe(int y, int x) {
    return (0<=y && y<n) && (0<=x && x<m);
} 

void dfs(int y, int x, int key, vector<vector<bool>>& visited, int cnt) {
    for(int i=0; i<4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(safe(ny, nx) && cnt>=2 && ny == goalY && nx == goalX) {
            cout << "Yes";
            exit(0);
        }
        if(safe(ny, nx) && !visited[ny][nx] && board[ny][nx] == key) {
            visited[ny][nx] = true;
            dfs(ny, nx, key, visited, cnt+1);
        }
    }
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    board.resize(n);
    for(int i=0; i<n; i++) cin >> board[i];
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            goalY = i, goalX = j;
            vector<vector<bool>> visited(n, vector<bool>(m, false));
            visited[i][j] = true;
            dfs(i, j, board[i][j], visited, 0);
        }
    }
    cout << "No";
    return 0;
}