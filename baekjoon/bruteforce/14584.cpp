#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector<string> dictionary;
int n; // 1 ~ 25
string encodedString, answer;
int correctKey;


// 원본 문자열에서 key 만큼 뒤로 옮긴 문자열을 리턴
string convert(string word, int key) {
    for(int i=0; i < word.size(); i++) {
        word[i] = word[i] - key;
        if(word[i] < 'a') {
            int diff = 'a' - word[i];
            word[i] = 'z' + 1 - diff;
        }
    }
    return word;
}

// 해당 단어가 변환에 필요한 단어인지 판별
bool isKeyString(string word) {
    for(int i=0; i <= encodedString.size() - word.size(); i++) {
        string subString = encodedString.substr(i, word.size());
        // cout << "subStr : " << subString << "\n";
        for(int j=0; j<=25; j++) {
            // cout << "converted : " << convert(subString, j) << "\n";
            if(convert(subString, j) == word) {
                correctKey = j;
                return true;
            }
        }
    }
    return false;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> encodedString;
    cin >> n;
    for(int i=0; i<n; i++) {
        string tmp;
        cin >> tmp;
        dictionary.push_back(tmp);
    }

    for(int i=0; i<n; i++) {
        if(dictionary[i].size() > encodedString.size()) continue;
        if(isKeyString(dictionary[i])) {
            answer = convert(encodedString, correctKey);
            break;
        }
    }

    cout << answer;
    return 0;
}