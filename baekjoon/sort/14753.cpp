#include <iostream>
#include <algorithm>

using namespace std;
int card[10010];
int n;
int ans;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    for(int i=1; i<=n ;i++)
        cin >> card[i];

    sort(card+1, card+1+n);

    ans = max(ans, card[1] * card[2] * card[3]);
    ans = max(ans, card[1] * card[2] * card[n]);
    ans = max(ans, card[n-2] * card[n-1] * card[n]);
    ans = max(ans, card[1] * card[2]);
    ans = max(ans, card[n] * card[n-1]);

    cout << ans;

    return 0;
}