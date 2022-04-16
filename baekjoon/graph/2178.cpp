#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <utility>

using namespace std;
vector<string> board;
queue<pair<int, int>> q;
int n, m;
bool visited[110][110];
int dy[4]  = { 0, 1, -1, 0 }, dx[4] = { 1, 0, 0, -1 };

bool safe(int y, int x ) {
    return (0<=y && y<n) && (0<=x && x<m);    
}

/*
    bfs로 최소 거리를 구한다.
*/
int bfs() {
    int cnt = 1;
    visited[0][0] = true;
    q.push({ 0, 0 });
    
    while(!q.empty()) {
        int qs = q.size();
        for(int i=0; i<qs; i++) {
            int y = q.front().first, x = q.front().second; q.pop();
            if(y == n - 1 && x == m - 1) return cnt;
            for(int j=0; j<4; j++) {
                int ny = y + dy[j], nx = x + dx[j];
                if(safe(ny, nx) && !visited[ny][nx] && board[ny][nx] == '1') {
                    visited[ny][nx] = true;
                    q.push({ny, nx});    
                }    
            } 
        }
        cnt++;
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    	
    cin >> n >> m;
    board.resize(n);
    for(int i=0; i<n; i++) cin >> board[i];
    
    cout << bfs();
    
	return 0;
}
