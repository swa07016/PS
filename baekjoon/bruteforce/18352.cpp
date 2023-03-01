#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;
int n, m, k, x;
queue<pair<int, int> > q; // vertex, distance
bool visited[300010];
vector<int> ans;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m >> k >> x;

    vector<vector<int> > v(n+1);

    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
    }

    q.push(make_pair(x, 0));
    visited[x] = true;

    while(!q.empty()) {
        int x = q.front().first;
        int dist = q.front().second;
        q.pop();

        if(dist == k) {
            ans.push_back(x);
        }

        for(int i=0; i<v[x].size(); i++) {
            int nx = v[x][i];

            if(!visited[nx]) {
                q.push(make_pair(nx, dist+1));
                visited[nx] = true;
            }
        }
    }

    if(ans.size() == 0) cout << "-1";
    else {
        sort(ans.begin(), ans.end());
        for(int i=0; i<ans.size(); i++) cout << ans[i] << "\n";
    }

    return 0;
}