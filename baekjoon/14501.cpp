#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
vector<int> T, P;
bool visited[17];
int max_v = -1;

void dfs(int sum, int curr) {
    if(curr && curr + T[curr] - 1 == n) {
        max_v = max(max_v, sum);
        return ;
    }
    if(curr && curr + T[curr] - 1 > n) {
        max_v = max(max_v, sum-P[curr]);
        return ;
    }
    int start = curr ? curr + T[curr] : 1;
    for(int i=start; i<=n; i++) {
        if(!visited[i]) {
            visited[i] = true;
            dfs(sum+P[i], i);
            visited[i] = false;
        }
    } 
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n;
    T.resize(n+1);
    P.resize(n+1);
    for(int i=1; i<=n; i++) {
        cin >> T[i] >> P[i];
    }
    dfs(0, 0);
    cout << max_v;
    return 0;
}