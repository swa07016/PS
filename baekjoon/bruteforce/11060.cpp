#include <iostream>
#include <queue>
#include <utility>

using namespace std;
int n;
int ans = -1;
int maze[1010];
bool visited[1010];
queue<pair<int, int> > q; // index, dist

bool safe(int a) {
    return (1<=a && a<=n);
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    for(int i=1; i<=n; i++) cin >> maze[i];

    q.push(make_pair(1, 0));
    visited[1] = true;

    while(!q.empty()) {
        int x = q.front().first;
        int dist = q.front().second;
        q.pop();

        if(x == n) {
            ans = dist;
            break;
        }
        
        for(int i=1; i<=maze[x]; i++) {
            int nx = x + i;
            if(safe(nx) && !visited[nx]) {
                visited[nx] = true;
                q.push(make_pair(nx, dist+1));
            }
        }
        
    }

    cout << ans;
    return 0;
}