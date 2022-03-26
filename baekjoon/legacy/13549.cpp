#include <iostream>
#include <queue>
#include <utility>

using namespace std;
int n, k;
int result;
bool visited[100001];

bool safe(int x) {
    return 0<=x && x<=100000;
}

void bfs() {
    // cnt, position
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push(make_pair(0, n));
    visited[n] = true;
    
    while(!q.empty()) {
        int cnt = q.top().first;
        int position = q.top().second;
        q.pop();
        
        if(position == k) {
            result = cnt;
            return ;
        }
        if(safe(position*2) && !visited[position*2]) {
            q.push(make_pair(cnt, position*2));
            visited[position*2] = true;
        }
        if(safe(position+1) && !visited[position+1]) { 
            q.push(make_pair(cnt+1, position+1));
            visited[position+1] = true;
        }
        if(safe(position-1) && !visited[position-1]) { 
            q.push(make_pair(cnt+1, position-1));
            visited[position-1] = true;
        }
        
    }
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n >> k;
    bfs();
    cout << result;
    return 0;
}
