#include <iostream>

using namespace std;

int n, m;
int flag, input;
int parent[210];
int plan[1010];

int find(int x) {
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void Union(int x, int y) {
    int px = find(x);
    int py = find(y);

    if(px == py) return ;
    parent[py] = px;
}


bool isUnion(int x, int y) {
    return find(x) == find(y);
}


int main() {


    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;

    for(int i=1; i<=n; i++) parent[i] = i;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> flag;
            if(flag) Union(i, j);
        }
    }

    for(int i=1; i<=m; i++) {
        cin >> input;
        plan[i] = input;
    }

    for(int i=1; i<=m-1; i++) {
        if(!isUnion(plan[i], plan[i+1])) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";


    return 0;
}