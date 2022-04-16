#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;
int n, m;
vector<vector<int>> board;
int result;
int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, -1, 0, 1};
bool visited[1001][1001];

bool safe(int y, int x) {
    return (0<=y && y<n) && (0<=x && x<m);
}

void bfs() {
	queue <pair<int, int>> q;
	for(int i=0; i<n; i++) {
	    for(int j=0; j<m; j++) if(board[i][j] == 1) q.push(make_pair(i, j));
	}

	while (!q.empty()) {
		int qs = q.size();
		for (int i = 0; i < qs; i++) {
			int y = q.front().first;
			int x = q.front().second;
			visited[y][x] = true;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (safe(ny, nx) && !visited[ny][nx] && !board[ny][nx]) {
					q.push(make_pair(ny, nx));
					board[ny][nx] = 1;
				}
			}
		}
		result++;
	}
	
	result--;
	return ;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cin >> m >> n;
    board.resize(n);
    for(int i=0; i<n; i++) {
        board[i].resize(m);
        for(int j=0; j<m; j++) cin >> board[i][j];
    }
    bfs();
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) if(!board[i][j]) result = -1;
    }
    cout << result;
    return 0;
}
