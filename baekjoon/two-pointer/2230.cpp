#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;
int n, m, bestDiff = INT_MAX;
int num[100010];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for(int i=1; i<=n; i++) cin >> num[i];
    sort(num+1, num+1+n);

    int s = 1, e = 1;
    while(s <= n && e <=n) {
        int diff = num[e] - num[s];

        if(diff >= m && diff < bestDiff) bestDiff = diff;
        if(diff == m) {
            bestDiff = diff;
            break;
        }
        if(diff < m) e++;
        if(diff > m) s++;
    }

    cout << bestDiff;

    return 0;
}