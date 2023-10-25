#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>


using namespace std;
int L, R, C; // 층, 행, 열
int df[6] = {0, 0, 0, 0, 1, -1};
int dy[6] = {-1, 0, 1, 0, 0, 0};
int dx[6] = {0, 1, 0, -1, 0, 0};

class Position {
public:
    int floor, y, x;
    Position(int floor, int y, int x) {
        this->floor = floor;
        this->y = y;
        this->x = x;
    }
    Position() {}
};

bool isExit(Position end, int f, int y, int x) {
    return end.floor == f && end.y == y && end.x == x;
}

bool safe(int f, int y, int x) {
    return (0<= f && f<L) && (0<=y && y<R) && (0<=x && x<C);
}

int bfsBoard(vector<vector<string> > board, Position start, Position end) {
    bool visited[31][31][31] = {false};

    queue<pair<Position, int > > q;
    q.push(make_pair(start, 0));
    visited[start.floor][start.y][start.x] = true;
    
    while(!q.empty()) {
        int f = q.front().first.floor;
        int y = q.front().first.y;
        int x = q.front().first.x;
        int m = q.front().second;

        q.pop();

        if(isExit(end, f, y, x)) {
            return m;
        }

        for(int i=0; i<6; i++) {
            int nf = f + df[i];
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(safe(nf, ny, nx) && board[nf][ny][nx] != '#' && !visited[nf][ny][nx]) {
                q.push(make_pair(Position(nf, ny, nx), m+1));
                visited[nf][ny][nx] = true;
            }
        }

    }

    return 0;
}

// 6593
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    while(true) {
        cin >> L >> R >> C;
        if(L == 0 && R == 0 && C == 0) break;
        
        vector<vector<string> > board;
        Position start, end;

        for(int i=0; i<L; i++) { // 층
            vector<string> temp(R);
            
            for(int j=0; j<R; j++) { // 행 
                cin >> temp[j];  
                
                // START와 END 찾기
                for(int k=0; k<C; k++) { // 열
                    if(temp[j][k] == 'S') start = Position(i, j, k);
                    if(temp[j][k] == 'E') end = Position(i, j, k);
                }
            }
            board.push_back(temp);

            
        }

        int minutes = bfsBoard(board, start, end);
        if(minutes >= 1) cout << "Escaped in " <<  minutes << " minute(s)." << "\n";
        else cout << "Trapped!" << "\n";

    }

    return 0;
}