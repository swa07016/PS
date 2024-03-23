#include <iostream>

using namespace std;
int n;
int ans;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    int s = 1, e = 1;
    int sum = 1;

    while(s<=e && e <= n) {
        if(sum == n) {
            ans++;
            sum -= s;
            s++;
        }
        if(sum > n) {
            sum -= s;
            s++;
        }
        if(sum < n) {
            e++;
            sum += e;
        }
    }

    cout << ans;
    return 0;
}