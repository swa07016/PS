#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m, ans;
vector<vector<int>> v;
bool visited[1010];

void dfs(int current){
    visited[current] = true;
    for(int i=0; i<v[current].size(); i++) {
        int next = v[current][i];
        if(!visited[next]) dfs(next);
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    	
    cin >> n >> m;
    v.resize(n+1);
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    /*
        임의의 점에서 dfs를 수행하면 하나의 연결요소가 만들어짐.
        즉, dfs를 수행한 횟수가 연결요소의 개수임.
    */
    for(int i=1; i<=n; i++) {
        if(!visited[i]) {
            dfs(i);
            ans++;        
        }
    } 
            	    	            	    	        	    	        	    	        	       	    	          cout << ans;        	    	
	return 0;
}
