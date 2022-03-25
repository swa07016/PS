#include <iostream>
#include <vector>
using namespace std;
int n;
int arr[25];
int min_diff = 500;
int s[25][25];
int chk[25];

vector <int> start;
vector <int> link;

bool isPromising(int level) {
	for (int i = 0; i < level; i++) if (arr[i] == arr[level] || arr[i] > arr[level]) return false;
	return true;
}

void dfs(int level) {
	if (!isPromising(level)) return;
	else if (level == n / 2) {
		int cnt = 1;
		for (int i = 1; i <= n / 2; i++) chk[arr[cnt++]]++;
		for (int i = 1; i <= n; i++) {
			if (chk[i] == 1) start.push_back(i);
			else link.push_back(i);
		}
		int sum_s = 0, sum_l = 0;
		for (int i = 0; i < start.size(); i++) {
			for (int j = 0; j < start.size(); j++) {
				if (i == j) continue;
				sum_s += s[start[i]][start[j]];
				sum_l += s[link[i]][link[j]];
			}
		}
		if (abs(sum_s - sum_l) < min_diff) min_diff = abs(sum_s - sum_l);
		for (int i = 1; i <= n; i++) chk[i] = 0;
		start.clear();
		link.clear();
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
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) cin >> s[i][j];
	}
	dfs(0);
	cout << min_diff;	
	return 0;
}