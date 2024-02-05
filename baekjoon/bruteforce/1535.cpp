#include <iostream>

using namespace std;
int n;
int loseHp[25];
int happy[25];
int ans = -1;

void dfs(int hp, int depth, int happySum) {

    if(depth == n + 1) {
        ans = max(ans, happySum);        
        return ;
    }
    
    if(hp > loseHp[depth+1]) {
        dfs(hp-loseHp[depth+1], depth+1, happySum + happy[depth+1]);
    }

    dfs(hp, depth+1, happySum);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i=1; i<=n; i++) cin >> loseHp[i];
    for(int i=1; i<=n; i++) cin >> happy[i];

    dfs(100, 0, 0);
    
    cout << ans;
    return 0;
}