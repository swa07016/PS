#include <iostream>

using namespace std;

long long int a, b;

long long int gcd(int x, int y) {
    if(y == 0) return x;
    return gcd(y, x%y);
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> a >> b;

    cout <<  (a * b) / gcd(a, b);

    return 0;
}