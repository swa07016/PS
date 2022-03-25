#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
bool visited[10010];
vector<string> answer;
int cnt = 0; 

bool cmp(vector<string> a, vector<string> b) {
    if(a[0] == b[0]) {
        return a[1] < b[1];
    } return a[0] < b[0];
}

void dfs(string current, vector<string>& v, vector<vector<string>> tickets) {
    if(cnt >= 1) return ;
    if(v.size() == tickets.size() + 1) {
        cnt++;
        if(cnt==1)answer.assign(v.begin(), v.end());
    }
    
    for(int i=0; i<tickets.size(); i++) {
        if(tickets[i][0] == current && !visited[i]) {
            string next = tickets[i][1];
            visited[i] = true;
            v.push_back(next);
            dfs(next, v, tickets);
            visited[i] = false;
            v.pop_back();
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {

    sort(tickets.begin(), tickets.end(), cmp);
    
    vector<string> v;
    v.push_back("ICN");
    dfs("ICN", v, tickets);
    
    return answer;
}