#include <iostream>
#include <algorithm>

using namespace std;
int A[51][51], n, m, cnt = 0, T;
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, -1, 1};

void input() {
	int x, y, k;
	scanf("%d %d %d", &m, &n, &k);
	for(int i=0; i<k; i++) {
		scanf("%d %d", &x, &y);
		A[x][y] = 1;
	}
}

bool safe(int a, int b) {
	return (0<=a && a<m) && (0<=b && b<n);
}

void dfs(int a, int b, int c) {
	A[a][b] = c;
	for(int i=0; i<4; i++) {
		if(safe(a+dx[i], b+dy[i]) && A[a+dx[i]][b+dy[i]] == 1) 
		dfs(a+dx[i], b+dy[i], c);
	}
}

void solve() {
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			if(A[i][j] == 1){
				cnt++;
				dfs(i, j, cnt+1);
			}
		}
	}
}

void output() {
	printf("%d\n", cnt);
}

int main(void) {
	
	scanf("%d", &T);
	for(int i=0; i<T; i++) {
		input();
		solve();
		output();
		for(int j = 0; j <m; j++) 
		for(int k = 0; k<n; k++) A[j][k] = 0;
		cnt = 0;
	}
	return 0;
}