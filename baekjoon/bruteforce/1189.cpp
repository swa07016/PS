#include <iostream>
#include <string>

using namespace std;

int r, c, k;
string board[5];
bool visited[5][5];
int ans = 0;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, -1, 0, 1};

bool safe(int y, int x) {
    return (0 <= y && y < r) && (0 <= x && x < c);
}

void dfs(int y, int x, int dist) {
    if (y == 0 && x == c - 1) {
        if (dist == k) ans++;
        return;
    }

    visited[y][x] = true;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (safe(ny, nx) && !visited[ny][nx] && board[ny][nx] != 'T') {
            dfs(ny, nx, dist + 1);
        }
    }

    visited[y][x] = false;  // 백트래킹: 방문 기록 취소
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> r >> c >> k;

    for (int i = 0; i < r; i++) {
        cin >> board[i];
    }

    dfs(r - 1, 0, 1);  // 시작 위치 (왼쪽 하단)에서 시작

    cout << ans << "\n";

    return 0;
}
