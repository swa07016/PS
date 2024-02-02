#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main() {
    int n;
    string pattern, target;

    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    cin >> pattern;

    // 별표(*)를 [a-z]*로 변환하고, 정규 표현식의 시작과 끝을 명시합니다.
    string modifiedPattern = "^" + regex_replace(pattern, regex("\\*"), "[a-z]*") + "$";
    regex reg(modifiedPattern);

    for(int i = 0; i < n; i++) {
        cin >> target;
        if(regex_match(target, reg)) cout << "DA\n";
        else cout << "NE\n";
    }

    return 0;
}
