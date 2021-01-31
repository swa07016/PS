#include <iostream>
#include <vector>
#include <set>

using namespace std;
int n;
vector<vector<int>> v;
vector<int> seq;
bool visited[100001];
int idx = 2;

int dfs(int x) {
    set<int> s;
    for(int i=0; i<v[x].size(); i++) {
        int t = v[x][i];
        if(!visited[t]) s.insert(t);
    }
    
    for(int i=0; i<s.size(); i++) {
        int key = seq[idx++];
        if(s.find(key) == s.end()) return 0;
        else if(!visited[key]) {
            visited[key] = true;
            dfs(key);
        }
    }
    return 1;
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n;
    v.resize(n+1);
    for(int i=0; i<n-1; i++) {
        
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    seq.resize(n+1);
    for(int i=1; i<=n; i++) cin >> seq[i];
    visited[1] = true;
    int ret = dfs(1);
    cout << ret; 
    return 0;
}
