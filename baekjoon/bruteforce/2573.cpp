#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int n, m;
int board[310][310];
int board_update[310][310];
int ans;
int dist;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, -1, 0, 1};

bool safe(int a, int b) {
    return (0<=a && a< n) && (0<=b && b<m);
}

bool isFinish() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) 
            if(board[i][j] != 0) return false;
    }
    return true;
}

void setUpdateBoardElem(int y, int x) {
    int cnt = 0;
    for(int i=0; i<4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(!safe(ny, nx)) continue;
        if(board[ny][nx] == 0) cnt++;
    }
    
    board_update[y][x] = board[y][x] - cnt;
    if(board_update[y][x] < 0) board_update[y][x] = 0;
    
}

void copyBoardUpdateToBoard() {
    for(int i=0; i<n; i++) 
        for(int j=0; j<m; j++) 
            board[i][j] = board_update[i][j];
}

void updateBoard() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(board[i][j] != 0) setUpdateBoardElem(i, j);
        }
    }
    
    copyBoardUpdateToBoard();
}



int unionFind() {
    int cnt = 0;
    bool visited[310][310] = {false};

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(!visited[i][j] && board[i][j] != 0) {
                cnt++;

                queue<pair<int, int> > q;
                q.push(make_pair(i, j));
                visited[i][j] = true;
                // cout << "visited : " << i << " " << j << "\n";

                while(!q.empty()) {
                    int y = q.front().first;
                    int x = q.front().second;
                    q.pop();

                    for(int k=0; k<4; k++) {
                        int ny = y + dy[k];
                        int nx = x + dx[k];
                        if(safe(ny, nx) && !visited[ny][nx] && board[ny][nx] != 0) {
                           // cout << "visited : " << ny << " " << nx << "\n";
                            visited[ny][nx] = true;
                            q.push(make_pair(ny, nx));
                        }
                    }

                }

            }
        }
    }

   // cout << "union : " << cnt << "\n";

    return cnt;
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for(int i=0; i<n; i++) 
        for(int j=0; j<m; j++)
            cin >> board[i][j];

    while(!isFinish()) {
        if(unionFind() >= 2) {
            ans = dist;
            break;
        }

        updateBoard(); dist++;
    }
    

    cout << ans;
    return 0;
}
