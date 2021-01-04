#include <iostream>
using namespace std;
int n, max1=-1;
int arr[201], dp[201];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= n; i++) {
		dp[i] = 1;
		for (int j = 1; j < i; j++) {
			if ((arr[j] <arr[i])&&(dp[j] + 1 > dp[i])) dp[i] = dp[j] + 1;
		}
		if (max1 < dp[i])max1 = dp[i];
	}
	cout << n - max1;
	return 0;
}