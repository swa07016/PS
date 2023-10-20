#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int V, E;
bool visited[10010];
int ans;
int parent[10010];
int edgeCount;

class Edge {
public:
    int a;
    int b;
    int weight;
    Edge(int a, int b, int w) {
        this->a = a;
        this->b = b;
        this->weight = w;
    }
};

vector<Edge> edges;

bool compare(Edge& a, Edge& b) {
    return a.weight < b.weight;
}

int find(int x) {
    if(x == parent[x]) return x;
    else return parent[x] = find(parent[x]);
}

void Union(int x, int y) {

    int px = find(x);
    int py = find(y);

    if(px != py) {
        parent[px] = py;
    }

}

// 1197
/*
    1. 가중치를 기준으로 정렬한다.
    2. 사이클이 생기지 않는 경우에 합친다. (사이클의 판정은 unino-find)
    3. 합쳐진 간선의 개수가 정점의 개수 - 1인경우 종료한다.
*/
int main() {

    cin >> V >> E;

    for(int i=1; i<=10000; i++) parent[i] = i;

    for(int i=0; i<E; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        
        edges.push_back(Edge(a, b, w));
    }

    sort(edges.begin(), edges.end(), compare);

    for(int i=0; i<edges.size(); i++) {
        int x = edges[i].a;
        int y = edges[i].b;
        int w = edges[i].weight;
        if(find(x) != find(y)) {
            Union(x, y);
            ans += w;
            edgeCount++;
            if(edgeCount == V-1) break;
        }
    }

    cout << ans;
    return 0;
}