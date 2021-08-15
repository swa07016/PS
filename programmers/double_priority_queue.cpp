#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;
string cmd;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    priority_queue<int> max_heap;
    int cnt = 0;
    
    for(int i=0; i<operations.size(); i++) {
        cmd = operations[i];
        if(cmd[0] == 'I') {
            int value = atoi(cmd.substr(2).c_str());
            max_heap.push(value);
            min_heap.push(value);
            cnt++;
        } else if(cmd[0] == 'D') {
            int value = atoi(cmd.substr(2).c_str());
            if(cnt==0) continue;
            if(value == 1) {
                max_heap.pop();
                cnt--;
            } else if(value == -1) {
                min_heap.pop();
                cnt--;
            }
        }
    }
    if(cnt == 0) {
        answer.push_back(0); answer.push_back(0);
        return answer;
    } else {
        while(!max_heap.empty()) {
            answer.push_back(max_heap.top());
            max_heap.pop();
        }
        while(!min_heap.empty()) {
            answer.push_back(min_heap.top());
            min_heap.pop();
        }
        sort(answer.begin(), answer.end());
        vector<int> tmp;
        for(int i=0; i<answer.size(); i++) {
            if(answer[i] == answer[i+1]) {
                tmp.push_back(answer[i]);
                i++; 
            }
        }
        vector<int> result;
        result.push_back(tmp[tmp.size()-1]); result.push_back(tmp[0]);
        return result;
    }
}