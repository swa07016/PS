#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
vector<int> arr;
int result = -1;
bool visited[8];

int calculate(vector<int>& v) {
    int ret = 0;
    for(int i=0; i<=n-2; i++) ret += abs(v[i]-v[i+1]);
    return ret;
}

void dfs(vector<int>& v, int depth) {
    if(depth == n) {
        result = max(calculate(v), result);
        return;
    }
    for(int i=0; i<n; i++) {
        if(!visited[i]) {
            v.push_back(arr[i]);
            visited[i]=true;
            dfs(v, depth+1);
            v.pop_back();
            visited[i]=false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++) {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }  
    vector<int> v;
    dfs(v, 0);
    cout << result;
    return 0;
}