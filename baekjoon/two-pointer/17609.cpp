#include <iostream>
#include <string>

using namespace std;

int n;

bool isPalindrome(string str) {
    int x = str.size() / 2;
    for(int i=0; i<x; i++) {
        if(str[i] != str[str.size() - 1 - i]) return false;
    }
    return true;
}

int checkPalindrome(string str) {
    int s = 0, e = str.size() - 1;

    while(s < e) {
        if(str[s] == str[e]) {
            s++;
            e--;
            if(s >= e) return 0;
        }
        if(str[s] != str[e]) {
            int subStrLength = e - s;
            if(isPalindrome(str.substr(s+1, subStrLength))) return 1; // 왼쪽것을 삭제하고 팰린드롬인 경우 
            if(isPalindrome(str.substr(s, subStrLength))) return 1; // 오른쪽것을 삭제하고 팰린드롬인 경우
            return 2;
        }
    }
    return 2;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    for(int i=0; i<n; i++) {
        string input;
        cin >> input;
        
        cout << checkPalindrome(input) << "\n";
    }

    return 0;
}