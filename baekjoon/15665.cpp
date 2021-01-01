#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m;
vector<int> arr;

void dfs(vector<int>& v, int depth) {
    if(depth == m) {
        for(int i=0; i<m; i++) cout << v[i] << " ";
        cout << "\n";
        return ;
    }
    bool same_level_visited[10001] = {false};
    for(int i=0; i<n; i++) {
        if(!same_level_visited[arr[i]]) {
            same_level_visited[arr[i]] = true;
            v.push_back(arr[i]);
            dfs(v, depth+1);
            v.pop_back();
        }
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }
    sort(arr.begin(), arr.end());
    vector<int> v;
    dfs(v, 0);
    return 0;
}