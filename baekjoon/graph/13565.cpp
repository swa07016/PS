#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>

using namespace std;
int n, m;
vector<string> board;
bool visited[1010][1010];
bool isPossible = false;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, -1, 0, 1};

bool safe(int a, int b) {
    return (0<=a && a<n) && (0<=b && b<m);
}

void bfs(int a, int b) {
    queue<pair<int, int> > q;
    q.push(make_pair(a, b));
    visited[a][b] = true;

    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        if(y == n - 1 && board[y][x] == '0') {
            isPossible = true;
            break;
        }

        for(int i=0; i<4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(safe(ny, nx) && !visited[ny][nx] && board[ny][nx] == '0') {
                q.push(make_pair(ny, nx));
                visited[ny][nx] = true;
            }
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
    }

    for(int i=0; i<m; i++) {
        int y = 0;
        int x = i;

        if(!visited[y][x] && board[y][x] == '0') {
            bfs(y, x);
        }
    }

    if(isPossible) cout << "YES";
    else cout << "NO";

    return 0;
}