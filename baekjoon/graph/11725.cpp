#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<vector<int> > tree;
int n;
int a, b;
bool visited[100010];
int parent[100010];

void solve() {
    // parent, me
    queue<pair<int, int> > q;

    visited[1] = true;
    q.push(make_pair(1, 1));

    while (!q.empty()) 
    {
        int p = q.front().first;
        int me = q.front().second;
        parent[me] = p;
        q.pop();

        for(int i=0; i<tree[me].size(); i++) {
            int next = tree[me][i];

            if(!visited[next]) {
                visited[next] = true;
                q.push(make_pair(me, next));
            }
        }
    }
    

}

int main() {    
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    tree.resize(n+1);
    for(int i=0; i<n-1; i++) {
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    solve();

    for(int i=2; i<=n; i++) {
        cout << parent[i] << "\n";
    }

    return 0;
}