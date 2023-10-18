#include <iostream>
#include <vector>
#include <string>

using namespace std;
int n, m;
int pY, pX;
int ans;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, -1, 0, 1};
bool visited[601][601];

vector<string> board;

bool safe(int y, int x) {
    return (0 <= y && y<n) && (0<=x && x<m);
}

void solve(int y, int x) {
    
    if(board[y][x] == 'P') ans++;

    for(int i=0; i<4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(safe(ny, nx) && !visited[ny][nx] && board[ny][nx] != 'X') {
            visited[ny][nx] = true;
            solve(ny, nx);
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    board.resize(n);

    for(int i=0; i<n; i++) {
        cin >> board[i];
        for(int j=0; j<m; j++) {
            if(board[i][j] == 'I') {
                pY = i;
                pX = j;
            }
        }
    }

    visited[pY][pX] = true;
    solve(pY, pX);

    if(ans == 0) cout << "TT";
    else cout << ans;
    return 0;
}