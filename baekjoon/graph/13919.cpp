#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int n, k;
bool visited[100001];
// 역추적할 때 사용하는 배열
int parent[100001];
int result = -1;
vector<int> v;

bool safe(int x) {
    return 0<=x && x<=100000;
}

void bfs() {
    queue<int> q;
    q.push(n);
    visited[n] = true;
    int cnt = 0;
    
    while(!q.empty()) {
        int qs = q.size();
        for(int i=0; i<qs; i++) {
            int x = q.front();
            q.pop();
            
            if(x == k) {
                cout << cnt << "\n";
                result = cnt;
                int curr = x;
                while(1) {
                    v.push_back(curr);
                    if(curr == n) break;
                    curr = parent[curr];    
                }
                for(int i=cnt; i>=0; i--) cout << v[i] << " ";
                return ;
            }
            if(safe(x*2) && !visited[x*2]) {
                parent[x*2] = x;
                q.push(x*2);
                visited[x*2] = true;
            } 
            if(safe(x+1) && !visited[x+1]) {                
                parent[x+1] = x;
                q.push(x+1);
                visited[x+1] = true;
            }
            if(safe(x-1) && !visited[x-1]) {
                parent[x-1] = x;
                q.push(x-1);
                visited[x-1] = true;
            }
        }
        cnt++;
    }
    return ;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    bfs();
    return 0;
}
