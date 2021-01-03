#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
int n, m;
vector<string> board;
int result = -1;

bool safe(int y, int x) {
    return (0<=y && y<n) && (0<=x && x<m);
}

int check(int y, int x) {
    int area = 1;
    int key = board[y][x];
    int ny = y, nx = x;
    while(1) {
        if(!safe(ny, nx)) break;
        if(board[ny][nx] == key) {
            if(board[y][nx] == key && board[ny][x] == key) area = (ny-y+1)*(ny-y+1);
        }
        ny++;
        nx++;
    }
    return area;
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    board.resize(n);
    for(int i=0; i<n; i++) {
        cin >> board[i];
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            result = max(check(i, j), result);
        }
    }
    cout << result;
    return 0;
}
