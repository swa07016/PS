#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
int n;
vector<string> board;
int dy[2] = { 0, 1 }, dx[2] = { 1, 0 };
int ans = 1;

bool safe(int y, int x) {
    return (0<=y && y<n) && (0<=x && x<n); 
}

/*
    특정 위치의 사탕을 기준으로
    행의 길이를 계산해줌
*/
int goRight(int y, int x) {
    int len = 1, key = board[y][x];
    for(int i=x+1; i<n; i++) {
        if(board[y][i]==key 
        && board[y][i]==board[y][i-1]) len++;
        else return len;
    }
    
    return len;
}

/*
    특정 위치의 사탕을 기준으로
    열의 길이를 계산해줌
*/
int goBottom(int y, int x) {
    int len = 1, key = board[y][x];
    for(int i=y+1; i<n; i++) {
        if(board[i][x]==key 
        && board[i][x]==board[i-1][x]) len++;
        else return len;
    }
    
    return len;
}


/*
    특정 위치의 사탕을 기준으로 
    행과 열의 길이를 계산해서
    최댓값을 갱신해준다.
*/
void calculateMax() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            ans = max(ans, goRight(i, j));
            ans = max(ans, goBottom(i, j));
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    cin >> n;
    board.resize(n);
    for(int i=0; i<n; i++) cin >> board[i];
    
    /*
        인접한 두 사탕이 다른 경우 위치를 바꿔서
        최댓값을 갱신해준다.
    */
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            for(int k=0; k<2; k++) {
                int ny = i + dy[k],
                    nx = j + dx[k];
                if(safe(ny, nx) && board[i][j] != board[ny][nx]) {
                    swap(board[i][j], board[ny][nx]);
                    calculateMax();
                    swap(board[i][j], board[ny][nx]);
                }
            }
        }
    }
    cout << ans;

    return 0;
}
