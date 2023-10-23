#include <iostream>
#include <string>
#include <map>

using namespace std;

bool isSimilar(string keyword, string testword) {
    map<char, int> keywordMap;
    map<char, int> testwordMap;

    for(char alpha : keyword) {
        keywordMap[alpha]++;
    }

    for(char alpha : testword) {
        testwordMap[alpha]++;
    }

    int totalDiff = 0;

    for(auto keywordPair : keywordMap) {
        char requiredAlpha = keywordPair.first;
        int requiredCount = keywordPair.second;
        
        totalDiff += abs(requiredCount - testwordMap[requiredAlpha]);
    }

    for(auto testwordPair : testwordMap) {
        char alpha = testwordPair.first;

        if(keywordMap[alpha] == 0) {
            totalDiff += testwordPair.second;
        }
    }

    int lengthDiff = abs((int)keyword.size() - (int)testword.size());

    if(lengthDiff > 1) return false;

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