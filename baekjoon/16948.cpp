#include <iostream>
#include <queue>
#include <utility>

using namespace std;
int n;
int r1, c1, r2, c2;
int result = -1;
int dy[6] = {-2, -2, 0, 0, 2, 2};
int dx[6] = {-1, 1, -2, 2, -1, 1};
bool visited[201][201];

bool safe(int y, int x) {
    return (0<=y && y<n) && (0<=x && x<n);
}

void bfs() {
    queue<pair<int, int>> q;
    q.push(make_pair(r1, c1));
    visited[r1][c1] = true;
    int cnt = 0;
    while(!q.empty()) {
        int qs = q.size();
        for(int i=0; i<qs; i++) {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();
            if(y == r2 && x == c2) {
                result = cnt;
                return ;
            }
            for(int i=0; i<6; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(safe(ny, nx) && !visited[ny][nx]){ 
                    q.push(make_pair(ny, nx));
                    visited[ny][nx] = true;
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
    cin >> n;
    cin >> r1 >> c1 >> r2 >> c2;
    bfs();
    cout << result;
    return 0;
}
