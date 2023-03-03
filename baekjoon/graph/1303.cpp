#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>

using namespace std;

vector<string> board;
int n, m;
bool visited[110][110];
int W, B;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };

bool safe(int a, int b) {
    return (0<=a && a<n) && (0<=b && b<m);
}

void bfs(int a, int b, char type) {
    int cnt = 1;
    queue<pair<int, int> > q;
    visited[a][b] = true;
    q.push(make_pair(a, b));

    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(safe(ny, nx) && !visited[ny][nx] && board[ny][nx] == type) {
                q.push(make_pair(ny, nx));
                visited[ny][nx] = true;
                cnt++;
            }
        }
    }

    if(type == 'W') W += cnt*cnt;
    if(type == 'B') B += cnt*cnt;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> m >> n;
    board.resize(n);

    for(int i=0; i<n; i++) cin >> board[i];

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(!visited[i][j] && board[i][j] == 'W') bfs(i, j, 'W');
            if(!visited[i][j] && board[i][j] == 'B') bfs(i, j, 'B');
        }
    }

    cout << W << " " << B;
    return 0;
}