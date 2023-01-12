#include <iostream>

using namespace std;
int n, k;
int dp[201][201];
const int DIV = 1000000000;

void initDpTable() {
    for(int i=1; i<=k; i++) dp[1][i] = i;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    initDpTable();

    for(int i=2; i<=n; i++) 
        for(int j=1; j<=k; j++)
            dp[i][j] = (dp[i][j-1] + dp[i-1][j]) % DIV;

    cout << dp[n][k] << "\n";
    return 0;
}