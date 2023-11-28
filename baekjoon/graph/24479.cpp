#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<vector<int> > v;
int n, m, r;
int a, b;
bool visited[100010];
int s = 1;
int seq[100010];

void dfs(int x) {

    for(int i=0; i<v[x].size(); i++) {
        int nx = v[x][i];
        if(!visited[nx]) {
            visited[nx] = true;
            seq[nx] = s++;
            dfs(nx);
        }
    }
}

bool compare(int a, int b) {
    return a > b;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m >> r;
    v.resize(n+1);
    for(int i=0; i<m; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for(int i=1; i<=n; i++) {
        sort(v[i].begin(), v[i].end(), compare);
    }

    visited[r] = true;
    seq[r] = s++;
    dfs(r);

    for(int i=1; i<=n; i++) {
        cout << seq[i] << "\n";
    }

    return 0;
}