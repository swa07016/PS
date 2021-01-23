#include <iostream>
#include <stack>
#include <vector>

using namespace std;
int n;
int cnt[1000001];

void solve(vector<int>& nums) {
    vector<int> result(n, -1);
    stack<vector<int>> s;
    //key, idx, value
    vector<int> tmp(3);
    tmp[0] = nums[0]; tmp[1] = 0; tmp[2] = cnt[nums[0]];
    s.push(tmp);
    
    for(int i=1; i<n; i++) {
        int c = cnt[nums[i]];
        while(!s.empty() && s.top()[2] < c) {
            int idx = s.top()[1];
            int key = s.top()[0];
            result[idx] = nums[i];
            s.pop();
        }
        vector<int> tmp(3);
        tmp[0] = nums[i]; tmp[1] = i; tmp[2] = cnt[nums[i]];
        s.push(tmp);
    }
    for(int i=0; i<n; i++) cout << result[i] << " ";
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n; i++) cin >> nums[i];
    for(int i=0; i<n; i++) cnt[nums[i]]++;
    solve(nums);
    return 0;
}
