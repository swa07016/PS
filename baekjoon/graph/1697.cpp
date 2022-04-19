#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;
int n, k;
bool visited[200010];

bool safe(int x) {
    return 0 <= x && x <= 200000;    
}

int bfs() {
    queue<int> q;
    q.push(n); visited[n] = true;
    int cnt = 0;
    
    while(!q.empty()) {
         int qs = q.size();
         for(int i=0; i<qs; i++) {
             int x = q.front(); q.pop();
             if(x == k) return cnt;
             if(safe(x-1) && !visited[x-1]) {
                 q.push(x-1);
                 visited[x-1] = true;    
             }
             if(safe(x+1) && !visited[x+1]) {
                 q.push(x+1);
                 visited[x+1] = true;
             }
             if(safe(x*2) && !visited[x*2]) {
                 q.push(x*2);           
                 visited[x*2];
             }
          }
          cnt++;
     }
            
}


int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    cin >> n >> k;
    
    cout << bfs();
    return 0;
}
