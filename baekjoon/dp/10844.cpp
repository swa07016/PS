#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n;
int ans;
int dp[110][10];
const int MOD = 1000000000;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    cin >> n;
   
   /*
       dp[i][j] :길이가 i인 계단수. 단, 마지막 수가 j
       
       
       - 점화식
           1. dp[i][0] : 길이가 i-1이고 마지막 수가 1인 계단수에 0을 붙이는 경우
               -> dp[i-1][1]
               
           2. dp[i][k] (k는 [1, 8] 구간의 자연수) : 길이가 i-1이고 마지막 수가 k-1또는 k+1인 계단수에 k를 붙이는 경우
               -> dp[i-1][k-1] + dp[i-1][k+1]
               
           3. dp[i][9] : 길이가 i-1이고 마지막 수가 8인 계단수에 9를 붙이는 경우
               -> dp[i-1][8]
               
        - 초기값
            dp[1][i] = 1 : 자연수 하나는 한 자리의 계단 수임. 단, 0으로 시작하는 수는 계단수가 아니므로 dp[1][0] = 0.
   */
    for(int i=1; i<=9; i++) dp[1][i] = 1;    
    for(int i=2; i<=n; i++) {
        dp[i][0] = (dp[i-1][1] % MOD);
        for(int j=1; j<=8; j++) {
            dp[i][j] = (dp[i-1][j-1] +  dp[i-1][j+1]) % MOD;
        }
        dp[i][9] = (dp[i-1][8]  % MOD);    
    }    
    
    for(int i=0; i<=9; i++) ans = (ans + dp[n][i])  % MOD;
    cout << ans % MOD;
    
    return 0;
}
