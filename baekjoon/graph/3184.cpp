#include <iostream>
#include <queue>
#include <string>
#include <utility>

using namespace std;
int r, c;
vector<string> board;
bool visited[260][260];
int wolf, sheep;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, -1, 0, 1};

bool isWall(int y, int x) {
    if(board[y][x] == '#') return true;
    return false;
}

bool isWolf(int y, int x) {
    if(board[y][x] == 'v') return true;
    return false;
}

bool isSheep(int y, int x) {
     if(board[y][x] == 'o') return true;
    return false;
}

bool safe(int a, int b) {
    return (0<=a && a <r) && (0<=b && b <c);
}

void bfs(int y, int x) {
    int localWolf = 0, localSheep = 0;

    queue<pair<int, int> > q;
    visited[y][x] = true;
    q.push(make_pair(y, x));

    while(!q.empty()) {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();

        if(isWolf(a, b)) localWolf++;
        if(isSheep(a, b)) localSheep++;

        for(int i=0; i<4; i++) {
            int ny = a + dy[i];
            int nx = b + dx[i];

            if(safe(ny, nx) && !visited[ny][nx] && !isWall(ny, nx)) {
                visited[ny][nx] = true;
                q.push(make_pair(ny, nx));
            }
        }

    }
    if(localWolf < localSheep) sheep += localSheep;
    else wolf += localWolf;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> r >> c;
    board.resize(r);
    
    for(int i=0; i<r; i++) cin >> board[i];
    
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            if(!visited[i][j] && !isWall(i, j)) {
                bfs(i, j);
            }
        }
    }

    cout << sheep << " " << wolf;
    return 0;
}