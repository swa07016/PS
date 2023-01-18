#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n, minNum = 1000000001;
int nums[110];
vector<int> diffs;

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a%b);
}

void printRes(int gcdNum) {
    vector<int> res;
    res.push_back(gcdNum);
    for(int i=2; i*i<=gcdNum; i++) {
        if(gcdNum%i == 0) {
            res.push_back(i);
            if(gcdNum/i != i) res.push_back(gcdNum/i);
        }
    }
    sort(res.begin(), res.end());
    for(int i=0; i<res.size(); i++) cout << res[i] << " ";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i=0; i<n; i++) cin >> nums[i];
    sort(nums, nums+n);
    for(int i=1; i<n; i++) diffs.push_back(nums[i] - nums[i-1]);

    int gcdNum = gcd(diffs[1], diffs[0]);
    for(int i=2; i<diffs.size(); i++) {
        gcdNum = gcd(gcdNum, diffs[i]);
    }

    printRes(gcdNum);
    return 0;
}