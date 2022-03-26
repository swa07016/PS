#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m;
int x, y;
bool visited[110];

void dfs(int curr, int cnt, vector<vector<int>>& v) {
    if(curr == y) {
        cout << cnt;
        exit(0);
    }
    for(int i=0; i<v[curr].size(); i++) {
        int next = v[curr][i];
        if(!visited[next]) {
            visited[next] = true;
            dfs(next, cnt+1, v);
            visited[next] = false;
        }
    }
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n;
    cin >> x >> y;
    cin >> m;
    vector<vector<int>> v(n+1);
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    visited[x] = true;
    dfs(x, 0, v);
    cout << "-1";
    return 0;
}
