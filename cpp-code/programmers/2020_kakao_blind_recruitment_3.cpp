#include <string>
#include <vector>

using namespace std;

bool search(vector<vector<int>> key, vector<vector<int>> lock) {
    int m = key.size(), n = lock.size();
    int k = (m-1)*2 + n;
    for(int i=0; i<=n+m-2; i++) {
        for(int j=0; j<=n+m-2; j++) {
            vector<vector<int>> board(k, vector<int>(k));
            vector<vector<int>> check(k, vector<int>(k));
            int by = i;
            for(int a=0; a<m; a++) {
                int bx = j;
                for(int b=0; b<m; b++) board[by][bx++] = key[a][b];
                by++;
            }
            int cy = m-1;
            for(int a=0; a<n; a++) {
                int cx = m-1;
                for(int b=0; b<n; b++) check[cy][cx++] = lock[a][b];
                cy++;
            }
            int ty = m-1, tx = m-1;
            
            int chk=0;
            for(int a=ty; a<ty+n; a++) {
                for(int b=tx; b<tx+n; b++) {
                    if(check[a][b] && board[a][b]) chk++;
                    else if(!check[a][b] && !board[a][b]) chk++;
                }
            }
            if(!chk) return true;
        }
    }
    return false;
}

void rotateKey(vector<vector<int>>& key, int m) {
    vector<vector<int>> tmp(m, vector<int>(m));
    for(int i=0; i<m; i++) {
        for(int j=0; j<m; j++) {
            tmp[j][m-1-i] = key[i][j];
        }
    }
    key = tmp;
    return ;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    int m = key.size();
    for(int i=0; i<4; i++) {
        if(search(key, lock)) {
            answer = true;
            break;
        }
        rotateKey(key, m);
    }
    return answer;
}