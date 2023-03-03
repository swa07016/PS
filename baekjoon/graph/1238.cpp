/*
    n개의 마을 (각각 한명학생이 살고 있음)
    m개의 단방향 도로
    X번 마을에 모여서 파티할 거임.

    특정 마을 -> X번 + X번 -> 특정마을 의 합이 가장 큰 마을을 출력
*/
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <climits>

using namespace std;
int n, m, target;
vector<vector<pair<int, int> > > graph;
int ans = -1;

int dijkstra(int start, int finish) {
    int dist[1010];
    for(int i=1; i<=n; i++) dist[i] = INT_MAX;
    dist[start] = 0;

    // <currDist, currNode>
    priority_queue<
        pair<int, int>,
        vector<pair<int, int> >,
        greater<pair<int, int> >
    > q;

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

    cin >> n >> m >> target;
    graph.resize(n+1);

    for(int i=0; i<m; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        graph[from].push_back(make_pair(to, cost));
    }

    for(int i=1; i<=n; i++) {
        ans = max(ans, dijkstra(i, target) + dijkstra(target, i));
    }

    cout << ans;
    return 0;
}