#include <iostream>

using namespace std;
long long int dp[1000002];
int t;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for(int i=4; i<=1000000; i++) {
        long long int sum = 0;
        for(int j=i-1; j>=i-3; j--) sum += (dp[j]%1000000009);
        dp[i] = sum;
    }
    cin >> t;
    for(int i=0; i<t; i++) {
        int num;
        cin >> num;
        cout << (dp[num]%1000000009) << "\n";
    }
    return 0;
}