#include <iostream> 
#include <queue>
using namespace std;
int n, k, cnt = 0;
bool visited[100010];

bool safe(int a) {
	return (0<=a && a <= 100000);
}

void bfs() {
	queue <int> q;
	q.push(n);
	visited[n] = true;
	while (!q.empty()) {
		int qs = q.size();
		for (int i = 0; i < qs; i++) {
			int x = q.front();
			q.pop();
			if (x == k) {
				cout << cnt;
				return;
			}
			if (safe(x - 1) &&!visited[x - 1]) {
				q.push(x - 1);
				visited[x - 1] = true;
			}
			if ( safe(x + 1) && !visited[x + 1] ) {
				q.push(x + 1);
				visited[x + 1] = true;
			}
			if ( safe(x * 2) && !visited[x * 2] ) {
				q.push(x * 2);
				visited[x * 2] = true;
			}
		}
		cnt++;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;
	bfs();
	return 0;
}