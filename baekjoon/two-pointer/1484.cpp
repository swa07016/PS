#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int G, N;
vector<int> ans;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> G;

    int N = (G + 1) / 2 + 1;
    int s = 1, e = s+1;

    while(s < e && e <= N) {
        int key = (e-s)*(e+s);
        if(key == G) {
            ans.push_back(e);
            s++;
        }
        if(key > G) {
            s++;
        }
        if(key < G) {
            e++;
        }
    }

    if(ans.empty()) {
        cout << "-1";
        return 0;
    }
    sort(ans.begin(), ans.end());
    for(int i=0; i<ans.size(); i++) cout << ans[i] << "\n";

    return 0;
}