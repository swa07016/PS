#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;
int n, m;
int board[51][51]; // board[y][x] : (0 : 청소되지 않은 칸), (1 : 벽), (-1 : 청소한 칸)
int r, c, d; 
int cy, cx, cd;
// d : (0 : 북), (1 : 동), (2 : 남), (3 : 서)
int ans;
// 동, 서, 남, 북 순서대로 배열 세팅
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

bool isDirty(int y, int x) {
    return board[y][x] == 0;
}

void clean(int y, int x) {
    board[y][x] = -1;
}

bool safe(int y, int x) {
    return (0 <= y && y < n) && (0 <= x && x < m);
}

bool isFourSpacesClean(int y, int x) {
    int cleanCount = 0;
    for(int i=0; i<4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(safe(ny, nx) && (board[ny][nx] == -1 || board[ny][nx] == 1)) cleanCount++;
    }
    return cleanCount == 4;
}

pair<int, int> getOppositePosition(int y, int x, int d) {
    int oppositeY, oppositeX;
    if(d == 0) { // 북이라면 남쪽으로 한칸 가봐야함
        oppositeY = y + dy[2];
        oppositeX = x + dx[2];
    }
    if(d == 1) { // 동쪽이면 서쪽으로 한칸 가봐야함
        oppositeY = y + dy[1];
        oppositeX = x + dx[1];
    }
    if(d == 2) { // 남쪽이면 북쪽으로 한칸 가봐야함
        oppositeY = y + dy[3];
        oppositeX = x + dx[3];
    }
    if(d == 3) { // 서쪽이면 동쪽으로 한칸 가봐야함.
        oppositeY = y + dy[0];
        oppositeX = x + dx[0];
    }

    return make_pair(oppositeY, oppositeX);
}

pair<int, int> getForwardPosition(int y, int x, int d) {
    int ny, nx;
    if(d == 0) { // 북이면 북으로 한칸더 가서 봄.
        ny = y + dy[3];
        nx = x + dx[3];
    }
    if(d == 1) { // 동쪽이면 동으로 한칸 더 가서 봄.
        ny = y + dy[0];
        nx = x + dx[0];
    }
    if(d == 2) { // 남쪽이면 남으로 한 칸 더 가서봄
        ny = y + dy[2];
        nx = x + dx[2];
    }
    if(d == 3) { // 서쪽이면 서로 한 칸 더 가서봄
        ny = y + dy[1];
        nx = x + dx[1];
    }

    return make_pair(ny, nx);
}

bool canReverse(int y, int x, int d) {
    pair<int, int> oppositePosition = getOppositePosition(y, x, d);

    int oppositeY = oppositePosition.first;
    int oppositeX = oppositePosition.second;

    if(safe(oppositeY, oppositeX) && board[oppositeY][oppositeX] != 1) return true;
    return false;
}

void executeReverse(int& y, int& x, int d) {
    pair<int, int> oppositePosition = getOppositePosition(y, x, d);

    int oppositeY = oppositePosition.first;
    int oppositeX = oppositePosition.second;

    y = oppositeY;
    x = oppositeX;

    return ;
}

void rotateRobot(int& d) {
    if(d == 0) { // 북이면 서로
        d = 3;
    }
    else if(d == 1) { // 동쪽이면 북으로
        d = 0;
    }
    else if(d == 2) { // 남쪽이면 동으로
        d = 1;
    }
    else if(d == 3) { // 서쪽이면 남으로 
        d = 2;
    }
}


bool isFrontSpaceCleaned(int y, int x, int d) {
    int ny, nx;
    pair<int, int> forwardPosition = getForwardPosition(y, x, d);
    ny = forwardPosition.first;
    nx = forwardPosition.second;
    
    if(safe(ny, nx) && board[ny][nx] == -1) return true;
    return false;
}

void goForward(int& y, int& x, int d) {
    int ny, nx;
    pair<int, int> forwardPosition = getForwardPosition(y, x, d);
    ny = forwardPosition.first;
    nx = forwardPosition.second;
    y = ny;
    x = nx;
    return ;
}

void solve() {
    
    // 현재 좌표 & 현재 보고있는 방향
    cy = r;
    cx = c;
    cd = d;


    while(true) {
        // 현재 칸이 아직 청소되지 않은 경우 청소한다.
        if(isDirty(cy, cx)) clean(cy, cx);

        // 4칸이 청소가 다 된 경우,
        if(isFourSpacesClean(cy, cx)) {
            // 후진이 가능하면 후진하고 1번으로 돌아간다.
            if(canReverse(cy, cx, cd)) {
                executeReverse(cy, cx, cd);
                continue;
            }

            // 후진이 불가능하다면 멈춘다. (종료조건)
            else break;
        }
            
        
        // 4칸 중 청소되지 않은 빈칸이 있는 경우
        else {
            // 반시계 방향으로 90도 회전한다. 
            rotateRobot(cd);
            // 바라보는 방향을 기준으로 앞쪽 칸이 청소되지 않은 빈 칸인 경우 한 칸 전진한다.
            if(!isFrontSpaceCleaned(cy, cx, cd)) {
                goForward(cy, cx, cd);
                // 1번으로 돌아간다.
                continue;
            }
        }
    }
        
}

void countClean() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++)
        if(board[i][j] == -1) ans++;
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    cin >> r >> c >> d;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++)
            cin >> board[i][j];
    }

    solve();
    countClean();
    cout << ans;

    return 0;
}