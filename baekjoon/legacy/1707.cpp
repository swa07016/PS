#include <iostream>
#include <vector>
#include <string>

using namespace std;
int k;

void dfs(int current, vector<vector<int>>& v, vector<int>& visited) {
    for(int i=0; i<v[current].size(); i++) {
        int next = v[current][i];
        if(!visited[next]) {
            if(visited[current] == 1) visited[next] = 2;
            if(visited[current] == 2) visited[next] = 1;
            dfs(next, v, visited);
        }
    }
    return ;
}

string check(vector<vector<int>>& v, vector<int>& visited, int V) {
    for(int i=1; i<=V; i++) {
        int currentColor = visited[i];
        for(int j=0; j<v[i].size(); j++) {
            int next = v[i][j];
            if(visited[next] == currentColor) return "NO\n";
        }
    }
    return "YES\n";
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> k;
    for(int i=0; i<k; i++) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> v(V+1);
        vector<int> visited(V+1, 0);
        for(int i=0; i<E; i++) {
            int a, b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        for(int i=1; i<=V; i++) {
            if(!visited[i]) {
                visited[i] = 1;
                dfs(i, v, visited);
            }
        }
        string ret = check(v, visited, V);
        cout << ret;
    }
    return 0;
}