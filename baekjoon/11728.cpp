#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> nums;
int n, m;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    int tmp;
    for(int i=0; i<n; i++) {
        cin >> tmp;
        nums.push_back(tmp);
    } 
    for(int i=0; i<m; i++) {
        cin >> tmp;
        nums.push_back(tmp);
    }
    sort(nums.begin(), nums.end());
    for(int i=0; i<n+m; i++) cout << nums[i] << " ";
    return 0;
}
