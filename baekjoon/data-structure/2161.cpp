#include <iostream>
#include <queue>
#include <deque>

using namespace std;
int n;
queue<int> q;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);


    cin >> n;
    for(int i=0; i<n; i++) q.push(i+1);

    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
        q.push(q.front());
        q.pop();
    }

    return 0;
}