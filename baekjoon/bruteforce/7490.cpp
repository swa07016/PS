#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int T, n;
char opers[3] = { ' ', '+', '-' };
vector<string> answers;

string makeExpression(vector<int> numbers, vector<char>& operators) {
    string ret = to_string(numbers[0]);
    for(int i=1; i<n; i++) {
        ret += operators[i-1];
        ret += to_string(numbers[i]);
    }

    return ret;
}

int eval(string expression) {
    int ret = 0;
    string num = "";
    char oper = '+';
    for(int i=0; i<expression.size(); i++) {
        if(expression[i] == ' ') continue;
        if(expression[i] == '+') {
            if(oper == '+') ret += atoi(num.c_str());
            else ret -= atoi(num.c_str());
            oper = '+';
            num = "";
        }
        if(expression[i] == '-') {
            if(oper == '+') ret += atoi(num.c_str());
            else ret -= atoi(num.c_str());
            oper = '-';
            num = "";
        }
        else {
            num += expression[i];
        }
    }

    if(oper == '+') ret += atoi(num.c_str());
    else ret -= atoi(num.c_str());
    
    return ret;
}

void dfs(vector<int> numbers, vector<char>& operators) {
    // 종료조건
    if(operators.size() == n-1) {
        string expression = makeExpression(numbers, operators);
        // cout << expression << "\n";
        if(eval(expression) == 0) cout << expression << "\n";
        return;
    }
    

    // DFS
    for(int i=0; i<3; i++) {
        char o = opers[i];

        operators.push_back(o);
        dfs(numbers, operators);
        operators.pop_back();
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> T;
    for(int i=0; i<T; i++) {
        cin >> n;
        vector<int> numbers;
        for(int j=0; j<n; j++) numbers.push_back(j+1);
        vector<char> operators;
        dfs(numbers, operators);
        cout << "\n";
    }

    return 0;
}