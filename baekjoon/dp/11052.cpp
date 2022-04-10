#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n;
int p[1010];
int dp[1010];

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    cin >> n;
    for(int i=1; i<=n; i++) cin >> p[i];        
    
    /*
        dp[n] : 카드 n개를 갖기 위해 지불해야 하는 금액의 최댓값
        점화식 : dp[n] = max(dp[k] + dp[k-n]). 단, k는 [1, n/2] 범위의 자연수
                      
                      ex. 카드 5개를 갖기 위해 지불해야 하는 금액의 최댓값?
                      p[5], dp[1] + dp[4], dp[2] + dp[3] 중 가장 큰 값
                       
                      Q. dp[5]를 구할 때, 
                           dp[1] + dp[1] + dp[3] 이런 경우는 고려 안 하나?
                      A. dp[1] + dp[1]이 dp[2]를 구할 때 이미 고려되었으므로 
                           dp[2] + dp[3]으로 표현해도 적절하다.    

        초기값 : dp[i] = p[i] (i개를 갖기 위해 카드 i개짜리 카드팩 구매하는 방법)
    */
    for(int i=1; i<=n; i++) {
        dp[i] = p[i];
        for(int j=1; j<=i/2; j++) dp[i] = max(dp[i], dp[j] + dp[i-j]);    
    }
    
    cout << dp[n];
    return 0;
}
