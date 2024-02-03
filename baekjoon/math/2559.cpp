#include <iostream>
#include <climits>

using namespace std;
int temp[100010];
int n, k;
int ans = INT_MIN;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> k;
    for(int i=1; i<=n; i++) cin >> temp[i];
    for(int i=2; i<=n; i++) temp[i] += temp[i-1];

    for(int i=k; i<=n; i++) {
        ans = max(ans, temp[i] - temp[i-k]);
    }

    cout << ans;

    return 0;
}