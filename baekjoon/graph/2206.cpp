#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

class Node {
public:
    int y, x, length;
    bool isWallBroken;
    Node(int y, int x, int length, bool isWallBroken) : y(y), x(x), length(length), isWallBroken(isWallBroken) {}
};

int n, m;
vector<string> board;
queue<Node> q;
bool visited[2][1010][1010];
int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, -1, 0, 1};

bool safe(int y, int x) {
    return (0 <= y && y < n) && (0 <= x && x < m);
}

int bfs(int sy, int sx) {
    q.push(Node(sy, sx, 1, false));
    visited[0][sy][sx] = true;

    while(!q.empty()) {
        Node node = q.front();
        q.pop();

        if(node.y == n-1 && node.x == m-1) {
            return node.length;
        }

        for(int i=0; i<4; i++) {
            int ny = node.y + dy[i];
            int nx = node.x + dx[i];

            if(safe(ny, nx)) {
                if(board[ny][nx] == '0' && !visited[node.isWallBroken][ny][nx]) {
                    q.push(Node(ny, nx, node.length+1, node.isWallBroken));
                    visited[node.isWallBroken][ny][nx] = true;
                } else if(board[ny][nx] == '1' && !node.isWallBroken && !visited[1][ny][nx]) {
                    q.push(Node(ny, nx, node.length+1, true));
                    visited[1][ny][nx] = true;
                }
            }
        }
    }

    return -1;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    board.resize(n);
    for(int i=0; i<n; i++) cin >> board[i];

    int ans = bfs(0, 0);
    cout << ans;
    return 0;
}
