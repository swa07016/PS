#include <iostream>
#include <string>

using namespace std;
string str;
int i;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> str >> i;
    cout << str[i];

    return 0;
}