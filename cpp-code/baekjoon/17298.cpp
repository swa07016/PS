#include <iostream>
#include <stack>
#include <vector>
#include <utility>

using namespace std;
int n;

void solve(vector<int>& nums) {
    vector<int> result(n, -1);
    //idx, value
    stack<pair<int, int>> s;
    s.push(make_pair(0, nums[0]));
    
    for(int i=1; i<n; i++) {
        int num = nums[i];
        while(!s.empty() && s.top().second < num) {
            int idx = s.top().first;
            result[idx] = num;
            s.pop();
        }
        s.push(make_pair(i, num));
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
    solve(nums);
    return 0;
}