#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <climits>

using namespace std;
int n;
vector<int> nums;
vector<char> opers;
int result = INT_MIN;

int calc(vector<int>& idxs) {
    set<int> operIdx;
    vector<char> tmpOpers = opers;
    vector<int> tmpNums;
    for(int i=0; i<idxs.size(); i++) {
        operIdx.insert(idxs[i]);
    }
    for(int i=0; i<nums.size(); i++) {
        if(operIdx.find(i)!=operIdx.end()) {
            int tmp = nums[i];
            if(tmpOpers[i]=='*') tmp *= nums[i+1];
            if(tmpOpers[i]=='+') tmp += nums[i+1];
            if(tmpOpers[i]=='-') tmp -= nums[i+1];
            tmpNums.push_back(tmp);
            tmpOpers[i] = '@';
            ++i;
        } else tmpNums.push_back(nums[i]);
    }
    vector<char> calcOper;
    for(int i=0; i<tmpOpers.size(); i++) {
        if(tmpOpers[i] != '@') calcOper.push_back(tmpOpers[i]);
    }
    int ret = tmpNums[0];
    for(int i=1; i<tmpNums.size(); i++) {
        if(calcOper[i-1]=='*') ret *= tmpNums[i];
        if(calcOper[i-1]=='+') ret += tmpNums[i];
        if(calcOper[i-1]=='-') ret -= tmpNums[i];
    }
    return ret;
}

void dfs(int current, int depth, int len, vector<bool>& visited, vector<int>& idxs) {
    if(depth == len) {
        result = max(result, calc(idxs));
        return ;
    }
    for(int i=current; i<opers.size(); i++) {
        if(!visited[i]) {
            visited[i] = visited[i+1] = true;
            idxs.push_back(i);
            dfs(i, depth+1, len, visited, idxs);
            visited[i] = visited[i+1] = false;
            idxs.pop_back();
        }
    }
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i=0; i<n; i++) {
        if(i%2==0) {
            int tmp;
            cin >> tmp;
            nums.push_back(tmp);
        }
        else {
            char tmp;
            cin >> tmp;
            opers.push_back(tmp);
        }
    }
    vector<bool> visited(15, false);
    vector<int> idxs;
    if(opers.size()%2==0) {
        for(int i=0; i<=opers.size()/2; i++) {
            dfs(0, 0, i, visited, idxs);
        }
    }
    else {
        for(int i=0; i<=(opers.size()/2) + 1; i++) {
            dfs(0, 0, i, visited, idxs);
        }
    }
    cout << result;
    return 0;
}