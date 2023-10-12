#include <iostream>

using namespace std;

int board[1010][1010];
int rowMax[1010][1010];
int colMax[1010][1010];
int n, m;
long long int total, ans;


// 14754
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for(int i=0; i<n; i++) 
        for(int j=0; j<m; j++) {
            cin >> board[i][j];
            total += board[i][j];
        }
            

    for(int i=0; i<n; i++) {
        int maxV = -1;
        int py, px;
        for(int j=0; j<m; j++) {
            if(board[i][j] > maxV) {
                maxV = board[i][j];
                py = i;
                px = j;
            }
        }
        rowMax[py][px] = maxV;
    }

    for(int i=0; i<m; i++) {
        int maxV = -1;
        int py, px;
        for(int j=0; j<n; j++) {
            if(board[j][i] > maxV) {
                maxV = board[j][i];
                py = j;
                px = i;
            }
        }
        colMax[py][px] = maxV;
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            // cout << rowMax[i][j] << " ";
            if(rowMax[i][j] && colMax[i][j]) ans += board[i][j];
            else if(rowMax[i][j]) ans += board[i][j];
            else if(colMax[i][j]) ans += board[i][j];
        }
        // cout << "\n";
    }

    cout << total - ans;

    return 0;
}         