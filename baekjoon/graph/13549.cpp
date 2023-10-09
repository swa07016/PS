#include <iostream>
#include <queue>
#include <climits>

using namespace std;
class Node {
public:
    int position;
    int sec;
    Node(int position, int sec) : position(position), sec(sec) {}
};

int n, k;
bool visited[100010];

bool safe(int x) {
    return 0 <= x && x <= 100000;
}

int solve() {
    queue<Node> q;
    q.push(Node(n, 0));
    visited[n] = true;
    int minSec = INT_MAX;

    while(!q.empty()) {
        Node node = q.front(); q.pop();
        int position = node.position;
        int sec = node.sec;

        if(position == k && sec < minSec) {
            minSec = sec;
        }

        if(safe(position+1) && !visited[position+1]) {
            q.push(Node(position+1, sec+1));
            visited[position+1] = true;
        }

        if(safe(position-1) && !visited[position-1]) {
            q.push(Node(position-1, sec+1));
            visited[position-1] = true;
        }

        if(safe(position*2) && !visited[position*2]) {
            q.push(Node(position*2, sec));
            visited[position*2] = true;
        }
    }    
    return minSec;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> k;
    cout << solve();

    return 0;
}