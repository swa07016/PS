#include <iostream>
using namespace std;
int arr[20];
int n, m;

bool isPromising(int level) {
	for (int i = 1; i < level; i++) {
		if (arr[i] == arr[level]) return false;
	}
	return true;
}

void dfs(int level) {
	if (!isPromising(level)) return;
	if (level == m) {
		for (int i = 1; i <= m; i++) cout << arr[i] << " ";
		cout << "\n";
		return;
	}
	else {
		for (int i = 1; i <= n; i++) {
			arr[level + 1] = i;
			dfs(level + 1);
		}
 	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	dfs(0);
	return 0;
}