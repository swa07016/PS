#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, x, ans;
int nums[100001];
int s, e;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> nums[i];
    }
    cin >> x;
    sort(nums + 1, nums + n + 1);

    s = 1;
    e = n;
    while(s < e) {
        int sum = nums[s] + nums[e];
        if(sum == x) {
            ans++;
            s++;
            e--;
        }
        if(sum < x) s++;
        if(sum > x) e--;
    }
    cout << ans;
    return 0;
}