#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int parent[1010], n, m, x, y, d, cnt, ans;
class Edge {
public:
	int x, y;
	int distance;
	Edge(int _x, int _y, int _distance) {
		this->x = _x;
		this->y = _y;
		this->distance = _distance;
	}
	bool operator<(Edge& e) {
		return this->distance < e.distance;
	}
};
vector <Edge> edge;

int getParent(int x) {
	if (x == parent[x]) return x;
	else return getParent(parent[x]);
}

void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

bool findParent(int a, int b) {
	if (getParent(a) == getParent(b)) return true;
	else return false;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) parent[i] = i;
	for (int i = 1; i <= m; i++) {
		cin >> x >> y >> d;
		edge.push_back(Edge(x, y, d));
	}
	sort(begin(edge), end(edge));
	for (int i = 0; i < edge.size(); i++) {
		if (cnt == n - 1) break;
		if (!findParent(edge[i].x, edge[i].y)) {
			ans += edge[i].distance;
			cnt++;
			unionParent(edge[i].x, edge[i].y);
		}
	}
	cout << ans;
	return 0;
}