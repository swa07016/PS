#include <iostream>
#include <utility>
#include <vector>
using namespace std;
int arr[10][10];
vector <pair<int, int>> v;

bool check(int x, int y,int num) {
	for (int i = 1; i <= 9; i++) if (arr[x][i] == num)return false;
	for (int i = 1; i <= 9; i++) if (arr[i][y] == num)return false;
	int r_x = ((x - 1) / 3) * 3 + 1;
	int r_y = ((y - 1) / 3) * 3 + 1;
	for (int i = r_x; i <= r_x + 2; i++) {
		for (int j = r_y; j <= r_y + 2; j++) {
			if (arr[i][j] == num) return false;
		}
	}
	return true;
}
void dfs(int level) {
	
	if (level == v.size() - 1) {
		for (int i = 1; i <= 9; i++) {
			for (int j = 1; j <= 9; j++) cout << arr[i][j] << " ";
			cout << "\n";
		}
		exit(0);
	}
	else {
		for (int i = 1; i <= 9; i++) {
			int x = v[level+1].first;
			int y = v[level+1].second;
			if (check(x, y, i)) {
				arr[x][y] = i;
				dfs(level + 1);
				arr[x][y] = 0;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	v.push_back(make_pair(0, 0));
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			int tmp;
			cin >> tmp;
			if (tmp == 0) v.push_back(make_pair(i, j));
			arr[i][j] = tmp;
		}
	}
	dfs(0);
	return 0;
}