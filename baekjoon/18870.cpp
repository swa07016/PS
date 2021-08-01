#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;
int n;
vector<int> v;
vector<int> ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    v.resize(n);
    ans.resize(n);
    for(int i=0; i<n; i++){ 
        int tmp;
        cin >> tmp;
        v[i] = tmp; ans[i] = tmp;
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for(int i=0; i<n; i++) {
        int key = ans[i];
        cout << lower_bound(v.begin(), v.end(), key) - v.begin() << " ";
    }
    return 0;
}