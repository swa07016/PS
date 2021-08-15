#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int>> q;
    for(int i=0; i<scoville.size(); i++) q.push(scoville[i]);
    
    int cnt = 0;
    
    while(q.size() >= 2) {
        int first = q.top(); q.pop();
        if(first >= K) break;
        int second = q.top(); q.pop();
        int newFood = first + second*2;
        q.push(newFood);
        cnt++;
    } 
    if(q.top() >= K) return cnt;
    return -1;
}