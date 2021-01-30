#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int n;
vector<vector<int>> v;
bool chk;

void dfs(int curr, int key, vector<bool>& visited, int cnt) {
    for(int i=0; i<v[curr].size(); i++) {
        int next = v[curr][i];
        if(cnt>=2 && next == key) {
            chk = true;
            return ;
        }
        else if(!visited[next]) {
            visited[next] = true;
            dfs(next, key, visited, cnt+1);
            visited[next] = false;
        }
    }
}

int bfs(int curr, vector<bool>& visited, vector<int>& dist) {
    queue<int> q;
    int cnt = 0;
    q.push(curr);
    visited[curr] = true;
    
    while(!q.empty()) {
        int qs = q.size();
        for(int i=0; i<qs; i++) {
            int x = q.front();
            q.pop();
            if(!dist[x]) {
                return cnt;
            }
            
            for(int i=0; i<v[x].size(); i++) {
                int next = v[x][i];
                if(!visited[next]) {
                    visited[next] = true;
                    q.push(next);
                } 
            }
        }
        cnt++;
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    v.resize(n+1);
    for(int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    vector<int> dist(n+1, -1);    
    for(int i=1; i<=n; i++) {
        chk = false;
        vector<bool> visited(n+1, false);
        visited[i] = true;
        dfs(i, i, visited, 0);
        if(chk) dist[i] = 0;
    }
    
    for(int i=1; i<=n; i++) {
        vector<bool> visited(n+1);
        visited[i] = true;
        if(dist[i] == -1) {
            int d = bfs(i, visited, dist);
            dist[i] = d;
        }
    }
    
    for(int i=1; i<=n; i++) cout << dist[i] << " ";
    return 0;
}