#include <iostream>
#include <vector>

using namespace std;
int cnt_one, cnt_m_one, cnt_zero;
vector<vector<int>> board;

int check(int y, int x, int distance) {
    int chk[3] = {0};
    if(distance == 1) return board[y][x];
    for(int i=y; i<y+distance; i++) {
        for(int j=x; j<x+distance; j++) chk[board[i][j]+1]++;
    }
    if(chk[0]==distance*distance) return -1;
    if(chk[1]==distance*distance) return 0;
    if(chk[2]==distance*distance) return 1;
    return -2;
}

void solve(int y, int x, int distance) {
    int ret = check(y, x, distance);
    if(ret!=-2) {
        if(ret == -1) cnt_m_one++;
        if(ret == 0) cnt_zero++;
        if(ret == 1) cnt_one++;
        return ;
    }
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            int ny = y + (distance/3)*i;
            int nx = x + (distance/3)*j;
            solve(ny, nx, distance/3);
        }
    }
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    board.resize(n);
    for(int i=0; i<n; i++) {
        board[i].resize(n);
        for(int j=0; j<n; j++) cin >> board[i][j];
    }
    solve(0, 0, n);
    cout << cnt_m_one << "\n" << cnt_zero << "\n" << cnt_one;
    return 0;
}