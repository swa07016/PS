#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <utility>

using namespace std;
vector<string> board;
int n, m, result=-1;
int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, -1, 0, 1};

bool safe(int y, int x) {
    return (0<=y && y<n) && (0<=x && x<m);
}

int bfs(int sy, int sx, vector<vector<bool>> visited) {
    queue<pair<int, int>> q;
    q.push(make_pair(sy, sx));
    visited[sy][sx] = true;
    int dist = -1;
    while(!q.empty()) {
        dist++;
        int qs = q.size();
        for(int i=0; i<qs; i++) {
           int y = q.front().first;
           int x = q.front().second;
           q.pop();
           
           for(int j=0; j<4; j++) {
               int ny = y + dy[j];
               int nx = x + dx[j];
               if(safe(ny, nx) && board[ny][nx] == 'L' && !visited[ny][nx]) {
                   q.push(make_pair(ny, nx));
                   visited[ny][nx] = true;
               }
           }
        }
    }
    return dist;
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    board.resize(n);
    for(int i=0; i<n; i++) {
        cin >> board[i];
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(board[i][j] == 'L') {
                vector<vector<bool>> v(n, vector<bool>(m, false));
                result = max(bfs(i, j, v), result);
            }
        }
    }
    cout << result;
    return 0;
}
