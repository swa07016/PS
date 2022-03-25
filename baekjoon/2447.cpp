#include <iostream>
#include <vector>

using namespace std;
int n;
vector<vector<char>> board;

void fill(int y, int x, int size) {
    if(size == 1) {
        board[y][x] = '*'; 
        return ;
    } 
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(i==1 && j==1) continue;
            int ny = y + (size/3)*i;
            int nx = x + (size/3)*j;
            fill(ny, nx, size/3);
        }
    }
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n;
    board.resize(n);
    for(int i=0; i<n; i++) {
        board[i].resize(n);
        for(int j=0; j<n; j++) board[i][j] = ' ';
    }
    fill(0, 0, n);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) cout << board[i][j];
        cout << "\n";
    }
    return 0;
}