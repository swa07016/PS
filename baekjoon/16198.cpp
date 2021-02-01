#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;
int n;
int result = INT_MIN;

void dfs(int sum, vector<int> marble) {
    int mSize = marble.size();
    if(mSize == 2) {
        result = max(result, sum);
        return ;
    }
    for(int i=1; i<mSize-1; i++) {
        int tmp = (marble[i-1]*marble[i+1]);
        vector<int> v;
        for(int j=0; j<mSize; j++) {
            if(i==j) continue;
            v.push_back(marble[j]);
        }
        dfs(sum+tmp, v);
    }
    return ;
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n;
    vector<int> w(n);
    for(int i=0; i<n; i++) cin >> w[i];
    for(int i=1; i<n-1; i++) {
        int tmp = (w[i-1]*w[i+1]);
        vector<int> v;
        for(int j=0; j<w.size(); j++) {
            if(i==j) continue;
            v.push_back(w[j]);
        }
        dfs(tmp, v);
    }
    cout << result;
    return 0;
}