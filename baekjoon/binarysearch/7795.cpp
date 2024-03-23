#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int t;
int n, m;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> t;
    for(int i=0; i<t; i++) {
        cin >> n >> m;

        int ans = 0;

        vector<int> a(n);
        vector<int> b(m);

        for(int j=0; j<n; j++) cin >> a[j];
        for(int j=0; j<m; j++) cin >> b[j];

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        for(int j=0; j<a.size(); j++) {
            int key = a[j];
            int lowerIndex = lower_bound(b.begin(), b.end(), key) - b.begin();
            ans += lowerIndex;
        }

        cout << ans << "\n";
    }

    return 0;
}