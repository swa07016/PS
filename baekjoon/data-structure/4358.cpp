#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

// 나무 종 이름, 개수
map<string, int> dict;
int total;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string str;
    while(getline(cin, str)) { // EOF면 종료
        total++;
        dict[str]++;
    }

    // 소수점 4자리까지 표시
    cout << fixed;
    cout.precision(4);

    for(auto iter : dict) {
        cout << iter.first << " " << ((double)iter.second / total) * 100 << "\n";
    }

    return 0;
}