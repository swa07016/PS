#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;
vector<vector<char>> board;
set<string> nums;
int result;
int dy[4] = {-1, 0, 0, 1}, dx[4] = {0, -1, 1, 0};

bool safe(int y, int x) {
    return (0<=y && y<5) && (0<=x && x<5);
}

void dfs(int y, int x, int depth,vector<char>& num) {
    if(depth == 6) {
        string tmp = "";
        for(int i=0; i<6; i++) tmp += num[i];
        if(nums.find(tmp)==nums.end()) { 
            nums.insert(tmp);
        }
        return;
    }
    for(int i=0; i<4; i++) {
        int ny = y + dy[i], nx = x + dx[i];
        if(safe(ny, nx)) {
            num.push_back(board[ny][nx]);
            dfs(ny, nx, depth+1, num);
            num.pop_back();
        }
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    board.resize(5);
    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            char tmp;
            cin >> tmp;
            board[i].push_back(tmp);
        }
    }
    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            vector<char> num;
            dfs(i, j, 0, num);
        }
    }
    cout << nums.size();
    return 0;
}