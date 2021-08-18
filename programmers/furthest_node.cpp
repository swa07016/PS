#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
bool visited[20010];
int depth[20010];
vector<vector<int>> vertex;
int cnt = 0, key;

void bfs() {
    queue<pair<int, int>> q;
    q.push({1, 0});
    visited[1] = true;
    
    while(!q.empty()) {
        int curr = q.front().first;
        int dep = q.front().second;
        key = dep;
        depth[dep]++;
        q.pop();
        for(int i=0; i<vertex[curr].size(); i++) {
            int next = vertex[curr][i];
            if(!visited[next]) {
                visited[next] = true;
                q.push({next, dep+1});
                
            }
        }
    }
    return ;
}

int solution(int n, vector<vector<int>> edge) {
    vertex.resize(n+1);
    for(int i=0; i<edge.size(); i++) {
        int a = edge[i][0], b = edge[i][1];
        vertex[a].push_back(b);
        vertex[b].push_back(a);
    }
    bfs();
    return depth[key];
}
