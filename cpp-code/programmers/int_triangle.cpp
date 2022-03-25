#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n));
    dp[0][0] = triangle[0][0];
    for(int i=1; i<n; i++) {
        for(int j=0; j<=i; j++) {
            if(j==0) dp[i][j] = triangle[i][j] + dp[i-1][j];
            if(j==i) dp[i][j] = triangle[i][j] + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j-1] + triangle[i][j], dp[i-1][j] + triangle[i][j]);
        }
    }
    int answer = -1;
    for(int i=0; i<n; i++) answer = max(answer, dp[n-1][i]);
    return answer;
}