#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;
int n;
int sol[100010]; // 용액 배열
int s, e;
int ansS, ansE, bestDiff = INT_MAX;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    for(int i=1; i<=n; i++) cin >> sol[i];

    sort(sol+1, sol+1+n);

    s = 1;
    e = n;

    while(s < e) {
        int curr = sol[s] + sol[e];
        if(abs(curr) < bestDiff) {
            bestDiff = abs(curr);
            ansS = s;
            ansE = e;
        }
        if(curr == 0) {
            ansS = s;
            ansE = e;
            break;
        }
        if(curr < 0) {
            s++;
        }
        if(curr > 0) {
            e--;
        }
    }

    cout << sol[ansS] << " " << sol[ansE];

    return 0;
}