#include <iostream>
#include <algorithm>
using namespace std;

int n, m, cnt;
int arr[501][501], Size[251001];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};

void input() {
	cin >> n >> m;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) cin >> arr[i][j];
	}
}

bool safe(int a, int b) {
	return ((0<=a && a<n) && (0<=b && b<m));
}

void dfs(int x, int y, int c) {
	arr[x][y] = c;
	for(int i=0; i<4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if(safe(nx, ny) && arr[nx][ny]==1) dfs(nx, ny, c);
	}
}

bool compare(int a, int b) {
	return a > b;
}

void solve() {
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(arr[i][j]==1) {
			cnt++;
			dfs(i, j, cnt+1);
			}
		}
	}
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(arr[i][j]!=0) Size[arr[i][j]-2]++;
		}
	}
	sort(Size, Size+cnt, compare);
}

void output() {
	/*for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) cout << arr[i][j] << " ";
		cout << "\n";
	}*/
	cout << cnt << endl;
	cout << Size[0];
}

int main() {
	input();	
	solve();
	output();
	return 0;
}