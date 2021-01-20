#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <queue>

using namespace std;
int R, C;
int Dy, Dx, Sy, Sx;
vector<string> board;
vector<pair<int, int>> waterCoords;
int result;
bool visited[51][51];
bool Wvisited[51][51];

bool flag = false;
int dy[4] = {-1, 1, 0, 0} , dx[4] = {0, 0, -1, 1};

bool safe(int y, int x) {
    return (0<=y && y<R) && (0<=x && x<C);
}

void bfs() {
    int cnt = 0;
    queue<pair<int, int>> hedgehog;
    queue<pair<int, int>> water;
    
    visited[Sy][Sx] = true;
    hedgehog.push(make_pair(Sy, Sx));
    for(int i=0; i<waterCoords.size(); i++) { 
        water.push(make_pair(waterCoords[i].first, waterCoords[i].second));
        Wvisited[waterCoords[i].first][waterCoords[i].second] = true;
    }
    
    while(!hedgehog.empty()) {
        int Hqs = hedgehog.size();
        int Wqs = water.size();
        
        for(int i=0; i<Wqs; i++) {
            int y = water.front().first;
            int x = water.front().second;
            water.pop();
            
            for(int j=0; j<4; j++) {
                int ny = y + dy[j], nx = x + dx[j];
                if(safe(ny, nx) && !Wvisited[ny][nx] && !visited[ny][nx] && board[ny][nx]=='.') {
                    Wvisited[ny][nx] = true;
                    board[ny][nx] = '*';
                    water.push(make_pair(ny, nx));
                }
            }
        }
        
        for(int i=0; i<Hqs; i++) {
            int y = hedgehog.front().first;
            int x = hedgehog.front().second;
            hedgehog.pop();
            
            if(y == Dy && x == Dx) {
                flag = true;
                result = cnt;
                return;
            }
            
            for(int j=0; j<4; j++) {
                int ny = y + dy[j], nx = x + dx[j];
                if(safe(ny, nx) && !visited[ny][nx] && board[ny][nx]!='*' && board[ny][nx]!='X') {
                    visited[ny][nx] = true;
                    hedgehog.push(make_pair(ny, nx));
                }
            }
        }
        
        cnt++;
    }
    return ;
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    cin >> R >> C;
    board.resize(R);
    
    for(int i=0; i<R; i++) cin >> board[i];
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            if(board[i][j] == 'D') {
                Dy = i;
                Dx = j;
            } else if(board[i][j] == 'S') {
                Sy = i;
                Sx = j;
            } else if(board[i][j] == '*') {
                waterCoords.push_back(make_pair(i, j));
            }
        }
    }
    
    bfs();
    if(flag) cout << result;
    else cout << "KAKTUS";
    return 0;
}