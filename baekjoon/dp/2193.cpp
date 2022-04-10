#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
// 자료형을 int로 선언하면 틀림..
long long int n, dp[100][2];

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cin >> n;
    
    /*
        dp[i][j] : i자리 이친수의 개수. 단, 마지막수가 j.
           
         - 점화식
             1. dp[i][0] : 마지막 수가 0 또는 1인 i-1자리 이친수들에 0을 붙임.
                 -> dp[i-1][0] + dp[i-1][1]
                 
             2. dp[i][1] : 마지막 수가 0인 i-1자리 이친수들에 1을 붙임.
                 -> dp[i-1][0]
    
         - 초기값
             dp[1][1] = 1. (1자리 이친수의 개수는 1밖에 없음.)
    */
    dp[1][1]  = 1;
    for(int i=2; i<=n; i++) {
        dp[i][0] = dp[i-1][0] + dp[i-1][1];
        dp[i][1] = dp[i-1][0];
    }     
    cout << dp[n][0] + dp[n][1];
    return 0;
}
