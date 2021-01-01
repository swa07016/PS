#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
vector<int> nums;
int opers[4];
int max_v = -1000000010, min_v = 1000000010;


void dfs(int plus, int minus, int multiply, int divide, int ret, int depth) {
    if(depth == n-1) {
        max_v = max(max_v, ret);
        min_v = min(min_v, ret);
        return ;
    }
    if(plus>0) dfs(plus-1, minus, multiply, divide, ret + nums[depth+1], depth+1);
    if(minus>0) dfs(plus, minus-1, multiply, divide, ret - nums[depth+1], depth+1);
    if(multiply>0) dfs(plus, minus, multiply-1, divide, ret * nums[depth+1], depth+1);
    if(divide>0) dfs(plus, minus, multiply, divide-1, ret / nums[depth+1], depth+1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    nums.resize(n);
    for(int i=0; i<n; i++) {
        cin >> nums[i];
    }
    for(int i=0; i<4; i++) {
        cin >> opers[i];
    }
    int ret = nums[0];
    dfs(opers[0], opers[1], opers[2], opers[3], ret, 0);
    cout << max_v << "\n" << min_v;
    return 0;
}