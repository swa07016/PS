#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
int n;
vector<long long int> nums;
string input;

long long int toNumber(string str) {
    string numStr = "";
    for(int i=str.size() - 1; i>=0; i--) {
        numStr += str[i];
    }
    return atoll(numStr.c_str());
}  

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> input;
        nums.push_back(toNumber(input));
    }

    sort(nums.begin(), nums.end());
    for(int i=0; i<nums.size(); i++) 
        cout << nums[i] << "\n";

    return 0;
}