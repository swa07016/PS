#include <iostream>
#include <string>
#include <stack>

using namespace std;
int n;

void print(string& str) {
    stack<char> s;
    bool flag = false;
    for(int i=0; i<str.size(); i++) {
        if(str[i] == '<') {
            while(!s.empty()) {
                cout << s.top();
                s.pop();
            }
            cout << '<';
            flag = true;
            continue;
        }
        
        if(flag) {
            if(str[i] == '>') {
                cout << '>';
                flag = false;
            } else cout << str[i];
        } else {
            if(str[i] == ' ') {
                while(!s.empty()) {
                    cout << s.top();
                    s.pop();
                }
                cout << ' ';
            } else if(i == str.size()-1) {
                cout << str[i];
                while(!s.empty()) {
                    cout << s.top();
                    s.pop();
                }
            } else s.push(str[i]);
        }
    }
    
    return ;
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    string str;
    getline(cin, str);
    print(str);
    return 0;
}