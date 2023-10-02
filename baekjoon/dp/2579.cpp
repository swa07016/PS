#include <iostream>
#include <algorithm>

using namespace std;
int step[310];
int dp[310][3];
int n;

// 2579 - 계단 오르기
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i=1; i<=n; i++) cin >> step[i];

    dp[1][1] = step[1];

    for(int i=2; i<=n; i++) {
        dp[i][1] = step[i] + max(dp[i-2][1], dp[i-2][2]);
        dp[i][2] = step[i] + dp[i-1][1];
    }

    cout << max(dp[n][1], dp[n][2]);

    return 0;
}