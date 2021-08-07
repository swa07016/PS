#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
vector<int> A;
int dp[1010], dp_r[1010];
int ans = -1;

void lis() {
    dp[0] = 1;
    for(int i=1; i<n; i++) {
        dp[i] = 1;
        for(int j=0; j<i; j++) {
            if(A[i] > A[j] && dp[i] < dp[j] + 1) dp[i] = dp[j] + 1;
        }
    }
}

void lis_r() {
    dp_r[n-1] = 1;
    for(int i=n-2; i>=0; i--) {
        dp_r[i] = 1;
        for(int j=n-1; j>i; j--) {
            if(A[i] > A[j] && dp_r[i] < dp_r[j] + 1) dp_r[i] = dp_r[j] + 1;
        } 
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    A.resize(n);
    for(int i=0; i<n; i++) cin >> A[i];
    
    lis(); lis_r();
    for(int i=0; i<n; i++) {
        ans = max(ans, dp[i] + dp_r[i]);    
    }
    
    cout << --ans;
    return 0;
}
