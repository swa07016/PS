#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;
int t, n;
int sy, sx, ey, ex;
int result;
int dy[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dx[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
bool visited[301][301];

void init_v() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) visited[i][j] = false;
    }
}

bool safe(int y, int x) {
    return (0<=y && y<n) && (0<=x && x<n);
}

void bfs() {
    queue<pair<int, int>> q;
    q.push(make_pair(sy, sx));
    visited[sy][sx] = true;
    
    while(!q.empty()) {
        int qs = q.size();
        for(int i=0; i<qs; i++) {
            int y = q.front().first;
            int x = q.front().second;
            
            q.pop();
            if(y == ey && x == ex) return;
            
            for(int j=0; j<8; j++) {
                int ny = y + dy[j];
                int nx = x + dx[j];
                if(safe(ny, nx) && !visited[ny][nx]) {
                    q.push(make_pair(ny, nx));
                    visited[ny][nx] = true;
                }
            }
        }
        result++;
    }
    return ;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> t;
    for(int i=0; i<t; i++) {
        cin >> n;
        cin >> sy >> sx;
        cin >> ey >> ex;
        
        bfs();
        
        cout << result << "\n";
        
        result = 0;
        init_v();
    }
    return 0;
}