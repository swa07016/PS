#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    string name;
    cin >> name;

    vector<int> count(26, 0);
    for (char c : name) {
        count[c - 'A']++;
    }

    int oddCount = 0;
    char oddChar;
    for (int i = 0; i < 26; i++) {
        if (count[i] % 2 != 0) {
            oddCount++;
            oddChar = 'A' + i;
        }
    }

    if (oddCount > 1) {
        cout << "I'm Sorry Hansoo";
    } else {
        string frontHalf = "", backHalf = "";
        for (int i = 0; i < 26; i++) {
            string temp(count[i] / 2, 'A' + i);
            frontHalf += temp;
            backHalf = temp + backHalf;
        }
        if (oddCount == 1) {
            cout << frontHalf + oddChar + backHalf;
        } else {
            cout << frontHalf + backHalf;
        }
    }

    return 0;
}
