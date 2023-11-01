#include <iostream>
#include <set>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
int n;
// 사람, 명령(enter, leave)
string person, command;
set<string> company;
vector<string> answer;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;

    for(int i=0; i<n; i++) {
        cin >> person >> command;

        if(command == "enter") {
            company.insert(person);
        } else {
            auto iter = company.find(person);
            company.erase(iter);
        }
    }

    for(auto iter = company.begin(); iter != company.end(); iter++) {
        answer.push_back(*iter);
    }

    for(int i=answer.size()-1; i>=0; i--) {
        cout << answer[i] << "\n";
    }

    return 0;
}