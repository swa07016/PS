#include <iostream>
#include <queue>
#include <utility>

using namespace std;
int n, m;
int ladder[101];
int snake[101];
bool visited[101];

bool safe(int x) {
    return 1<=x && x<=100;
}

int bfs() {
    queue<int> q;
    q.push(1);
    visited[1] = true;
    
    int cnt = 0;
    while(!q.empty()) {
        int qs = q.size();
        for(int i=0; i<qs; i++) {
            int x = q.front();
            q.pop();
            
            if(x == 100) {
                return cnt;
            }
            
            for(int j=1; j<=6; j++) {
                int nx = x + j;
                if(safe(nx) && !visited[nx]) {
                    if(ladder[nx]) q.push(ladder[nx]);
                    else if(snake[nx]) q.push(snake[nx]);
                    else q.push(nx);
                    visited[nx] = true;
                }
            }
        }
        cnt++;
    }
    return -1;
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        ladder[a] = b;
    }
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        snake[a] = b;
    }
    cout << bfs();
    return 0;
}
