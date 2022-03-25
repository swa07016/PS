#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;
int n, m;
vector<vector<int>> board;
int dy[4] = {0, 0, -1, 1}, dx[4] = {-1, 1, 0, 0};
int result;
bool visited[101][101];

bool safe(int y, int x) {
    return (0<=y && y<n) && (0<=x && x<m);
}

void bfs() {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
    q.push(make_pair(0, make_pair(0, 0)));
    visited[0][0] = true;
    
    while(!q.empty()) {
        int wallCnt = q.top().first;
        int y = q.top().second.first;
        int x = q.top().second.second;
        q.pop();
    
        if(y == n-1 && x == m-1) {
            result = wallCnt;
            return ;
        }
        
        for(int i=0; i<4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(safe(ny, nx) && !visited[ny][nx]) {
                visited[ny][nx] = true;
                int tmpCnt = wallCnt;
                if(board[ny][nx]) tmpCnt = wallCnt+1;
                q.push(make_pair(tmpCnt, make_pair(ny, nx)));
            }
        }
    
    }
    
    return ;
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    cin >> m >> n;
    vector<string> tmp(n);
    for(int i=0; i<n; i++) cin >> tmp[i];
    board.resize(n);
    for(int i=0; i<n; i++) {
        board[i].resize(m);
        for(int j=0; j<m; j++) board[i][j] = (tmp[i][j] - '0');
    }
    
    bfs();
    cout << result;
    return 0;
}