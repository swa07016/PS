#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;
int n, m, h;
int board[101][101][101];
int result;
int dy[6] = {0, 0, -1, 0, 1, 0}, dx[6] = {0, 0, 0, -1, 0, 1};
int dz[6] = {-1, 1, 0, 0, 0, 0};
bool visited[101][101][101];

bool safe(int z, int y, int x) {
    return (0<=z && z<h) && (0<=y && y<n) && (0<=x && x<m);
}

void bfs() {
	queue <vector<int>> q;
    for(int i=0; i<h; i++) {
        for(int j=0; j<n; j++) {
            for(int k=0; k<m; k++) {
                if(board[i][j][k]==1) {
                    vector<int> tmp;
                    tmp.push_back(i);
                    tmp.push_back(j);
                    tmp.push_back(k);
                    q.push(tmp);
                }
            }
        }
    }

	while (!q.empty()) {
		int qs = q.size();
		for (int i = 0; i < qs; i++) {
		    int z = q.front()[0];
			int y = q.front()[1];
			int x = q.front()[2];
			visited[z][y][x] = true;
			q.pop();
			for (int i = 0; i < 6; i++) {
			    int nz = z + dz[i];
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (safe(nz, ny, nx) && !visited[nz][ny][nx] && !board[nz][ny][nx]) {
					vector<int> tmp;
                    tmp.push_back(nz);
                    tmp.push_back(ny);
                    tmp.push_back(nx);
					q.push(tmp);
					board[nz][ny][nx] = 1;
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
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> m >> n >> h;
    for(int i=0; i<h; i++) {
        for(int j=0; j<n; j++) {
            for(int k=0; k<m; k++) cin >> board[i][j][k]; 
        }
    }
    bfs();
    for(int i=0; i<h; i++) {
        for(int j=0; j<n; j++) {
            for(int k=0; k<m; k++) if(!board[i][j][k]) result = -1;
        }
    }
    cout << result;
    return 0;
}
