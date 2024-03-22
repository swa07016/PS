#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;
int n;
int num[100010];
int bestDiff = INT_MAX;
int ans;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    for(int i=1; i<=n; i++) cin >> num[i];
    sort(num+1, num+1+n);
    
    int s = 1, e = n;
    while(s < e) {
        int curr = num[s] + num[e];
        int diff = abs(curr);
        if(diff < bestDiff) {
            bestDiff = diff;
            ans = curr;
        } 

        if(curr == 0) {
            ans = 0;
            break;
        }
        if(curr < 0) s++;
        if(curr > 0) e--;
    }

    cout << ans;

    return 0;
}