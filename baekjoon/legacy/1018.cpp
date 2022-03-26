#include <iostream>
using namespace std;
char arr[52][52], tmp[9][9];
int n, m, ans = 100;

void fill_arr(int a, int b) {
	for (int i = a, i_i = 1; i < a + 8; i++, i_i++) {
		for (int j = b, j_j=1; j < b + 8; j++, j_j++) {
			tmp[i_i][j_j] = arr[i][j];
		}
	}
}

void check() {
	int cnt = 0;
	for (int i = 1; i <= 8; i++) {
		for (int j = 1; j <=8; j++) {
			if (i % 2 != 0) {
				if (j % 2 != 0) {
					if (tmp[i][j] != 'W')cnt++;
				}
				else {
					if (tmp[i][j] != 'B')cnt++;
				}
			}
			else {
				if (j % 2 != 0) {
					if (tmp[i][j] != 'B')cnt++;
				}
				else {
					if (tmp[i][j] != 'W')cnt++;
				}
			}
		}
	}
	if (ans > cnt) ans = cnt;
	cnt = 0;
	for (int i = 1; i <= 8; i++) {
		for (int j = 1; j <=8; j++) {
			if (i % 2 != 0) {
				if (j % 2 != 0) {
					if (tmp[i][j] != 'B')cnt++;
				}
				else {
					if (tmp[i][j] != 'W')cnt++;
				}
			}
			else {
				if (j % 2 != 0) {
					if (tmp[i][j] != 'W')cnt++;
				}
				else {
					if (tmp[i][j] != 'B')cnt++;
				}
			}
		}
	}
	if (ans > cnt) ans = cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) cin >> arr[i][j];
	}
	for (int i = 1; i <= n - 8 + 1; i++) {
		for (int j = 1; j <= m - 8 + 1; j++) {
			fill_arr(i, j);
			check();
		}
	}
	cout << ans;
	return 0;
}