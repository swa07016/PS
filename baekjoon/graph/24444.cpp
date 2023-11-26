#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
vector<vector<int> > v;
bool visited[100010];
int seq[100010];
int n, m, r;

void bfs() {
    queue<int> q;
    q.push(r);
    visited[r] = true;
    int s = 1;

    while(!q.empty()) {
        int x = q.front();
        seq[x] = s++;
        q.pop();

        for(int i=0; i<v[x].size(); i++) {
            int nx = v[x][i];
            if(!visited[nx]) {
                q.push(nx);
                visited[nx] = true;
            }
        }
    }
    for(int i=1; i<=n; i++) {
        cout << seq[i] << "\n";
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m >> r;
    v.resize(n+1);    

    int a, b;
    for(int i=0; i<m; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for(int i=1; i<=n; i++) {
        sort(v[i].begin(), v[i].end());
    }

    bfs();

    return 0;
}