#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
string expression;
string number;
int answer;

bool isNegative = false;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> expression;
  
    number += expression[0];
    for(int i=1; i<expression.size(); i++) {

        if(expression[i] == '+') {
            
            if(isNegative) {
                answer -= atoi(number.c_str());
            } else {
                answer += atoi(number.c_str());
            }

            number = "";
        }
        if(expression[i] == '-') {
            
            if(isNegative) {
                answer -= atoi(number.c_str());
            } else {
                answer += atoi(number.c_str());
            }

            number = "";
            isNegative = true;
        }
        else {
            number += expression[i];
        }
    }

    if(isNegative) {
        answer -= atoi(number.c_str());
    } else {
        answer += atoi(number.c_str());
    }

    cout << answer;

    return 0;
}