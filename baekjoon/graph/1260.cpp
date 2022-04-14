#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int n, m, k;
vector<vector<int>> v;
bool visited[1010];

void dfs(int current) {
    visited[current] = true;
    cout << current << " ";
    
    for(int i=0; i<v[current].size(); i++) {
        int next = v[current][i];
        if(!visited[next]) dfs(next);
    }    
}

void bfs() {
    queue<int> q;
    q.push(k); visited[k] = true;
    
    while(!q.empty()){
        int current = q.front(); q.pop();
        cout << current << " ";
        
        for(int i=0; i<v[current].size(); i++) {
            int next = v[current][i];
            if(!visited[next]) {
                visited[next] = true;
                q.push(next);    
            }
        }    
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    	    
	cin >> n >> m >> k;
	v.resize(n+1);
    for(int i=1; i<=m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    /*
        방문할 수 있는 정점이 여러개인 경우에 정점 번호가
        작은 것을 먼저 방문하기 위해 오름차순 정렬 수행
    */
    for(int i=1; i<=n; i++) sort(v[i].begin(), v[i].end());
	
	dfs(k); cout << "\n";
    for(int i=1; i<=n; i++) visited[i] = false;
	bfs();
	
	return 0;
}
