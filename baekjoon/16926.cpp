#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> board;
int n, m, r;

void printBoard(vector<vector<int>>& v) {
    for(int i=0; i<v.size(); i++) {
        for(int j=0; j<v[i].size(); j++) cout << v[i][j] << " ";
        cout << "\n";
    }
    return ;
}

void rotateBoard() {
    vector<vector<int>> tmp = board;
    vector<vector<int>> copy = board;
    int s = r;
    for(int i=0; i<r; i++) {
        int sy = 0, sx = 0;
        int ey = n-1, ex = m-1;
        while(1) {
            if((ey<=sy) || (ex<=sx)) break;
            for(int j=ex-1; j>=sx; j--) copy[sy][j] = tmp[sy][j+1];
            for(int j=sy+1; j<=ey; j++) copy[j][sx] = tmp[j-1][sx];
            for(int j=sx+1; j<=ex; j++) copy[ey][j] = tmp[ey][j-1];
            for(int j=ey-1; j>=sy; j--) copy[j][ex] = tmp[j+1][ex];
            sy++; sx++; ey--; ex--;
        } 
        tmp = copy;
    }
    printBoard(copy);
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n >> m >> r;
    board.resize(n);
    for(int i=0; i<n; i++) {
        board[i].resize(m);
        for(int j=0; j<m; j++) cin >> board[i][j];
    }
    rotateBoard();
    return 0;
}