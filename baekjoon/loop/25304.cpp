#include <iostream>

using namespace std;
int total, sum;
int n;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> total;
    cin >> n;
    for(int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        sum += a*b;
    }
    if(sum == total) cout << "Yes";
    else cout << "No";
    return 0;
}