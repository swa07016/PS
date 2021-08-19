#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;
vector<string> answer;

// 동일한 문자들을 갖는 문자열이 map안에 있는지 검사
pair<string, bool> validate(map<string, int>& comb, string v) {
    for(auto iter = comb.begin(); iter != comb.end(); iter++) {
        string key = iter->first;
        int cnt = 0;
        for(int i=0; i<v.size(); i++) {
            string pivot = "";
            pivot += v[i];
            if(key.find(pivot) != string::npos) cnt++;
        }
        if(cnt == v.size()) return { key , true };
    }
    return {"", false};
}

void dfs(map<string, int>& comb, string order, int len, string& v, int curr) {
    if(v.size() == len) {
        pair<string, bool> check = validate(comb, v);
        if(comb.find(v) != comb.end()) { // 이미 존재하면
            auto iter = comb.find(v);
            iter->second++;
        } else if(check.second) {
            auto iter = comb.find(check.first);
            iter->second++;
        } else {
            comb.insert({v, 1});
        }
        return;
    }
    for(int i=curr+1; i<order.size(); i++) {
        v += order[i];
        dfs(comb, order, len, v, i);
        v = v.substr(0, v.size()-1);
    }
} 

vector<string> solution(vector<string> orders, vector<int> course) {
    
    // 1. 원하는 길이의 문자열을 orders에서 만들고 해당 문자열들을 카운트 
    // 2. 카운트 최댓값을 찾아서 map에서 해당 카운트를 가지고 있는 문자열들을 answer에 추가
    // 3. 원하는 길이대로 반복
    for(int i=0; i<course.size(); i++) {
        int len = course[i];
        map<string, int> comb;
        for(int j=0; j<orders.size(); j++) {
            string parsedOrder = orders[j];
            for(int k=0; k<parsedOrder.size(); k++) {
                string v = "";
                v += parsedOrder[k];
                dfs(comb, parsedOrder, len, v, k);       
            }
        }
        int max_cnt = -1;
        for(auto iter = comb.begin(); iter!=comb.end(); iter++) max_cnt = max(max_cnt, iter->second);
        for(auto iter = comb.begin(); iter!=comb.end(); iter++) if(max_cnt>=2 && iter->second == max_cnt) answer.push_back(iter->first);
    }
    for(int i=0; i<answer.size(); i++) sort(answer[i].begin(), answer[i].end());
    sort(answer.begin(), answer.end());
    return answer;
}