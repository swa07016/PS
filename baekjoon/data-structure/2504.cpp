#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);


string s;
    cin >> s;
    stack<int> st;
    int temp = 1;
    int result = 0;
    
    for(int i = 0; i < s.length(); ++i) {
        switch(s[i]) {
            case '(': // 여는 괄호는 곱셈을 위한 기반값 설정
                temp *= 2;
                st.push(s[i]);
                break;
            case '[':
                temp *= 3;
                st.push(s[i]);
                break;
            case ')': // 닫는 괄호는 계산 수행
                if(st.empty() || st.top() != '(') {
                    cout << "0\n";
                    return 0;
                }
                if(s[i-1] == '(') result += temp;
                st.pop();
                temp /= 2;
                break;
            case ']':
                if(st.empty() || st.top() != '[') {
                    cout << "0\n";
                    return 0;
                }
                if(s[i-1] == '[') result += temp;
                st.pop();
                temp /= 3;
                break;
        }
    }

    if(!st.empty()) { // 스택이 비어있지 않다면 올바르지 않은 괄호열
        cout << "0\n";
    } else {
        cout << result << "\n";
    }

    return 0;
}