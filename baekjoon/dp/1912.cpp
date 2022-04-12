#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;
int n, dp[100010], ans = INT_MIN;
vector<int> seq;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    seq.resize(n+1);
    for(int i=1; i<=n; i++) cin >> seq[i];
    
        
     /*
        dp[i] : i번째 수를 마지막수로 하는 최대 연속합
        점화식 : dp[i] = max(seq[i], dp[i-1] + seq[i])
             1. i-1번째수를 마지막 수로 하는 최대 연속합에,
                 i번째 수를 더한 것이 i번째 수보다 크면 더한 것이 최대 연속합
                 -> dp[i] = dp[i-1] + seq[i]
                 
             2. i번째 수가 오히려 더 크다면 i번째수가 최대 연속합
                 -> dp[i] = seq[i]
        초기값 : dp[1] = seq[1] (1번째 최대 연속합은 자기 자신)
     */    
    dp[1] = seq[1];
    for(int i=2; i<=n; i++) {
        dp[i] = max(seq[i], dp[i-1] + seq[i]);
    }

    for(int i=1; i<=n; i++) ans = max(ans, dp[i]);
    cout << ans;
    return 0;
}
