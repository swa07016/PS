#include <bits/stdc++.h>

using namespace std;
int n, m, cnt;
int max_v = -1;
int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
bool visited[10][10];

bool safe(int a, int b) {
    return (0<=a && a<n) && (0<=b && b<m);
}

void dfs(int a, int b, vector<vector<int>> matrix) {
    visited[a][b] = true;
    cnt++;
    for(int i=0; i<8; i++) {
        int ny = a + dy[i];
        int nx = b + dx[i];
        if(safe(ny, nx) && matrix[ny][nx] && !visited[ny][nx]) dfs(ny, nx, matrix);
    }
    return;
}

// Complete the connectedCell function below.
int connectedCell(vector<vector<int>> matrix) {
    n = matrix.size();
    m = matrix[0].size();
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(matrix[i][j] && !visited[i][j]) {
                cnt = 0;
                dfs(i, j, matrix);
                if(cnt > max_v) {
                    max_v = cnt;
                }
            }
        }
    }
    return max_v;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int m;
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> matrix(n);
    for (int i = 0; i < n; i++) {
        matrix[i].resize(m);

        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = connectedCell(matrix);

    fout << result << "\n";

    fout.close();

    return 0;
}
