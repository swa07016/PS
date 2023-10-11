#include <iostream>

using namespace std;

int dp[100010];
int n;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    dp[1] = 2;
    dp[2] = 2;

    for(int i=3; i<=n; i++) {
        if(i%2 == 0) dp[i] = dp[i-1];
        else dp[i] = (dp[i-1] * 2) % 16769023;
    }

    cout << dp[n];

    return 0;
}