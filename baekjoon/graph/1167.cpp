#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

class Vertex {
public:
    int number;
    int dist;
    Vertex(int number, int dist) : number(number), dist(dist) {}
};

class Node {
public:
    int number;
    int distSum;
    Node(int number, int distSum) : number(number), distSum(distSum) {}
};

int n; // 정점의 개수
vector<vector<Vertex> > graph;
int start, number, dist;

// 해당 정점, 최대 거리
pair<int, int> getMaxDistance(int start) { // start : 출발 정점
    bool visited[100010] = { false };
    queue<Node> q;
    Node ans = Node(start, 0);

    q.push(Node(start, 0));
    visited[start] = true;

    while(!q.empty()) {
        Node node = q.front(); q.pop();
        int number = node.number;
        int distSum = node.distSum;

        if(distSum > ans.distSum) {
            ans.distSum = distSum;
            ans.number = number;
        }

        for(int i=0; i<graph[number].size(); i++) {
            Vertex v = graph[number][i];
            if(!visited[v.number]) {
                q.push(Node(v.number, distSum + v.dist));
                visited[v.number] = true;
            }
        }
    }

    return make_pair(ans.number, ans.distSum);
}

int solve() {
    int firstDist, secondStart, secondDist;
    pair<int, int> firstRet = getMaxDistance(1);
    firstDist = firstRet.second;
    secondStart = firstRet.first;
    pair<int, int> secondRet = getMaxDistance(secondStart);
    secondDist = secondRet.second;
    return firstDist > secondDist ? firstDist : secondDist;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    graph.resize(n+1);
    for(int i=1; i<=n; i++) {
        cin >> start;
        while(true) {
            cin >> number;
            if(number == -1) break;
            cin >> dist;

            graph[start].push_back(Vertex(number, dist));
        }
    }

    cout << solve();

    return 0;
}