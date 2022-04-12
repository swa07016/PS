#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n, ans = -1, ans_idx;
int dp[1010], A[1010], pre_idx[1010];
vector<int> sub_seq;

// 정답의 부분수열을 거꾸로 찾아주는 함수
void setSubSeq(int idx, int cnt) {
    if(cnt == 0) return ;
    sub_seq.push_back(A[idx]);
    setSubSeq(pre_idx[idx], cnt-1);
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    cin >> n;
    for(int i=1; i<=n; i++) cin >> A[i];   
  
     /*
         dp[i] : i번째 수를 마지막으로 하는 가장 긴 증가하는 부분 수열의 길이. 
         - 점화식 : i번째 이전 수가 i번째 수보다 작으면 증가하는 수열이므로 dp[j] + 1로 값을 갱신할지 결정하면 됨.
             -> dp[i] = max(dp[j] +1). (j는 [1, i)구간의 자연수)
             
         - 초기화 : dp[i] = 1. (자기 자신을 처음이자 마지막 수로 하는 부분 수열의 길이)
     */
    for(int i=1; i<=n; i++) { 
        dp[i] = 1;
        pre_idx[i] = i;
    }
    for(int i=2; i<=n; i++) {
        for(int j=1; j<i; j++) {
            if(A[j] < A[i] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                pre_idx[i] = j;   
            }   
        }     
    }
    
    for(int i=1; i<=n; i++) { 
        if(ans < dp[i]) {
            ans = dp[i];
            ans_idx = i;       
        }
    }
    setSubSeq(ans_idx, ans);
    cout << ans << "\n";
    for(int i=ans-1; i>=0; i--) 
        cout << sub_seq[i] << " ";
    
    return 0;
}
