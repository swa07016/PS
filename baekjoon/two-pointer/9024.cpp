#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
int t;
int n, k;
int num[1000010];

int countAnswer() {
    int s = 1, e = n;
    int bestDiff = INT_MAX;
    int cnt = 0;

    while(s < e) {
        int sum = num[s] + num[e];
        int diff = abs(k - sum);
        
        if(diff == bestDiff) cnt++;
        
        if(diff < bestDiff) {
            bestDiff = diff;
            cnt = 1;
        }
        
        if(sum == k) {
            s++;
            e--;
        }
        if(sum < k) s++;
        if(sum > k) e--;
    }

    return cnt;
}

int main() {

    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> t;
    for(int i=0; i<t; i++) {
        cin >> n >> k;
        for(int j=1; j<=n; j++) cin >> num[j];
        sort(num+1, num+1+n);

        cout << countAnswer() << "\n";
    }

    return 0;
}