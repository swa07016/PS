#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m;
vector<vector<int>> board;
int max_v = -1;
bool visited[510][510];
int dy[4] = {-1, 0, 0, 1}, dx[4] = {0, -1, 1, 0};
int tetrominos[4][4][2] = {
    {{0, 0}, {0, 1}, {0, 2}, {1, 1}},
    {{0, 0}, {1, 0}, {2, 0}, {1, 1}},
    {{0, 0}, {0, 1}, {0, 2}, {-1, 1}},
    {{0, 0}, {-1, 1}, {0, 1}, {1, 1}},
};

bool safe(int y, int x) {
    return (0<=y && y<n) && (0<=x && x<m);
}

void tetro(int y, int x) {
    for(int i=0; i<4; i++) {
        int sum = 0, safe_cnt = 0;
        for(int j=0; j<4; j++) {
            int ny = y + tetrominos[i][j][0];
            int nx = x + tetrominos[i][j][1];
            if(safe(ny, nx)) {
                safe_cnt++;
                sum += board[ny][nx];
            }
        }
        if(safe_cnt == 4) max_v = max(max_v, sum); 
    }
    return ;
}

void dfs(int y, int x, int depth, int sum) {
    if(depth == 3) {
        max_v = max(max_v, sum);
        return ;
    }
    for(int i=0; i<4; i++) {
        int ny = y + dy[i], nx = x + dx[i];
        if(safe(ny, nx) && !visited[ny][nx]) {
            visited[ny][nx] = true;
            dfs(ny, nx, depth+1, sum+board[ny][nx]);
            visited[ny][nx] = false;
        }
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    board.resize(n);
    for(int i=0; i<n; i++) {
        board[i].resize(m);
        for(int j=0; j<m; j++) {
            cin >> board[i][j];
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            visited[i][j] = true;
            dfs(i, j, 0, board[i][j]);
            tetro(i, j);
            visited[i][j] = false;
        }
    }
    cout << max_v;
    return 0;
}