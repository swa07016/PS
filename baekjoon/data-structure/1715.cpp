#include <iostream>
#include <queue>

using namespace std;


/*
    10 20 40) 10 + 20 = 30
    30 40) 30 + 40 = 70
*/
priority_queue<int, vector<int>, greater<int> > pq;
int n;
int ans;
int tmp;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    for(int i=0; i<n; i++) {
        
        cin >> tmp;
        pq.push(tmp);
    }

    while(!pq.empty()) {
        if(pq.size() == 1) break;
        
        int first = pq.top(); pq.pop();
        int second = pq.top(); pq.pop();

        ans += (first + second);
        pq.push(first + second);
    }

    cout << ans;

    return 0;
}