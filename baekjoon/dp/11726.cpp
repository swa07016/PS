#include <iostream>
#include <algorithm>

using namespace std;
int dp[1010];
int n;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;

    /*
        dp[n] : 2*n 크기의 직사각형을 1*2, 2*1 타일로 채우는 방법의 수
        점화식 : dp[n] = dp[n-1] + dp[n-2]
            1. 2*(n-1) 크기의 직사각형을 채우고 2*1 1개로 채우는 방법
               -> dp[n-1]
            
            2. 2*(n-2) 크기의 직사각형을 채우고 1*2 2개로 채우는 방법
               -> dp[n-2]
            
            ※ 1과 2를 더한 것이 2*n 크기의 직사각형을 채우는 방법의 수
    
        초기값 : dp[1] = 1 (2*1 크기의 직사각형을 채우는 방법의 수)
                 dp[2] = 2 (2*2 크기의 직사각형을 채우는 방법의 수)
    */
    dp[1] = 1; dp[2] = 2;
    for(int i=3; i<=n; i++) dp[i] = (dp[i-1] + dp[i-2]) % 10007;
        
    cout << dp[n];
    return 0;
}
