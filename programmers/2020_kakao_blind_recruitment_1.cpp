#include <string>
#include <vector>
#include <iostream>

using namespace std;

int f(string s, int k) {
    string tmp = "";
    int i = 0, chk = 0;
    while(1) {
        string target = s.substr(i, k);
        int cnt = 0; 
        for (int j = i; j < s.size(); j += k) {
            if (s.substr(j, k) == target) { 
                cnt++; 
            }
            else {
                i = j;
                break;
            }
        }
        chk += (k * cnt);
        if (cnt == 1) tmp += target;
        else tmp += (to_string(cnt) + target);
        if (chk >= s.size()) break;
    }
    return tmp.size();
}

int solution(string s) {
    int answer = 1010;
    for (int i = 1; i <= s.size(); i++) {
        if (f(s, i) < answer) answer = f(s, i);
    }
    return answer;
}