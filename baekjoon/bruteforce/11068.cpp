#include <iostream>
#include <string>

using namespace std;
int T, input;

string convert(int number, int base) {
    if (number == 0) return "0"; // 0의 경우를 미리 처리

    const string chars = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"; // 최대 62진법까지 표현 가능
    string result = "";

    while (number > 0) {
        result = chars[number % base] + result;
        number /= base;
    }

    return result;
}

bool isValidPalindromeNumber(const string& str) {
    int len = str.length();
    for (int i = 0; i < len / 2; ++i) {
        if (str[i] != str[len - 1 - i]) return false;
    }
    return true;
}


bool isPalindrome(int num) {
    for(int i=2; i<=64; i++) {
        string convertedNumber = convert(num, i);
        if(isValidPalindromeNumber(convertedNumber)) return true;
    }

    return false;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> T;
    for(int i=0; i<T; i++) {
        cin >> input;
        if(isPalindrome(input)) cout << "1\n";
        else cout << "0\n";
    }

    return 0;
}