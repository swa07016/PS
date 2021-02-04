#include <iostream>

using namespace std;

int p_sum[1025][1025];

int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M, num;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> num;
			p_sum[i + 1][j + 1] = p_sum[i][j + 1] + p_sum[i + 1][j] - p_sum[i][j] + num;
		}
	}

	for (int i = 0; i < M; i++) {
		int x1, y1, x2, y2;
		cin >> y1 >> x1 >> y2 >> x2;
		cout << p_sum[y2][x2] - p_sum[y1 - 1][x2] - p_sum[y2][x1 - 1] + p_sum[y1 - 1][x1 - 1] << '\n';
	}

	return 0;
}