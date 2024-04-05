#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;

string s, t;
queue<string> q;
set<string> visited;

/*
    반대로 생각하기
    
    T에서 S로 갈 수 있는가?
    이렇게 하면 A, B가 있는 경우에만 추가하니까
    연산에서 탐색이 많이 줄어들 듯

    1. 문자열의 뒤에 A를 제거한다. (맨뒤가 A이면)
    2. 앞의 B를 빼고 문자열을 뒤집는다.
*/
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> s >> t;

    q.push(t);
    // a.visited(t);

    while(!q.empty()) {
        string curr = q.front(); q.pop();

        if(curr == s) {
            cout << "1";
            return 0;
        }        

        if(curr[curr.size()-1] == 'A') {
            string case1 = curr.substr(0, curr.size() - 1);
            q.push(case1);
        }

        if(curr[0] == 'B') {
            string case2 = curr.substr(1);
            reverse(case2.begin(), case2.end());
            q.push(case2);
        }
    }
    
    cout << "0";

    return 0;
}