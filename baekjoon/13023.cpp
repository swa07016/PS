#include <iostream>
#include <vector>

using namespace std;
int n, m;

void dfs(int curr, vector<vector<int>>& v, vector<bool>& visited, int cnt) {
    if(cnt == 4) {
        cout << "1";
        exit(0);
        return;
    }

    for(int i=0; i<v[curr].size(); i++) {
        int next = v[curr][i];
        if(!visited[next]) {
            visited[next] = true;
            dfs(next, v, visited, cnt+1);
            visited[next] = false;
        }
    }
    
    return;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    vector<vector<int>> v(n);    
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=0; i<n-1; i++) {
        vector<bool> visited(n, false);
        visited[i] = true;
        dfs(i, v, visited, 0);
    }
    cout << "0";
    return 0;
}