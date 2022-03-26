#include <iostream>
#include <algorithm>

using namespace std;
int n, k;

int count(int t) {
    int cnt = 0;
    for(int i=1; i<=n; i++) {
        cnt += min(t/i, n);
    }
    return cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    
    int L = 1, R = k;
    int ans = 0;
    while(L <= R) {
        int M = (L+R)/2;
        int cnt = count(M);
        if(cnt < k) L = M + 1;
        else {
            ans = M;
            R = M - 1;
        }
    }
    cout << ans;
    return 0;
}