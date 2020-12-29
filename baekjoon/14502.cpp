#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m;
int dy[4] = {-1, 0, 0, 1}, dx[4] = {0, -1, 1, 0};
bool visited[10][10];
int result = -1;

void init_v() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) visited[i][j] = false;
    }
    return;
}

bool safe(int y, int x) {
    return (0<=y && y<n) && (0<=x && x<m);
}

void dfs(int y, int x, vector<vector<int>>& v) {
    visited[y][x] = true;
    v[y][x] = 2;
    for(int i=0; i<4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(safe(ny, nx) && !visited[ny][nx] && !v[ny][nx]) {
            dfs(ny, nx, v);
        } 
    }
}

int count(vector<vector<int>>& v) {
    int cnt = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) if(!v[i][j]) cnt++;
    }
    return cnt;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    vector<vector<int>> original(n);
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            int tmp;
            cin >> tmp;
            original[i].push_back(tmp);
        }
    }
    for(int i=0; i<n*m-2; i++) {
        for(int j=i+1; j<n*m-1; j++) {
            for(int k=j+1; k<n*m; k++) {
                if(!original[i/m][i%m] && !original[j/m][j%m] && !original[k/m][k%m]) {
                    vector<vector<int>> copy = original;
                    copy[i/m][i%m] = copy[j/m][j%m] = copy[k/m][k%m] = 1;
                    
                    for(int l=0; l<n; l++) {
                        for(int a=0; a<m; a++) {
                            if(copy[l][a] == 2 && !visited[l][a]) dfs(l, a, copy);
                        }
                    }
                    
                    result = max(count(copy), result);   
                    init_v();
                }
            }
        }
    }
    cout << result;
    return 0;
}