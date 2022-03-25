#include <iostream>
#include <algorithm>
using namespace std;

int min(int a, int b) {
	if(a < b)return a;
	else return b;
}
int p[1010][3];
int main(void) {

	iostream::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> p[i][0] >> p[i][1] >> p[i][2];
	}
	for(int i=1; i<n; i++) {
		p[i][0] = min(p[i-1][1], p[i-1][2]) + p[i][0];
		p[i][1] = min(p[i-1][0], p[i-1][2]) + p[i][1];
		p[i][2] = min(p[i-1][0], p[i-1][1]) + p[i][2];
	}
	sort(p[n-1], p[n-1]+3);
	cout << p[n-1][0];
	return 0;
}