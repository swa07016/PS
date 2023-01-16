#include <iostream>
#include <set>
#include <string>

using namespace std;
set<string> strs;
int n, m, cnt;
string input;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        cin >> input;
        strs.insert(input);
    }
    for(int i=0; i<m; i++) {
        cin >> input;
        if(strs.find(input) != strs.end()) cnt++;
    }
    cout << cnt;
    return 0;
}