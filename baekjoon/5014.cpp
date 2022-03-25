#include <iostream>
#include <queue>

using namespace std;
int F, S, G, U, D;
bool visited[1000001];

bool safe(int y) {
    return (1<=y && y<=F); 
}

int bfs() {
    int cnt = 0;
    
    queue<int> q;
    q.push(S);
    visited[S] = true;
    
    while(!q.empty()) {
        int qs = q.size();
        for(int i=0; i<qs; i++) {
            int y = q.front();
            q.pop();
            if(y == G) return cnt;
            
            int ny = y + U;
            if(safe(ny) && !visited[ny]) {
                visited[ny] = true;
                q.push(ny);
            }
            ny = y - D;
            if(safe(ny) && !visited[ny]) {
                visited[ny] = true;
                q.push(ny);
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
    cin >> F >> S >> G >> U >> D;
    int ret = bfs();
    if(ret == -1) cout << "use the stairs";
    else cout << ret;
    return 0;
}
