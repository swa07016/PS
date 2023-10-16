#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
string expression;
string number;
int answer;

bool isNegative = false;

// 1541
/*
    첫 번째 '-' 연산자가 나타날 때까지는 모든 숫자들을 더하고, 
    첫 번째 '-' 연산자가 나타난 이후의 모든 숫자들은 빼주면 된다.
*/
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