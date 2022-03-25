#include <iostream>
#include <algorithm>

using namespace std;
int dist[52][52];
int n;
int result[52];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) dist[i][j] = 987654321;
    } 
    
    while(1) {
        int a, b;
        cin >> a >> b;
        if(a==-1 && b==-1) break;
        dist[a][b] = dist[b][a] = 1;
    }

    for(int i=1; i<=n; i++) dist[i][i] = 0;

    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    
    for(int i=1; i<=n; i++) {
        int tmp = -1;
        for(int j=1; j<=n; j++) if(i!=j) tmp = max(tmp, dist[i][j]);
        result[i] = tmp;
    }
    
    int key = 987654321;
    for(int i=1; i<=n; i++) key = min(key, result[i]);
    
    int count = 0;
    for(int i=1; i<=n; i++) if(key == result[i]) count++;
    
    cout << key << " " << count << "\n";
    for(int i=1; i<=n; i++) if(key == result[i]) cout << i << " ";
    
    return 0;
}
