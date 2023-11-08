#include <iostream>
#include <queue>

using namespace std;
priority_queue<int> pq;
int n, input;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> input;
            pq.push(input);
        }
    }

    for(int i=0; i<n-1; i++) {
        pq.pop();
    }

    cout << pq.top();

    return 0;
}
