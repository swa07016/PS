#include <iostream>
#include <string>
#include <map>

using namespace std;
int n, m;
// domain, password
map<string, string> password;
string domain, pw;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for(int i=0; i<n; i++) {
        cin >> domain >> pw;
        password.insert(make_pair(domain, pw));
    }

    for(int i=0; i<m; i++) {
        cin >> domain;
        cout << password.find(domain)->second << "\n";
    }

    return 0;
}