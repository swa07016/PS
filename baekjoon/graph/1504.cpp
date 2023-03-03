#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#include <climits>

using namespace std;
int N, E;
int v1, v2;
vector<vector<pair<int, int> > > graph;

int dijkstra(int start, int finish) {
    int dist[810];
    for(int i=1; i<=N; i++) dist[i] = INT_MAX;

    // <currDist, currNode>
    priority_queue<
        pair<int, int>,
        vector<pair<int, int> >,
        greater<pair<int, int> >
    > q;

    dist[start] = 0;
    q.push(make_pair(0, start));

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

    return dist[finish];
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N >> E;
    graph.resize(N+1);
    for(int i=0; i<E; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        graph[from].push_back(make_pair(to, cost));
        graph[to].push_back(make_pair(from, cost));
    }
    cin >> v1 >> v2;


    if(dijkstra(1, v1) == INT_MAX || dijkstra(v2, N) == INT_MAX ||
    dijkstra(1, v2) == INT_MAX || dijkstra(v1, N) == INT_MAX) cout << "-1";

    else cout << min(
        dijkstra(1, v1) + dijkstra(v1, v2) + dijkstra(v2, N),
        dijkstra(1, v2) + dijkstra(v2, v1) + dijkstra(v1, N)
    );

    return 0;
}