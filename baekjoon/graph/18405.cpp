#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;
int board[210][210];
int n, k;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, -1, 0, 1};
int s, x, y;
vector<pair<int, int> > virus; // y, x
bool visited[210][210];

bool safe(int a, int b) {
    return (0<=a && a<n) && (0<=b && b<n);
}

// ex. 1이 1초인 상황 2가 1초인상황이 채워지고 그다음 1이 2초인상황이 채워지고 2가 2초인상황이 채워지도록
void bfs() {
    queue<pair<pair<int, int>, int > > q;

    for(int i=0; i<virus.size(); i++) { 
        int a = virus[i].first;
        int b = virus[i].second;
        int curr = board[a][b];
    
        visited[a][b] = true;
        q.push(make_pair(make_pair(a, b), 0));
    }

    

    while(!q.empty()) {
        int cy = q.front().first.first;
        int cx = q.front().first.second;
        int dist = q.front().second;
        q.pop();

        if(dist + 1 > s) continue;

        for(int i=0; i<4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if(safe(ny, nx) && !visited[ny][nx] && (board[ny][nx] == 0 )) { //  
                board[ny][nx] = board[cy][cx];
                visited[ny][nx] = true;
                q.push(make_pair(make_pair(ny, nx), dist+1));
            }
        }

    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> k;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) cin >> board[i][j];
    }
    cin >> s >> x >> y;

    for(int i=1; i<=k; i++) {
        for(int j=0; j<n; j++) {
            for(int l=0; l<n; l++) {
                if(board[j][l] == i) {
                    virus.push_back(make_pair(j, l));
                }
            }
        }
    }

    bfs();

    cout << board[x-1][y-1];

    return 0;
}