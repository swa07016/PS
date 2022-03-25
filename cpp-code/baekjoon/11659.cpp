#include <iostream>

using namespace std;
int num[100001];
int sum[100001];
int n, m;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i=1; i<=n; i++) cin >> num[i];
    int s = num[1];
    sum[1] = s;
    for(int i=2; i<=n; i++) {
        s += num[i];
        sum[i] = s;
    }
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        cout << sum[b] - sum[a-1] << "\n";
    }
    return 0;
}
