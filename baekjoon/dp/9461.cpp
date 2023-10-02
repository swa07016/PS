#include <iostream>

using namespace std;
long long int dp[110];
int t, n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    dp[1] = dp[2] = dp[3] = 1;
    for(int i=4; i<=100; i++) {
        dp[i] = dp[i-2] + dp[i-3];
    }

    cin >> t;
    for(int i=0; i<t; i++) {
        cin >> n;
        cout << dp[n] << "\n";
    }

    return 0;
}