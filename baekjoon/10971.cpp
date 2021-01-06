#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
vector<vector<int>> W;
int result=987654321;

void dfs(int first, int current, vector<int>& visited, int cnt, int cost) {
    if(cnt == n) {
        if(W[current][first]) result = min(result, cost + W[current][first]);
        return ;
    }
    for(int i=1; i<=n; i++) {
        if(W[current][i] && !visited[i]) {
            visited[i] = true;
            dfs(first, i, visited, cnt+1, cost+W[current][i]);
            visited[i] = false;
        }
    }
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n;
    W.resize(n+1);
    for(int i=1; i<=n; i++) {
        W[i].resize(n+1);
        for(int j=1; j<=n; j++) cin >> W[i][j];
    }
    for(int i=1; i<=n; i++) {
        vector<int> visited(n+1, false);
        visited[i] = true;
        dfs(i, i, visited, 1, 0);
    }
    cout << result;
    return 0;
}
