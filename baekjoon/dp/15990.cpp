#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int T, n;
int dp[100010][4];
const int MOD = 1000000009;

void calc() {
    /*
        dp[i][j] : i를 1, 2, 3의 합으로 나타내는 방법의 수.
                      단, 마지막 더하는 수는 j.
                      
        dp[i][1] : i-1을 만드는 식들에 1을 더하면 i가 되므로 i-1을 만드는 경우의 수와 같음.
                        -> dp[i-1][2] + dp[i-1][3] (식에서 1이 연속하면 안되므로 2와 3으로 끝나는 경우에만 더함)
                        
        dp[i][2] : i-2을 만드는 식들에 2을 더하면 i가 되므로 i-2을 만드는 경우의 수와 같음.
                        -> dp[i-2][1] + dp[i-2][3] (식에서 2가 연속하면 안되므로 1와 3으로 끝나는 경우에만 더함)
                        
        dp[i][3] : i-3을 만드는 식들에 3을 더하면 i가 되므로 i-3을 만드는 경우의 수와 같음.
                        -> dp[i-3][1] + dp[i-3][2] (식에서 3이 연속하면 안되므로 1와 2으로 끝나는 경우에만 더함)                                    
    */
    
    dp[1][1] = 1;
    dp[2][1] = 0; dp[2][2] = 1;
    dp[3][1] = 1; dp[3][2] = 1; dp[3][3] = 1;
    
    for(int i=4; i<=100000; i++) {
        dp[i][1] = (dp[i-1][2] + dp[i-1][3]) % MOD;
        dp[i][2] = (dp[i-2][1] + dp[i-2][3]) % MOD;
        dp[i][3] = (dp[i-3][1] + dp[i-3][2]) % MOD;    
    }     
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    calc();
    cin >> T;
    
    for(int i=0; i<T; i++) {
        cin >> n;
        /* 
            n을 만드는 경우의 수는 1, 2, 3으로 끝나는 경우의 수를 모두 합해줘야 함.
            dp[n][1] + dp[n][2] + dp[n][3]을 할 경우 최대 30억이 넘어서 int범위를 넘어갈 수 있으므로
            (A + B) % M = (A%M + B%M)%M임을 이용하여 오버플로를 방지해준다.
        */
        cout << ((dp[n][1]  + dp[n][2]) % MOD + dp[n][3]) % MOD << "\n";
    }
    
    return 0;
}
