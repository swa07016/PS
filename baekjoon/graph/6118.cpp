#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int n, m, a, b;
vector<vector<int> > node;
// 1과의 거리
int dist[20010];
bool visited[20010];
int answerNode;
int maxDist = -1;
int answerCount;

void solve() {
    // 노드번호, 거리
    queue<pair<int, int> > q;
    
    q.push(make_pair(1, 0));
    visited[1] = true;

    while(!q.empty()) {
        int vertex = q.front().first;
        int distance = q.front().second;
        dist[vertex] = distance;
        q.pop();

        maxDist = max(maxDist, distance);

        for(int i=0; i<node[vertex].size(); i++) {
            int next = node[vertex][i];
            if(!visited[next]) {
                q.push(make_pair(next, distance+1));
                visited[next] = true;
            }
        }
    }

    for(int i=n; i>=0; i--) {
        if(maxDist == dist[i]) {
            answerNode = i;
            answerCount++;
        }
    }
}

// 6118
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    node.resize(n+1);

    for(int i=0; i<m; i++) {
        cin >> a >> b;
        node[a].push_back(b);
        node[b].push_back(a);
    }

    solve();

    cout << answerNode << " " << maxDist << " " << answerCount;

    return 0;
}