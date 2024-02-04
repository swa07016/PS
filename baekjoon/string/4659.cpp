#include <iostream>
#include <string>

using namespace std;

bool hasOneOrMoreConsonant(string str) {
    for(int i=0; i<str.size(); i++) {
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') return true;
    }
    return false;
}

bool isConsonant(char c) {
    char consonant[5] = {'a', 'e', 'i', 'o', 'u'};
    for(int i=0; i<5; i++) if(c == consonant[i]) return true;
    return false;
}

bool isNotTripleTypeChar(string str) {
    // 언더 플로우 방지
    if(str.size() < 3) return true;
    for(int i=0; i<str.size()-2; i++) {
        if(isConsonant(str[i]) && isConsonant(str[i+1]) && isConsonant(str[i+2])) {
            // cout << str[i] << str[i+1] << str[i+2] << "\n";
            return false;
        } 
        if(!isConsonant(str[i]) && !isConsonant(str[i+1]) && !isConsonant(str[i+2])) {
            // cout << str[i] << str[i+1] << str[i+2] << "\n";
            return false;
        } 
    }
    return true;
}

bool isNotDoubleChar(string str) {
    if(str.size() < 2) return true;

    for(int i=0; i<str.size()-1; i++) {
        if(str[i] == str[i+1] && str[i] != 'e' && str[i] != 'o') {
            return false;
        } 
    }
    return true;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string password;
    while(true) {
        cin >> password;
        if(password == "end") break;
        if(
            hasOneOrMoreConsonant(password) &&
            isNotTripleTypeChar(password) &&
            isNotDoubleChar(password)
        ) cout << "<" << password << "> is acceptable.\n";
        else cout << "<" << password << "> is not acceptable.\n";
    }

    return 0;
}