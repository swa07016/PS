#include <iostream>
#include <algorithm>

using namespace std;
int t, n;


// 9465 - 스티커
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    for(int i=0; i<t; i++) {
        int sticker[100010][3] = { 0 };
        int dp[100010][3] = { 0 };
        
        cin >> n;

        for(int j=1; j<=n; j++) cin >> sticker[j][1];
        for(int j=1; j<=n; j++) cin >> sticker[j][2];

        dp[1][1] = sticker[1][1];
        dp[1][2] = sticker[1][2];
        dp[2][1] = sticker[1][2] + sticker[2][1];
        dp[2][2] = sticker[1][1] + sticker[2][2];
        
        for(int j=3; j<=n; j++) {
            dp[j][1] = sticker[j][1] + max(max(dp[j-2][1], dp[j-2][2]), dp[j-1][2]);
            dp[j][2] = sticker[j][2] + max(max(dp[j-2][1], dp[j-2][2]), dp[j-1][1]);
        }
        
        cout << max(dp[n][1], dp[n][2]) << "\n";
    }

    return 0;
}