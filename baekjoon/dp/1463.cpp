#include <iostream>
#include <algorithm>

using namespace std;
int dp[1000010];
int n;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    
    /*
        dp[n] : n을 만드는데 드는 연산의 최소 횟수
        점화식 : dp[n] = 1 + min(dp[n-1], dp[n/2], dp[n/3])
            0. 1을 빼는 연산을 한 번 진행 +  
               n-1을 만드는 최소 연산 횟수(dp[n-1]) 
               -> 1 + dp[n-1]
            
            1. n이 2의 배수라면,
               2로나누는 연산을 한 번 진행 + 
               n/2을 만드는 최소 연산 횟수(dp[n/2])
               -> 1 + dp[n/2]
               
            2. n이 3의 배수라면,
               3으로 나누는 연산을 한 번 진행 + 
               n/3을 만드는 최소 연산 횟수(dp[n/3])
               -> 1 + dp[n/3]
              
            ※ 0, 1, 2 중에 최솟값이 n을 만드는 최소 연산 횟수(dp[n])가 됨.
            
        초기값 : dp[1] = 0 (0번의 연산으로 1을 만들 수 있다)
    */
    
    dp[1] = 0;
    for(int i=2; i<=n; i++) {
        dp[i] = 1 + dp[i-1];
        if(i%2 == 0) dp[i] = min(dp[i], 1 + dp[i/2]);
        if(i%3 == 0) dp[i] = min(dp[i], 1 + dp[i/3]);
    }
    
    cout << dp[n];
    return 0;
}
