#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m;
int dist[110][110];
int ans;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) if(i!=j) dist[i][j] = 987654321;
    }
    
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        dist[a][b] = dist[b][a] = 1;
    }
    
    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    } 
    
    int pivot = 987654321;
    for(int i=n; i>=1; i--) {
        int sum = 0;
        for(int j=1; j<=n; j++) sum += dist[i][j];
        if(pivot >= sum) {
            pivot = sum;
            ans = i;
        }
    }

    cout << ans;
    return 0;
}
