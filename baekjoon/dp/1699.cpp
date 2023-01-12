#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
int n;
int dp[100010];
vector<int> key;

void initDpTable() {
    dp[0] = 0;
    for(int i=1; i<=n; i++) dp[i] = i;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    initDpTable();
    
    for(int i=1; i<=n; i++) {
        if((int)sqrt(i) * (int)sqrt(i) == i){
            dp[i] = 1;
            key.push_back(i);
        } 
        else for(int j=0; j<key.size(); j++) {
            int keyNum = key[j];
            dp[i] = min(dp[i], dp[keyNum] + dp[i-keyNum]);
        }
    }

    cout << dp[n] << "\n";
    return 0;
}