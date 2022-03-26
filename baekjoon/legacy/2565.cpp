#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

struct Node {
  int length;
  int connection;
};

vector<pair<int, int>> ropes;
vector<Node> dp;
int n;

void dp_init() {
    for(int i=0; i<n; i++) {
        Node node = {1, ropes[i].second};
        dp.push_back(node);
    }
}

void solve() {
    dp_init();
    int ans = -1;
    for(int i=1; i<n; i++) {
        for(int j=0; j<i; j++) {
            if(ropes[i].second > dp[j].connection && dp[i].length < dp[j].length + 1) {
                dp[i].length = dp[j].length + 1;
                dp[i].connection = ropes[i].second;
                ans = max(ans, dp[i].length);
            }
        }
    }
    
    cout << n-ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        ropes.push_back(make_pair(a, b));
    }
    sort(ropes.begin(), ropes.end());
    solve();
    return 0;
}
