#include <iostream>
#include <string>

using namespace std;
string s, t;

bool isSubString(string a, string b) {
    int idxA = 0, idxB = 0, cnt = 0;
    while(idxA < a.size() && idxB < b.size()) {
        if(a[idxA] == b[idxB]) {
            cnt++;
            idxA++; idxB++;
        }
        else idxB++;
    }
    if(cnt == a.size()) return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    while(cin >> s >> t) {
        if(isSubString(s, t)) cout << "Yes\n";
        else cout << "No\n";
    }

    return 0;
}