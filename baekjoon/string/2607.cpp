#include <iostream>
#include <string>
#include <map>

using namespace std;

bool isSimilar(string keyword, string testword) {
    map<char, int> keywordMap;   // keyword의 각 알파벳의 빈도를 저장하는 맵
    map<char, int> testwordMap;  // testword의 각 알파벳의 빈도를 저장하는 맵

    // keyword의 각 알파벳의 빈도를 계산
    for(char alpha : keyword) {
        keywordMap[alpha]++;
    }

    // testword의 각 알파벳의 빈도를 계산
    for(char alpha : testword) {
        testwordMap[alpha]++;
    }

    int totalDiff = 0; // 두 단어 사이의 전체 문자 빈도 차이

    // keyword의 각 문자에 대해 testword와의 빈도 차이를 계산
    for(auto keywordPair : keywordMap) {
        char requiredAlpha = keywordPair.first;
        int requiredCount = keywordPair.second;
        
        totalDiff += abs(requiredCount - testwordMap[requiredAlpha]);
    }

    // testword의 각 문자에 대해 keyword에 없는 문자의 빈도를 totalDiff에 추가
    for(auto testwordPair : testwordMap) {
        char alpha = testwordPair.first;

        if(keywordMap[alpha] == 0) {
            totalDiff += testwordPair.second;
        }
    }

    // 두 단어 사이의 길이 차이를 계산
    int lengthDiff = abs((int)keyword.size() - (int)testword.size());

    // 길이 차이가 1보다 크면 두 단어는 비슷한 단어가 아님
    if(lengthDiff > 1) return false;

    // totalDiff가 2 이하면 두 단어는 비슷한 단어
    return totalDiff <= 2;
}


int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    int ans = 0;
    string keyword;

    cin >> n;
    cin >> keyword;

    for(int i=0; i<n-1; i++) {
        string testword;
        cin >> testword;
        if(isSimilar(keyword, testword)) ans++;
    }

    cout << ans;

    return 0;
}   