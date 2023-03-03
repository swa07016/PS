#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <climits>

using namespace std;
int n, m;
int start, finish;
int dist[1010];
int prevNode[1010];
vector<int> path;
vector<vector<pair<int, int> > > graph; // graph[from] <to, cost>;

void dijkstra() {
    // <currDist, currNode>
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
    dist[start] = 0;
    q.push(make_pair(0, start));
    prevNode[start] = -1;

    while(!q.empty()) {
        int currDist = q.top().first;
        int currNode = q.top().second;
        q.pop();

        if(currDist > dist[currNode]) continue;

        for(int i=0; i<graph[currNode].size(); i++) {
            int nextNode = graph[currNode][i].first;
            int cost = graph[currNode][i].second;

            int newDist = dist[currNode] + cost;
            if(dist[nextNode] > newDist) {
                dist[nextNode] = newDist;
                prevNode[nextNode] = currNode;
                q.push(make_pair(newDist, nextNode));
            }
        }
    }
    
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    graph.resize(n+1);

    for(int i=1; i<=n; i++) dist[i] = INT_MAX;

    for(int i=0; i<m; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        graph[from].push_back(make_pair(to, cost));
    }
    cin >> start >> finish;
    
    dijkstra();

    cout << dist[finish] << "\n";


    int idx = finish;
    path.push_back(finish);
    while(1) {
        if(prevNode[idx] == start) {
            path.push_back(start);
            break;
        }
        path.push_back(prevNode[idx]);
        idx = prevNode[idx];
    }

    cout << path.size() << "\n";
    for(int i = path.size()-1; i>=0; i--) cout << path[i] << " ";

    return 0;
}