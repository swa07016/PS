#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <climits>

using namespace std;
vector<vector<int>> office;
vector<pair<int, int>> cctvPositions;
vector<int> cctvTypes;
int n, m;
int cctvCnt;
int result = INT_MAX;
string checkDirection[6][4] = {
    {"", "", "", ""},
    {"r", "l", "u", "d"},
    {"rl", "ud", "", ""},
    {"ur", "rd", "dl", "lu"},
    {"lur", "urd", "rdl", "dlu"},
    {"rldu", "", "", ""}
};

void findCctv() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(1<=office[i][j] && office[i][j]<=5) {
                cctvCnt++;
                cctvPositions.push_back(make_pair(i, j));
                cctvTypes.push_back(office[i][j]);
            }
        }
    }
    return ;
}

bool safe(int y, int x) {
    return (0<=y && y<n) && (0<=x && x<m);
}

void go(vector<vector<int>>& board, int y, int x, char type) {
    if(!safe(y, x) || board[y][x] == 6) return ;
    if(!board[y][x]) board[y][x] = -3;
    if(type == 'r') go(board, y, x+1, type);
    if(type == 'l') go(board, y, x-1, type);
    if(type == 'u') go(board, y-1, x, type);
    if(type == 'd') go(board, y+1, x, type);
}

void fillBoard(vector<vector<int>>& board, int y, int x, string type) {
    if(type.find("r")!=string::npos) go(board, y, x, 'r');
    if(type.find("l")!=string::npos) go(board, y, x, 'l');
    if(type.find("u")!=string::npos) go(board, y, x, 'u');
    if(type.find("d")!=string::npos) go(board, y, x, 'd');
    return ;
}

int countBlindSpot(vector<vector<int>>& board) {
    int cnt = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m ; j++) {
            if(!board[i][j]) cnt++;
        }
    }
    return cnt;
}

void dfs(vector<int>& v, int depth) {
    if(depth == cctvCnt) {
        vector<vector<int>> testBoard = office;
        for(int i=0; i<cctvCnt; i++) {
            int y = cctvPositions[i].first;
            int x = cctvPositions[i].second;
            string type = checkDirection[cctvTypes[i]][v[i]];
            if(type == "") continue;
            fillBoard(testBoard, y, x, type);
            int ret = countBlindSpot(testBoard);
            result = min(ret, result);
        }
        return ;
    }
    for(int i=0; i<=3; i++) {
        v.push_back(i);
        dfs(v, depth+1);
        v.pop_back();
    }
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    office.resize(n);
    for(int i=0; i<n; i++) {
        office[i].resize(m);
        for(int j=0; j<m; j++) cin >> office[i][j];
    }
    findCctv();
    vector<int> v;
    dfs(v, 0);
    if(cctvCnt == 0) result = countBlindSpot(office);
    cout << result;
    return 0;
}
