#include <iostream>
#include <algorithm>

using namespace std;
int A[30][30], n, Size[400], cnt = 0;
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, -1, 1};

void input() {
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) scanf("%1d", &A[i][j]);
	}
	
}

bool safe(int a, int b) {
	return (0<=a && a<n) && (0<=b && b<n);
}

void dfs(int a, int b, int c) {
	A[a][b] = c;
	for(int i=0; i<4; i++) {
		if(safe(a+dx[i], b+dy[i]) && A[a+dx[i]][b+dy[i]] == 1) 
		dfs(a+dx[i], b+dy[i], c);
	}
}

void solve() {
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(A[i][j] == 1){
				cnt++;
				dfs(i, j, cnt+1);
			}
		}
	}
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(A[i][j]) Size[A[i][j] - 2]++;
		}
	}
	sort(Size, Size+cnt);
}

void output() {
	printf("%d\n", cnt);
	for(int i=0; i<cnt; i++) printf("%d\n", Size[i]);
}

int main(void) {
	
	iostream::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	solve();
	output();
	return 0;
}
