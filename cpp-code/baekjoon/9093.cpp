#include <iostream>
#include <string>
#include <stack>

using namespace std;
int n;

void print(string& str) {
    stack<char> s;
    for(int i=0; i<str.size(); i++) {
        if(str[i] == ' ') {
            while(!s.empty()) {
                cout << s.top();
                s.pop();
            }
            cout << " ";
        } else if(i == str.size() - 1) {
            cout << str[i];
            while(!s.empty()) {
                cout << s.top();
                s.pop();
            }
        } else s.push(str[i]);
    }
    cout << "\n";
    return ;
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i=0; i<n+1; i++) {
        string str;
        getline(cin, str);
        if(i==0) continue;
        print(str);    
    }
    return 0;
}
