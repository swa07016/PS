#include <iostream>
#include <stack>

using namespace std;

int d[1001];

int dp(int x) {
	if(x==1) return 1;
	if(x==2) return 2;
	if(d[x]) return d[x];
	return d[x] = (dp(x-1) + dp(x-2))%10007;
}

int main(void) {

	iostream::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	cout << dp(n);
	return 0;
}