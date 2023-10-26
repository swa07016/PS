#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

int T, R, C;
string board[1010];
bool visited[1010][1010];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, -1, 0, 1};

class Position {
public:
    int y, x;
    Position() {};
    Position(int y, int x) : y(y), x(x) {};
};

// 주어진 좌표가 테두리에 있는지 확인하는 함수
bool isBorder(Position p) {
    return p.y == 0 || p.y == R-1 || p.x == 0 || p.x == C-1;
}

// 주어진 좌표가 안전한 범위 내에 있는지 확인하는 함수
bool safe(Position p) {
    return p.y >= 0 && p.y < R && p.x >= 0 && p.x < C;
}

int solve() {
    // 불과 지훈이의 움직임을 각각 처리하기 위한 큐
    queue<pair<Position, int> > q_fire;
    queue<pair<Position, int> > q_jihun;

    // 초기 위치 설정
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            if(board[i][j] == '@') {
                q_jihun.push(make_pair(Position(i, j), 0));
                visited[i][j] = true;
            } else if(board[i][j] == '*') {
                q_fire.push(make_pair(Position(i, j), 0));
            }
        }
    }


    while(!q_jihun.empty()) {
        // 불 확산 처리
        int size_fire = q_fire.size();
        for(int i = 0; i < size_fire; i++) {
            Position current = q_fire.front().first;
            q_fire.pop();

            for(int dir=0; dir<4; dir++) {
                Position next(current.y + dy[dir], current.x + dx[dir]);

                // 빈 칸이면 불 확산
                if(safe(next) && board[next.y][next.x] == '.') {
                    board[next.y][next.x] = 'F';
                    q_fire.push(make_pair(next, 0));
                }
            }
        }

        // 지훈이의 움직임 처리
        int size_jihun = q_jihun.size();
        for(int i = 0; i < size_jihun; i++) {
            Position current = q_jihun.front().first;
            int time = q_jihun.front().second;
            q_jihun.pop();

            // 테두리에 도달하면 탈출
            if(isBorder(current)) {
                return time + 1;
            }

            for(int dir=0; dir<4; dir++) {
                Position next(current.y + dy[dir], current.x + dx[dir]);

                // 안전하고 방문하지 않은 빈 칸으로 이동
                if(safe(next) && board[next.y][next.x] == '.' && !visited[next.y][next.x]) {
                    visited[next.y][next.x] = true;
                    q_jihun.push(make_pair(next, time + 1));
                }
            }
        }
    }

    return -1;
}

void initVisited() {
    for(int i=0; i<R; i++) 
        for(int j=0; j<C; j++) 
            visited[i][j] = false;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> T;
    for(int t=0; t<T; t++) {
        cin >> C >> R;
        for(int i=0; i<R; i++) {
            cin >> board[i];
        }

        int result = solve();
        if(result == -1) cout << "IMPOSSIBLE\n";
        else cout << result << "\n";
        initVisited();
    }

   

    return 0;
}
