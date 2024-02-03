#include <iostream>
#include <algorithm>

using namespace std;
int n, m;
int nums[15010];
int ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i=0; i<n; i++) cin >> nums[i];
    sort(nums, nums+n);

    int start = 0, end = n-1;
    while(start < end) {
        int sum = nums[start] + nums[end];
        if(sum == m) {
            ans++;
            start++;
            end--;
        }
        if(sum < m) start++;
        if(sum > m) end--;
    }

    cout << ans;
    return 0;
}