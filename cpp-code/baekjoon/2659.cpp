#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int keyClockNum;

int generateClockNum(vector<int>& input) {
    vector<int> candidate(4);
    candidate[0] = input[0]*1000 + input[1]*100 + input[2]*10 + input[3];
    candidate[1] = input[1]*1000 + input[2]*100 + input[3]*10 + input[0];
    candidate[2] = input[2]*1000 + input[3]*100 + input[0]*10 + input[1];
    candidate[3] = input[3]*1000 + input[0]*100 + input[1]*10 + input[2];
    sort(candidate.begin(), candidate.end());
    return candidate[0];
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    vector<int> input(4);
    set<int> clockNums;
    for(int i=0; i<4; i++) cin >> input[i];
    keyClockNum = generateClockNum(input);
    int cnt = 0;
    for(int i=1; i<=9; i++) {
        vector<int> nums(4);
        for(int j=1; j<=9; j++) {
            for(int k=1; k<=9; k++) {
                for(int h=1; h<=9; h++) {
                    nums[0] = i;
                    nums[1] = j;
                    nums[2] = k;
                    nums[3] = h;
                    int ret = generateClockNum(nums);
                    if(clockNums.find(ret) == clockNums.end() &&  ret <= keyClockNum) {
                        cnt++;
                        clockNums.insert(ret);
                    }
                }
            }
        }
    }
    cout << cnt;
    return 0;
}