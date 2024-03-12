#include <iostream>
#include <queue>

using namespace std;

/*
    30, 30, 40, 50 ) (30 + 30) = 60
    40 50 60 ) (40 + 50) = 90
    60 90 ) (60 + 90) = 150
    
    60 + 90 + 150 = 300

*/
int t;
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> t;
    for(int i=0; i<t; i++) {
        int k;
        long long ans = 0;
        priority_queue<long long int, vector<long long int>, greater<long long int> > pq;
        cin >> k;
        for(int j=0; j<k; j++) {
            long long int tmp;
            cin >> tmp;
            pq.push(tmp);
        }

        while(!pq.empty()) {

            long long first = pq.top(); pq.pop();
            long long second = pq.top(); pq.pop();

            pq.push(first + second);
            ans += (first + second);

            if(pq.size() == 1) break;
        }
        cout << ans << "\n";
    }

    return 0;
}