#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

class Point {
public:
    int y, x;
    Point(int y, int x) : y(y), x(x) {}
};

class Shark {
public:
    int y, x, size, needFish;
    Shark(int y, int x, int size, int needFish) : y(y), x(x), size(size), needFish(needFish) {}
    Shark() : y(0), x(0), size(0), needFish(0) {}
};

Shark shark = Shark();
int board[21][21];
int n;
int ans;
int dy[4] = {-1, 0, 1, 0}, 
    dx[4] = {0, -1, 0, 1};


bool safe(int y, int x) {
    return (0<=y && y<n) && (0<=x && x<n);
}

bool compare(Point& a, Point& b) {
    if(a.y == b.y) return a.x < b.x;
    return a.y < b.y;
}

pair<Point, int> findEatableFish() {
    bool visited[21][21] = { false };

    int sy = shark.y, sx = shark.x;
    queue<pair<Point, int> > q;
    q.push(make_pair(Point(sy, sx), 0));
    visited[sy][sx] = true;

    Point ret = Point(-1, -1);
    int minDist = 987654321;
    

    while(!q.empty()) {
        int y = q.front().first.y;
        int x = q.front().first.x;
        int depth = q.front().second;
        q.pop();

        if(board[y][x] >= 1 && board[y][x] < shark.size) {
            int dist = depth;
            if(dist < minDist) {
                minDist = dist;
                ret = Point(y, x);
            }
            if(dist == minDist) {
                if(ret.y > y) {
                    minDist = dist;
                    ret = Point(y, x);
                }
                if(ret.y == y) {
                    if(ret.x > x) {
                        minDist = dist;
                        ret = Point(y, x);
                    }
                } 
            }
        }
        
        for(int i=0; i<4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(safe(ny, nx) && !visited[ny][nx] && board[ny][nx] <= shark.size){
                q.push(make_pair(Point(ny, nx), depth+1));
                visited[ny][nx] = true;
            }
        }
    }

    return make_pair(ret, minDist);
}

void moveShark(Point p, int dist) {
    ans += dist;
    board[p.y][p.x] = 0;
    shark.y = p.y;
    shark.x = p.x;
    shark.needFish -= 1;
    if(shark.needFish == 0) {
        shark.size += 1;
        shark.needFish = shark.size;
    }
}

void solve() {
    while(true) {
        pair<Point, int > p = findEatableFish();
        if(p.first.y == -1 && p.first.x == -1) return ;
        moveShark(p.first, p.second);
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    for(int i=0; i<n; i++) 
        for(int j=0; j<n; j++) {
            cin >> board[i][j];
            if(board[i][j] == 9) {
                shark.y = i;
                shark.x = j;
                shark.size = 2;
                shark.needFish = 2;
                board[i][j] = 0; // 이거 꼭 해줘야 함.. 아니면 초기 상어 자리를 못 지나다님..
            }
        }
    
    solve();
    cout << ans;
    return 0;
}