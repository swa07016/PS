#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;
int n;
vector<vector<int>> v;
vector<int> seq;
bool visited[100001];

int bfs() {
    queue<int> q;
    q.push(1);
    visited[1] = true;
    int idx = 2;
    
    while(!q.empty()) {
        int qs = q.size();
        for(int i=0; i<qs; i++) {
            int x = q.front();
            q.pop();
        
            set<int> s;
            for(int i=0; i<v[x].size(); i++) {
                int t = v[x][i];
                if(!visited[t]) s.insert(t);
            }
            
            for(int i=0; i<s.size(); i++) {
                if(idx == n+1) return 1;
                int key = seq[idx++];
                if(s.find(key)==s.end()) return 0;
                else {
                    visited[key] = true;
                    q.push(key);
                }
            } 
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
    int ret = bfs();
    cout << ret; 
    return 0;
}
