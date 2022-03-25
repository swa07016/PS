#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;
int cnt[510];
double failureRate[510];
vector<pair<int, double>> temp;

bool cmp(pair<int, double> a, pair<int, double> b) {
    if(a.second == b.second) return a.first < b.first;
    else return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer; 
    int userCount = stages.size();
    
    for(int i=0; i<stages.size(); i++) {
        cnt[stages[i]]++;
    }
    for(int i=1; i<=N; i++) {
        if(userCount == 0) failureRate[i] = 0;
        else {
            failureRate[i] = (double)cnt[i]/userCount;    
            userCount -= cnt[i];
        }
    } 
    for(int i=1; i<=N; i++) {
        temp.push_back({i, failureRate[i]});
    }
    sort(temp.begin(), temp.end(), cmp);
    
    for(int i=0; i<temp.size(); i++) answer.push_back(temp[i].first);
    return answer;
}