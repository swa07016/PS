#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <utility>

using namespace std;
int n, m, k;
vector<vector<int>> board;
vector<pair<int, int>> coords;
vector<int> sArr;
int result = INT_MAX;

int calc(vector<vector<int>>& copy) {
    int ret = INT_MAX;
    for(int i=1; i<copy.size(); i++) {
        int sum=0;
        for(int j=1; j<copy[i].size(); j++) sum += copy[i][j];
        ret = min(ret, sum);
    }
    return ret;
}

void rotateBoard(vector<int>& v) {
    vector<vector<int>> tmp = board;
    vector<vector<int>> copy = board;
    for(int i=0; i<v.size(); i++) {
        int idx = v[i];
        int r = coords[idx].first, c = coords[idx].second, s = sArr[idx];
        while(s) {
            int sy = r-s, sx = c-s;
            int ey = r+s, ex = c+s;
            for(int j=sx+1; j<=ex; j++) copy[sy][j] = tmp[sy][j-1];
            for(int j=sy+1; j<=ey; j++) copy[j][ex] = tmp[j-1][ex];
            for(int j=ex-1; j>=sx; j--) copy[ey][j] = tmp[ey][j+1];
            for(int j=ey-1; j>=sy; j--) copy[j][sx] = tmp[j+1][sx];
            s--;
        }
        tmp = copy;
    }
    result = min(result, calc(copy));
} 

void solve(vector<int>& v, int depth, vector<bool>& visited) {
    if(depth == k) {
        rotateBoard(v);
        return ;
    }
    for(int i=0; i<k; i++) {
      if(!visited[i]) {
          visited[i] = true;
          v.push_back(i);
          solve(v, depth+1, visited);
          visited[i] = false;
          v.pop_back();
      }  
    }
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    board.resize(n+1);
    for(int i=1; i<=n; i++) {
        board[i].resize(m+1);
        for(int j=1; j<=m; j++) cin >> board[i][j];
    }
    for(int i=0; i<k; i++) {
        int r, c, s;
        cin >> r >> c >> s;
        coords.push_back(make_pair(r, c));
        sArr.push_back(s);
    }
    vector<int> v;
    vector<bool> visited(k, false);
    solve(v, 0, visited);
    cout << result;
    return 0;
}
