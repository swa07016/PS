#include <iostream>
#include <cmath>
using namespace std;
int cnt = 0, n;
int cols[16];

bool isPromising(int level) {
	for (int i = 1; i < level; i++) {
		if (cols[i] == cols[level] || (level - i) == abs(cols[level] - cols[i])) return false;
	}
	return true;
}

void dfs(int level) {
	if (!isPromising(level)) return;
	else if (level == n) {
		cnt++;
		return;
	}
	else {
		for (int i = 1; i <= n; i++) {
			cols[level + 1] = i;
			dfs(level + 1);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	dfs(0);
	cout << cnt;
	return 0;
}