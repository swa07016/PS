#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <climits>

using namespace std;
int V, E, start;
vector<vector<pair<int, int> > > graph;
int dist[20010];

void dijkstra() {
    // currDist, currNode
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;

    q.push(make_pair(0, start));
    dist[start] = 0;

    while(!q.empty()) {
        int currDist = q.top().first;
        int currNode = q.top().second;
        q.pop();

        if(dist[currNode] < currDist) continue;

        for(int i=0; i<graph[currNode].size(); i++) {
            int nextNode = graph[currNode][i].first;
            int cost = graph[currNode][i].second;
            
            int newDist = dist[currNode] + cost;
            if(dist[nextNode] > newDist) {
                dist[nextNode] = newDist;
                q.push(make_pair(newDist, nextNode));
            }
        }
    }

}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> V >> E;
    cin >> start;

    for(int i=1; i<=V; i++) dist[i] = INT_MAX;
    graph.resize(V+1);

    for(int i=0; i<E; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        graph[from].push_back(make_pair(to, cost));
    }

    dijkstra();

    for(int i=1; i<=V; i++) {
        int d = dist[i];
        if(d == INT_MAX) cout << "INF\n";
        else cout << dist[i] << "\n";
    }

    return 0;
}