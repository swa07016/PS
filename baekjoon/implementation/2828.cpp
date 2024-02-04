#include <iostream>
#include <queue>

using namespace std;
int n, m, apple;
int dist;
queue<int> q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    cin >> apple;
    
    for(int i=0; i<apple; i++) {
        int tmp;
        cin >> tmp;
        q.push(tmp);
    }
    int start = 1, end = m;

    while(!q.empty()) {
        int target = q.front(); q.pop();
        if(target > end) {
            int diff = target - end;
            dist += diff;
            end += diff;
            start += diff;
        }
        if(target < start) {
            int diff = start - target;
            dist += diff;
            end -= diff;
            start -= diff;
        }
    }

    cout << dist;
    return 0;
}