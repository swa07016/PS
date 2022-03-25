#include <iostream>
#include <vector>
using namespace std;
vector <int> v[101];
bool visit[101];
int n, k, a, b, cnt;

void dfs(int x) {
	visit[x] = true;
	for(int i=0; i<v[x].size(); i++) {
		if(!visit[v[x][i]]) dfs(v[x][i]);
	}
}

int main(){
	cin >> n >> k;
	for(int i=0; i<k; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1);
	for(int i=1; i<=n; i++) {
		if(visit[i]) cnt++;
	}
	cout << --cnt;
	return 0;
}