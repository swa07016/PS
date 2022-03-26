#include <iostream>
#include <string>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    string A, B, C, D;
    cin >> A >> B >> C >> D;
    A += B;
    C += D;
    cout << atoll(A.c_str()) + atoll(C.c_str());
    return 0;
}