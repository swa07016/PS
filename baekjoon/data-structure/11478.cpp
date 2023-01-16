#include <iostream>
#include <set>
#include <string>

using namespace std;
string input;
set<string> strSet;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> input;
    for(int i=0; i<input.size(); i++) {
        for(int j=1; j<=input.size()-i; j++) {
            string subStr = input.substr(i, j);
            if(strSet.find(subStr) == strSet.end()) strSet.insert(subStr);
        }
    }
    cout << strSet.size();
    return 0;
}