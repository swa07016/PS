#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
string str;
vector<string> nums;

bool isNumber(char c) {
    return '0' <= c && c <= '9';
}

/*
    예를 들어 2가 10 보다 사전순으로 뒤에 오게 되므로
    자리수를 비교하는 정렬 함수를 추가
*/
bool compareNumbers(string a, string b) {
    if(a.size() == b.size()) return a < b;
    return a.size() < b.size();
}

string removeForwardZero(string s) {
    if(s.size() < 2) return s;
    string num = "";
    int start = -1;
    for(int i=0; i<s.size(); i++) {
        if(s[i] != '0') {
            start = i;
            break;
        }
    }
    if(start == -1) return "0"; 
    return s.substr(start);
}

void findNumbers(string phrase) {
    bool isSearching = false;
    string num = "";
    for(int i=0; i<phrase.size(); i++) {

        if(isSearching) {
            if(isNumber(phrase[i])) num += phrase[i];
            else {
                nums.push_back(removeForwardZero(num));
                num = "";
                isSearching = false;
            }
        }

        if(!isSearching) {
            if(isNumber(phrase[i])) {
                isSearching = true;
                num += phrase[i];
            }
        }

    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> str;
        findNumbers("x" + str + "x");
    }

    sort(nums.begin(), nums.end(), compareNumbers);
    for(int i=0; i<nums.size(); i++) cout << nums[i] << "\n";

    return 0;
}