#include <iostream>
#include <queue>
#include <string>

using namespace std;

int board[17][17];
int n;
int ans;


class Point {
public:
    int y;
    int x;
    Point(int y, int x) {
        this->y = y;
        this->x = x;
    };
    Point() {}
};

class Node {
public:
    Point head;
    string direction;
    Node(Point p, string d) {
        this->head = p;
        this->direction = d;
    }
};

bool safe(int y, int x) {
    return y >= 0 && y < n && x >= 0 && x < n;
}

bool isNotWall(int y, int x) {
    return board[y][x] != 1;
}

// 기존의 makeHorizontalPaths 함수 수정
// 우측 이동: (nY, nX + 1)으로 이동 가능 여부 체크
// 대각선 이동: (nY + 1, nX + 1)로 이동 가능 여부 체크
void makeHorizontalPaths(queue<Node>& q, int headY, int headX) {
    int nY, nX;

    // 우측으로 이동
    nY = headY;
    nX = headX + 1; // 수정된 부분

    if(safe(nY, nX) && isNotWall(nY, nX)) q.push(Node(Point(nY, nX), "HORIZONTAL"));

    // 대각방향으로 이동
    nY = headY + 1;
    nX = headX + 1;

    if(safe(nY, nX) && isNotWall(nY, nX) && isNotWall(headY + 1, headX) && isNotWall(headY, headX + 1)) 
        q.push(Node(Point(nY, nX), "DIAGONAL"));
}



void makeDiagonalPaths(queue<Node>& q, int headY, int headX) {
    int nY, nX;

    // 우측 이동
    nY = headY;
    nX = headX + 1;
    if (safe(nY, nX) && isNotWall(nY, nX)) {
        q.push(Node(Point(nY, nX), "HORIZONTAL"));
    }

    // 아래로 이동
    nY = headY + 1;
    nX = headX;
    if (safe(nY, nX) && isNotWall(nY, nX)) {
        q.push(Node(Point(nY, nX), "VERTICAL"));
    }

    // 대각선 이동
    nY = headY + 1;
    nX = headX + 1;
    if (safe(nY, nX) && isNotWall(nY, nX) && isNotWall(headY + 1, headX) && isNotWall(headY, headX + 1)) {
        q.push(Node(Point(nY, nX), "DIAGONAL"));
    }
}

void makeVerticalPaths(queue<Node>& q, int headY, int headX) {
    int nY, nX;

    // 아래로 이동
    nY = headY + 1;
    nX = headX;
    if (safe(nY, nX) && isNotWall(nY, nX)) {
        q.push(Node(Point(nY, nX), "VERTICAL"));
    }

    // 대각선 이동
    nY = headY + 1;
    nX = headX + 1;
    if (safe(nY, nX) && isNotWall(nY, nX) && isNotWall(headY, headX + 1) && isNotWall(headY + 1, headX)) {
        q.push(Node(Point(nY, nX), "DIAGONAL"));
    }
}

void solve() {
    queue<Node> q;
    q.push(Node(Point(0, 1), "HORIZONTAL")); // 수정된 부분: 초기 위치 설정

    while(!q.empty()) {
        int headY = q.front().head.y;
        int headX = q.front().head.x;
        string direction = q.front().direction;
        q.pop();

        if(headY == n - 1 && headX == n - 1) { // 목적지에 도달했을 때
            ans++;
            continue;
        }

        if(direction == "HORIZONTAL") makeHorizontalPaths(q, headY, headX);
        if(direction == "DIAGONAL") makeDiagonalPaths(q, headY, headX);
        if(direction == "VERTICAL") makeVerticalPaths(q, headY, headX);
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) 
            cin >> board[i][j];
    }

    solve();

    cout << ans;

    return 0;
}