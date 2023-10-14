#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string str) {
    int length = str.size();    
    int last = (length - 1) / 2;

    for(int i=0; i<=last; i++) {
        if(str[i] != str[length - i - 1]) return false;
    }

    return true;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string str;

    while(1) {
        cin >> str;
        if(str == "0") break;    

        if(isPalindrome(str)) cout << "yes\n";
        else cout << "no\n";
    }
  
    return 0;
}