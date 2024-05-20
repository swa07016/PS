#include <iostream>

using namespace std;

int parent[1000010];
int n, m;
int a, b;
int command;

int find(int x) {
    if(x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

void Union(int x, int y) {
    int px = find(x);
    int py = find(y);

    // 이미 연결되어 있는 경우
    if(px == py) return ;
    
    // 한쪽 루트의 부모를 다른쪽 루트로 세팅
    parent[px] = py;
}

bool isConnected(int x, int y) {
    return find(x) == find(y);
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;

    for(int i=1; i<=n; i++) parent[i] = i;

    for(int i=0; i<m; i++) {
        cin >> command >> a >> b;

        if(command == 0) {
            Union(a, b);
        } 

        if(command == 1) {
            if(isConnected(a, b)) cout << "YES\n";
            else cout << "NO\n";
        }
    }

    return 0;
}